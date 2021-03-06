//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H


#include <string>
#include "IDGenerator.h"
#include "../Definitions.h"

/**
 * A task is a single instance of 'something that needs to be done',
 * generally created from a task rule.
 */
class Task {

    friend class TaskManager;

public:

    /**
     * Initializes a task to be project-independent and non-optional.
     * @param name Name of the task
     */
    explicit Task(std::string name);

    /**
     * @return True if task should be deleted when assigned project is
     */
    [[nodiscard]] bool isProjectDependant() const;
    /**
     * @param val True if task should be deleted when assigned project is
     */
    void setProjectDependant(bool val);

    /**
     * @return True if a task is not necessary to a projects completion.
     * If the task is unassigned, the value does not matter.
     */
    [[nodiscard]] bool isOptional() const;
    /**
     * @param val True if a task is not necessary to a projects completion.
     * If the task is unassigned, the value does not matter.
     */
    void setOptional(bool val);

    /**
     * Note: names of tasks can be changed freely, since they are identified
     * by their ID
     * @return name of the task
     */
    [[nodiscard]] const std::string &getName() const;
    /**
     * Note: names of tasks can be changed freely, since they are identified
     * by their ID
     * @param name name of the task
     */
    void setName(const std::string &name);

    /**
     * The estimated time affects what timeslots can be selected for a task
     * @return Estimated amount of time needed to complete this task
     */
    [[nodiscard]] float getNeededTime() const;
    /**
     * The estimated time affects what timeslots can be selected for a task
     * @param neededTime Estimated amount of time needed to complete this task
     */
    void setNeededTime(float neededTime);

    /**
     * The deadline of a task, may differ of that of its assigned project.
     * If a task is assigned to a project with an earlier deadline, that will
     * overrule the task-specific deadline.
     * @return Task deadline
     */
    [[nodiscard]] const TimeDefs::Date &getDeadline() const;
     /**
     * The deadline of a task, may differ of that of its assigned project.
     * If a task is assigned to a project with an earlier deadline, that will
     * overrule the task-specific deadline.
     * @param deadline Task deadline
     */
    void setDeadline(const TimeDefs::Date &deadline);

    /**
     * The start date is the earliest date a task can be scheduled at.
     * @return The start date
     */
    const TimeDefs::Date &getStartDate() const;

    /**
     * The start date is the earliest date a task can be scheduled at.
     * @param startDate The start date
     */
    void setStartDate(const TimeDefs::Date &startDate);


protected:

    std::string name;
    float neededTime;
    bool projectDependant;
    bool optional;

private:
    TimeDefs::Date deadline;
    TimeDefs::Date startDate;


};

bool operator==(const Task& lhs, const Task& rhs);

#endif //SCHEDULER_TASK_H
