//
// Created by Dana on 18.03.2020.
//

#include "TaskManager.h"
#include <algorithm>
#include <iostream>
#include <memory>


//TaskManager * TaskManager::globalTaskManager = TaskManager::getTaskManager();

//idGenerators need to be initialized before creating first Project
TaskManager::TaskManager() : idGeneratorTasks(), idGeneratorProjects() {
    NOJECT = createProject("Unassigned");
}

//TaskManager *TaskManager::getTaskManager() {
//    if(globalTaskManager == nullptr)
//        globalTaskManager = new TaskManager();
//    return globalTaskManager;
//}

ID TaskManager::createTask(const std::string& name, ID project) {

    ID id = idGeneratorTasks.getID();
    allTasks[id] = std::move(std::make_unique<Task> (name));

    assignProject(id, project);

    return id;
}

ID TaskManager::createTask(const std::string& name) {
    return createTask(name, NOJECT);
}

ID TaskManager::createProject(const std::string& name) {
    ID id = idGeneratorProjects.getID();

    allProjects[id] = std::move(std::make_unique<Project> (name));

    tasksOfProject[id] = {};

    return id;
}

void TaskManager::transferTask(ID task, ID newProject) {
    ID oldProjectID = getAssignedProject(task);
    //auto& oldList = allProjects.at(oldProjectID)->assignedTasks;
    //oldList.erase(std::remove(oldList.begin(), oldList.end(), task));

    tasksOfProject[oldProjectID].erase(std::remove(tasksOfProject[oldProjectID].begin(),
            tasksOfProject[oldProjectID].end(), task));

    assignProject(task, newProject);

}

void TaskManager::unassignTask(ID task) {
    transferTask(task, NOJECT);
}

void TaskManager::assignProject(ID task, ID project){
    //allProjects.at(project)->assignedTasks.push_back(task);
    tasksOfProject[project].push_back(task);
    projectOfTask[task] = project;
}

Task& TaskManager::getTask(const ID& id) {
    return *allTasks.at(id);
}

Project& TaskManager::getProject(const ID& id) {
    return *allProjects.at(id);
}

Project& TaskManager::associatedProject(const ID& task) {
    return getProject(getAssignedProject(task));
}

std::vector<ID> TaskManager::getAssociatedTasks(const ID& project) const {
    return tasksOfProject.at(project);
}

ID TaskManager::getAssignedProject(const ID taskID) const {
    return projectOfTask.at(taskID);
}


//TODO: duplicated, container dependant code in TaskManager
void TaskManager::deleteTask(ID task) {
    ID oldProjectID = getAssignedProject(task);
    //auto& oldList = allProjects.at(oldProjectID)->assignedTasks;
    //oldList.erase(std::remove(oldList.begin(), oldList.end(), task));
    allTasks.erase(task);

    tasksOfProject[oldProjectID].erase(std::remove(tasksOfProject[oldProjectID].begin(),
            tasksOfProject[oldProjectID].end(), task));

    projectOfTask.erase(task);
    idGeneratorTasks.releaseID(task);
}

void TaskManager::deleteProject(ID project) {
    for(const auto& task : getAssociatedTasks(project)) {
        if(allTasks.at(task)->isProjectDependant())
            deleteTask(task);
        else
            unassignTask(task);
    }
    allProjects.erase(project);

    tasksOfProject.erase(project);
    idGeneratorProjects.releaseID(project);
}

void TaskManager::testPrintTasks() const {
    std::cout << std::endl;
    std::cout << "TASK MANAGER TEST PRINT" << std::endl;
    std::cout << std::endl;

    for (const auto& [id, project] : this->allProjects) {
        std::cout << "Project: " << "ID: " << id << " Name: "<< project->getName() << std::endl;
        std::cout << "Assigned Tasks: " << std::endl;
        for(const auto& task : getAssociatedTasks(id))
            std::cout << "ID: " << task << " Name: " << allTasks.at(task)->getName() << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "TEST PRINT END" << std::endl;
    std::cout << std::endl;
}

bool TaskManager::validateTaskID(const ID id) const {

    //return ( allTasks.find(id) != allTasks.end() );
    return allTasks.count(id);
}

bool TaskManager::validateProjectID(const ID id) const {

    //return ( allProjects.find(id) != allProjects.end() );
    return allProjects.count(id);
}



