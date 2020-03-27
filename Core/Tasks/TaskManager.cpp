//
// Created by Dana on 18.03.2020.
//

#include "TaskManager.h"
#include <algorithm>
#include <typeinfo>
#include <iostream>
#include <cassert>

TaskManager * TaskManager::globalTaskManager = TaskManager::getTaskManager();

TaskManager::TaskManager() {
    allTasks = {};
    allProjects = {};

    NOJECT = createProject("Unassigned");
}

TaskManager *TaskManager::getTaskManager() {
    if(globalTaskManager == nullptr)
        globalTaskManager = new TaskManager();
    return globalTaskManager;
}

ID TaskManager::createTask(std::string name, ID project) {

    ID id = idGeneratorTasks.getID();
    allTasks.insert({id, Task {std::move(name)}});
    assignProject(id, project);
    return id;
}

ID TaskManager::createTask(std::string name) {
    return createTask(name, NOJECT);
}

ID TaskManager::createProject(std::string name) {
    ID id = idGeneratorProjects.getID();
    allProjects.insert({id, Project {std::move(name)}});
    return id;
}

void TaskManager::transferTask(ID task, ID newProject) {
    auto& oldProjectID = allTasks.at(task).assignedProject;
    auto& oldList = allProjects.at(oldProjectID).assignedTasks;
    oldList.erase(std::remove(oldList.begin(), oldList.end(), task));
    assignProject(task, newProject);
}

void TaskManager::unassignTask(ID task) {
    transferTask(task, NOJECT);
}

void TaskManager::assignProject(ID task, ID project){
    allTasks.at(task).assignedProject = project;
    allProjects.at(project).assignedTasks.push_back(task);
}

Task& TaskManager::getTask(const ID& id) {
    return allTasks.at(id);
}

Project& TaskManager::getProject(const ID& id) {
    return allProjects.at(id);
}

Project& TaskManager::associatedProject(const ID& task) {
    return getProject(allTasks.at(task).assignedProject);
}

std::vector<Task *> TaskManager::associatedTasks(const ID& project) {
    std::vector<Task*> pointies;
    for(const ID& id : allProjects.at(project).assignedTasks) {
        pointies.push_back(&getTask(id));
    }
    return pointies;
}

//TODO: duplicated, container dependant code in TaskManager
void TaskManager::deleteTask(ID task) {
    auto& oldProjectID = allTasks.at(task).assignedProject;
    auto& oldList = allProjects.at(oldProjectID).assignedTasks;
    oldList.erase(std::remove(oldList.begin(), oldList.end(), task));
    allTasks.erase(task);
}

void TaskManager::deleteProject(ID project) {
    for(const auto& task : allProjects.at(project).assignedTasks) {
        if(allTasks.at(task).isProjectDependant())
            deleteTask(task);
        else
            unassignTask(task);
    }
    allProjects.erase(project);
}

void TaskManager::testPrint() const {
    std::cout << std::endl;
    std::cout << "TEST PRINT" << std::endl;
    std::cout << std::endl;

    for (const auto& [id, project] : this->allProjects) {
        std::cout << "Project: " << "ID: " << id << " Name: "<< project.getName() << std::endl;
        std::cout << "Assigned Tasks: " << std::endl;
        for(const auto& task : project.assignedTasks)
            std::cout << "ID: " << task << " Name: " << allTasks.at(task).getName() << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "TEST PRINT END" << std::endl;
    std::cout << std::endl;
}
