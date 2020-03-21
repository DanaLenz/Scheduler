//
// Created by Dana on 18.03.2020.
//

#include "TaskManager.h"
#include <algorithm>
#include <typeinfo>

TaskManager * TaskManager::globalTaskManager = TaskManager::getTaskManager();
Project TaskManager::NOJECT = Project("Unassigned");

TaskManager *TaskManager::getTaskManager() {
    if(globalTaskManager == nullptr)
        globalTaskManager = new TaskManager();
    return globalTaskManager;
}

ID TaskManager::createTask(std::string name) {
    Task task {std::move(name)};
    allTasks.insert(std::make_pair(task.getID(), name));
    assignProject(task, NOJECT);
    return task.getID();
}

ID TaskManager::createTask(std::string name, Project * project) {
    auto taskID = createTask(name);
    assignProject(taskID, project->getID());

}

ID TaskManager::createProject(std::string name) {
    Project project {name};
    allProjects.insert(std::make_pair(project.getID(), project));
    return project.getID();
}

void TaskManager::deleteTask(ID taskID) {
    allTasks.erase(taskID);
}

void TaskManager::deleteProject(ID projectID) {
    //reassign all project independent tasks
    //delete all project dependant tasks
    //then delete the project
    Project& project = allProjects.at(projectID);
    for(Task* task : project.getTasks()) {
        if(task->isProjectDependant())
            deleteTask(task->getID());
        else
            assignProject(*task, NOJECT);
    }

    allProjects.erase(projectID);
}

bool TaskManager::isTask(const ID id) const {
    return allTasks.count(id) != 0;
}

bool TaskManager::isProject(const ID id) const {
    return allProjects.count(id) != 0;
}

//TODO: make the argument order optional
void TaskManager::assignProject(ID id1, ID id2) const {

    auto taskit = allTasks.end();
    auto projectit = allProjects.end();

    if (isTask(id1))
        if(isProject(id2))
        {
            taskit = allTasks.find(id1);
            projectit = allProjects.find(id2);
        }
        else
        {
            //Error
        }
    else if(isProject(id1)) {
        if(isTask(id2)){
            projectit = allProjects.find(id1);
            taskit = allTasks.find(id2);
        }
        else {
            //Error
        }
    }
    else {
        //Error
    }

    assignProject(task, project);
}

void TaskManager::assignProject(Task &task, Project &project) const {
    task.assignProject(&project);
    project.addTask(&task);
}

void TaskManager::unassignProject(const ID taskid) const {
    Task& task = allTasks.at(taskid);
    unassignProject(task);
}

void TaskManager::unassignProject(Task& task) const {
    assignProject(task, NOJECT);
}

TaskManager::TaskManager() {
    allTasks = {};
    allProjects = {};
    nextID = 0;
    createProject("NOJECT");
}


std::vector<Project>::const_iterator TaskManager::iteratorProjectsBegin() {
    return allProjects.begin();
}

std::vector<Project>::const_iterator TaskManager::iteratorProjectsEnd() {
    return allProjects.end();
}

