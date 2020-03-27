//
// Created by Dana on 18.03.2020.
//

#ifndef SCHEDULER_TASKMANAGER_H
#define SCHEDULER_TASKMANAGER_H


#include <memory>
#include <deque>
#include <unordered_map>
#include <set>
#include "Project.h"
#include "Task.h"
#include "IDGenerator.h"


/*
 * The Task Manager is responsible for creating, storing and deleting Tasks and Projects
 * There should always be exactly one instance of the TaskManager
 *
 * The Task Manager guarantees that:
 * 1. Each Task is always assigned to exactly one Project
 * 2. Each Task and it's assigned Project hold a unique pointer to each other
 * 3. All tasks and projects are saved in the respective container here
 * 4. Tasks and Projects are deleted properly
 */

class TaskManager {

    //TODO: friend this class with task and project and make their functions private?
    //TODO: figure out whether to use smart pointers in Task and Project

    //TODO: assign task manager at task and project creation

    //TODO: TaskManager should be a singleton
public:

    static TaskManager * getTaskManager();

    ID createTask(std::string name);
    ID createTask(std::string name, ID project);

    ID createProject(std::string name);

    void deleteTask(ID task);
    void deleteProject(ID project);

    void transferTask(ID task, ID newProject);

    void removeTask(ID task);
    void unassignTask(ID task);

    void testPrint() const;

    Project& getProject(const ID& id);
    Task& getTask(const ID& id);
    Project& associatedProject(const ID& task);
    std::vector<Task *> associatedTasks(const ID& project);

    //TODO: save project and task data

private:
    static TaskManager * globalTaskManager;
    ID NOJECT; //TODO: re-implement NOJECT
    TaskManager();

    void assignProject(ID task, ID project);

    bool validateTaskID(ID id);
    bool validateProjectID(ID id);

    IDGenerator idGeneratorTasks;
    IDGenerator idGeneratorProjects;

    std::unordered_map<ID, Task> allTasks;
    std::unordered_map<ID, Project> allProjects;

};


#endif //SCHEDULER_TASKMANAGER_H
