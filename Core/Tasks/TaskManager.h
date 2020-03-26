//
// Created by Dana on 18.03.2020.
//

#ifndef SCHEDULER_TASKMANAGER_H
#define SCHEDULER_TASKMANAGER_H


#include <memory>
#include <deque>
#include <unordered_map>
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

    const ID createTask(std::string name);
    const ID createTask(std::string name, ID projectID);

    const ID createProject(std::string name);

    void deleteTask(const ID id);
    void deleteProject(const ID id);

    void transferTask(Task& task, Project& newProject);

    void unassignProject(const ID id);
    void unassignProject(Task& task);

    bool isTask(const ID id) const;
    bool isProject(const ID id) const;

    Project& getProject(const ID& id);
    Task& getTask(const ID& id);

    void testPrint() const;

    //ContainerProject::const_iterator iteratorProjectsBegin();
    //ContainerProject::const_iterator iteratorProjectsEnd();

    //std::vector<Task>::const_iterator iteratorTasksBegin();
    //std::vector<Task>::const_iterator iteratorTasksEnd();

    //std::vector<Task>::const_iterator iteratorProjectTasksBegin(Project& project);
    //std::vector<Task>::const_iterator iteratorProjectTasksEnd(Project& project);

    //TODO: save project and task data

private:
    static TaskManager * globalTaskManager;
    ID NOJECT;
    TaskManager();
    IDGenerator idGenerator;

    void assignProject(const ID taskID, const ID projectID);
    void assignProject(Task& task, Project& project);

    std::unordered_map<ID, Project> allProjects;
    std::unordered_map<ID, Task> allTasks;
};


#endif //SCHEDULER_TASKMANAGER_H
