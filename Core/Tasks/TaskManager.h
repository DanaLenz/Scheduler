//
// Created by Dana on 18.03.2020.
//

#ifndef SCHEDULER_TASKMANAGER_H
#define SCHEDULER_TASKMANAGER_H


#include <memory>
#include <deque>
#include <map>
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
 * 5. The Priority Manager is kept consistent
 */

class TaskManager {

    //TODO: friend this class with task and project and make their functions private?
    //TODO: The TaskManager class is very hacked together. I don't like it. Do it again.

public:

    TaskManager();

    static TaskManager * getTaskManager();

    ID createTask(const std::string& name);
    ID createTask(const std::string& name, ID project);

    ID createProject(const std::string& name);

    void deleteTask(ID task);
    void deleteProject(ID project);

    void transferTask(ID task, ID newProject);
    void unassignTask(ID task);

    void testPrintTasks() const;

    [[nodiscard]] Project& getProject(const ID& id);
    [[nodiscard]] Task& getTask(const ID& id);
    [[nodiscard]] Project& associatedProject(const ID& task);
    [[nodiscard]] std::vector<ID> getAssociatedTasks(const ID& project) const;
    [[nodiscard]] ID getAssignedProject(const ID taskID) const;

    //TODO: save project and task data

private:

    //static TaskManager * globalTaskManager;
    ID NOJECT;

    void assignProject(ID task, ID project);

    bool validateTaskID(ID id);
    bool validateProjectID(ID id);

    IDGenerator idGeneratorTasks;
    IDGenerator idGeneratorProjects;

    std::map<ID, std::unique_ptr<Task>> allTasks;
    std::map<ID, std::unique_ptr<Project>> allProjects;

    std::map<ID, std::vector<ID>> tasksOfProject;
    std::map<ID, ID> projectOfTask;
};


#endif //SCHEDULER_TASKMANAGER_H
