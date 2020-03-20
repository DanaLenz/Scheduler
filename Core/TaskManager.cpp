//
// Created by Dana on 18.03.2020.
//

#include "TaskManager.h"
#include <algorithm>

TaskManager * TaskManager::globalTaskManager = TaskManager::getTaskManager();
Project TaskManager::NOJECT = Project("Unassigned");

TaskManager *TaskManager::getTaskManager() {
    if(globalTaskManager == nullptr)
        globalTaskManager = new TaskManager();
    return globalTaskManager;
}

ID TaskManager::createTask(std::string name) {
    Task task {std::move(name)};
    allTasks.insert(std::move(Task(name)));
    assignProject(&allTasks.back(), &NOJECT);
    return ;
}

ID TaskManager::createTask(std::string name, Project * project) {
    auto ptr = createTask(name);
    assignProject(ptr, project);

}

ID TaskManager::createProject(std::string name) {
    allProjects.push_back(Project {name});
    return allProjects.end()-1;
}

void TaskManager::deleteTask(Task * task) {
    allTasks.erase(std::remove(allTasks.begin(), allTasks.end(), *task));
}

void TaskManager::deleteProject(Project * project) {
    //reassign all project independent tasks
    //delete all project dependant tasks
    //then delete the project
    for(Task* task : project->getTasks()) {
        if(task->isProjectDependant())
            deleteTask(task);
        else
            assignProject(task, &NOJECT);
    }

    allProjects.erase(std::remove(allProjects.begin(), allProjects.end(), *project));
}

//TODO: CRITICAL the passed project is garbage
void TaskManager::assignProject(Task * task, Project * project) const {
    task->assignProject(project);
    project->addTask(task);
}

void TaskManager::unassignProject(Task * task) const {
    assignProject(task, &NOJECT);
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

unsigned int TaskManager::getID() {

    ID id;

    if(!idPool.empty()) {
        id = idPool.back();
        idPool.pop_back();
    }

    id = nextID++;
    lastID = id;
    return id;
}
