//
// Created by Dana on 18.03.2020.
//

#include "TaskManager.h"
#include <algorithm>
#include <typeinfo>
#include <iostream>
#include <cassert>

TaskManager * TaskManager::globalTaskManager = TaskManager::getTaskManager();

TaskManager *TaskManager::getTaskManager() {
    if(globalTaskManager == nullptr)
        globalTaskManager = new TaskManager();
    return globalTaskManager;
}

const ID TaskManager::createTask(std::string name, ID projectID) {
    Task task {std::move(name), idGenerator, projectID};
    allTasks.insert(std::make_pair(task.getID(), task));
    assignProject(task.getID(), projectID);
}

const ID TaskManager::createTask(std::string name) {
    return createTask(name, NOJECT);
}

const ID TaskManager::createProject(std::string name) {
    Project project {name, idGenerator};
    allProjects.insert(std::make_pair(project.getID(), project));
    return project.getID();
}

void TaskManager::deleteTask(ID taskID) {
    assert(taskID < allTasks.size() + allProjects.size() && "Invalid ID passed to deleteTask in TaskManager");
    unassignProject(taskID);
    allTasks.erase(taskID);
}

void TaskManager::deleteProject(ID projectID) {
    assert(projectID < allTasks.size() + allProjects.size() && "Invalid ID passed to deleteProject in TaskManager");
    //reassign all project independent tasks
    //delete all project dependant tasks
    //then delete the project
    Project& project = allProjects.at(projectID);
    for(Task* task : project.getTasks()) {
        if(task->isProjectDependant())
            deleteTask(task->getID());
        else
            assignProject(task->getID(), NOJECT);
    }

    allProjects.erase(projectID);
}

bool TaskManager::isTask(const ID id) const {
    return allTasks.count(id) != 0;
}

bool TaskManager::isProject(const ID id) const {
    return allProjects.count(id) != 0;
}

//TODO: error catching in assignProject
//TODO: make the argument order optional
void TaskManager::assignProject(ID id1, ID id2) {
    assert(id1 < allTasks.size() + allProjects.size() && "Invalid ID passed to assignProject in TaskManager");
    assert(id2 < allTasks.size() + allProjects.size() && "Invalid ID passed to assignProject in TaskManager");


    if (isTask(id1))
        if(isProject(id2))
        {
            Task& task = allTasks.at(id1);
            Project& project = allProjects.at(id2);
            assignProject(task, project);
        }
        else
        {
            //Error
        }
    else if(isProject(id1)) {
        if(isTask(id2)){
            Project& project = allProjects.at(id1);
            Task& task = allTasks.at(id2);
            assignProject(task, project);
        }
        else {
            //Error
        }
    }
    else {
        //Error
    }

}

void TaskManager::assignProject(Task &task, Project &project){
    task.assignProject(project.getID());
    project.addTask(&task);
}

void transferTask(Task& task, Project& newProject) {
    Project& oldProject = getProject(task.getAssignedProjectID());
    oldProject.removeTask(task);
    newProject.addTask(task);
    task.assignProject(newProject.getID());
}

//TODO: un-mess unassignProject
void TaskManager::unassignProject(const ID taskid) {
    assert(taskid < allTasks.size() + allProjects.size() && "Invalid ID passed to unassignProject in TaskManager");
    Task& task = allTasks.at(taskid);
    getProject(task.getAssignedProjectID()).removeTask(task);
    if(task.getAssignedProjectID() != NOJECT)
        assignProject(taskid, NOJECT);
}

void TaskManager::unassignProject(Task& task){
    unassignProject(task.getID());
}


TaskManager::TaskManager() {
    allTasks = {};
    allProjects = {};
    idGenerator = IDGenerator();

    NOJECT = createProject("Unassigned");
}

void TaskManager::testPrint() const {
    for (const auto& [id, p] : this->allProjects) {
        p.testPrint();
    }

}

Project &TaskManager::getProject(const ID& id) {
    assert(id < allTasks.size() + allProjects.size() && "Invalid ID passed to getProject in TaskManager");
    return allProjects.at(id);
}

Task &TaskManager::getTask(const ID& id) {
    assert(id < allTasks.size() + allProjects.size() && "Invalid ID passed to getTask in TaskManager");
    return allTasks.at(id);
}

