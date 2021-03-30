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
#include "TaskRule.h"
#include "IDGenerator.h"


/**
 * The Task Manager (TM) manages all existing tasks and projects and their assignments.
 *
 * All operations that change the set of existing tasks/projects or their
 * assignments should be handled by the TM (e.g. creating/deleting tasks/projects,
 * assigning a task to/unassigning it from a project). As a rule of thumb, if
 * something only affects a single task/project it is handled in the
 * Task/Project class, if it affects multiple tasks/projects or their relationship,
 * it should be handled by the TM.
 *
 * This separation exists to decouple the management of classes and projects from
 * their actual implementation.
 *
 * The TM upholds the following guarantees:
 * 1. Each task is always assigned to exactly one project
 *    (unassiged tasks are internally assigned to a dummy project).
 * 2. A dummy project with the smallest ID exists.
 * 3. When tasks and projects are created, they are assigned a unique ID.
 * 4. When tasks and projects are deleted, their ID is freed.
 * 5. All tasks, projects and their assignments can be accessed by their ID.
 */

class TaskManager {


public:

    TaskManager();

    //static TaskManager * getTaskManager();

    /**
     * Creates an unassigned task.
     * @param name Name of the task
     * @return ID of the newly created task
     */
    ID createTask(const std::string& name);

    /**
     * Creates a task and assigns it to a project.
     * @param name Name of the task
     * @param project ID of the project it should be assigned to
     * @return ID of the newly created task
     */
    ID createTask(const std::string& name, ID project);

    /**
     * Creates a project.
     * @param name Name of the project
     * @return ID of the newly created project
     */
    ID createProject(const std::string& name);

    /**
     * Safely deletes a task, removing it from internal data structures
     * and freeing its ID.
     * @param task ID of the task to be deleted
     */
    void deleteTask(ID task);

    /**
     * Safely deletes a project, deleting project-dependent tasks
     * and unassigning the rest, removing it from internal data structures
     * and freeing its ID.
     * @param project ID of the project to be deleted
     */
    void deleteProject(ID project);

    /**
     * Assigns an existing task to an existing project. This can be called
     * on both assigned and unassigned tasks. (Functionality includes
     * unassigning the task, so unassignTask() does not need to be called separately.)
     * @param task ID of the task to be reassigned
     * @param newProject ID of the new project
     */
    void transferTask(ID task, ID newProject);

    /**
     * Unassign a task. This will internally assign it to the dummy project.
     * @param task ID of the task to be unassigned
     */
    void unassignTask(ID task);

    /**
     * Prints a formatted list of all existing projects and tasks to
     * standard output, grouped by project.
     */
    void testPrintTasks() const;

    /**
     * @param id ID of the request project
     * @return Reference to the project
     */
    [[nodiscard]] Project& getProject(const ID& id);
    /**
     * @param id ID of the requested task
     * @return Reference to the task
     */
    [[nodiscard]] Task& getTask(const ID& id);

    /**
     * @param id ID of the requested task rule
     * @return Reference to the task rule
     */
    [[nodiscard]] TaskRule& getTaskRule(const ID& id);


        /**
         * @param task ID of the task
         * @return Reference to the project the task is assigned to
         */
    [[nodiscard]] Project& associatedProject(const ID& task);
    /**
     * @param project ID of the project
     * @return a vector of IDs of all assigned tasks
     */
    [[nodiscard]] std::vector<ID> getAssociatedTasks(const ID& project) const;
    /**
     * @param taskID ID of the task
     * @return ID of the projects its assigned to
     */
    [[nodiscard]] ID getAssignedProject(const ID taskID) const;

    /**
     * Verifies that the given ID belongs to a task.
     * @param id ID to be verified
     * @return True iff a task with this ID exists currently
     */
    [[nodiscard]] bool validateTaskID(const ID id) const;
    /**
     * Verifies that the given ID belongs to a task.
     * @param id ID to be verified
     * @return True iff a project with this ID exists currently
     */
    [[nodiscard]] bool validateProjectID(const ID id) const;

    /**
     * Create and store a task rule
     * @param name The name for the task rule. Does not need to be unique and can be empty.
     * @return ID of the created task rule
     */
    ID createTaskRule(std::string name);

    /**
     * Create and store a task rule
     * @param name The name for the task rule. Does not need to be unique and can be empty.
     * @param project ID of the projet that this task rule should be assigned to
     * @return ID of the created task rule
     */
    ID createTaskRule (std::string name, ID project);

    /**
     * Removes the task rule, unassigns it from its project and frees its ID.
     * @param id ID of the task rule to be deleted.
     */
    void deleteTaskRule(ID id);

    /**
     * Unimplemented!
     * Should generate a file that contains an encoding for all saved tasks and
     * tasks generated from task rules in the specified date range
     * @param startDate First day tasks should be generated for
     * @param endDate Last day tasks should be generated for
     */
    void generateEncodings(TimeDefs::Date startDate, TimeDefs::Date endDate) const;

    /**
     * Returns a vector with IDs of all stored task rules.
     * @return IDs of all task rules
     */
    [[nodiscard]] std::vector<ID> getAllTaskRules();

private:

    //static TaskManager * globalTaskManager;
    ID NOJECT;

    void assignProject(ID task, ID project);

    IDGenerator idGeneratorTasks;
    IDGenerator idGeneratorProjects;

    std::map<ID, std::unique_ptr<Task>> allTasks;
    std::map<ID, std::unique_ptr<TaskRule>> allTaskRules;
    std::map<ID, std::unique_ptr<Project>> allProjects;

    std::map<ID, std::vector<ID>> tasksOfProject;
    std::map<ID, ID> projectOfTask;

};


#endif //SCHEDULER_TASKMANAGER_H
