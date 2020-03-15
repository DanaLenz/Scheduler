//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_PROJECT_H
#define SCHEDULER_PROJECT_H


#include <vector>
#include <memory>
#include <iterator>
#include "Task.h"
#include "PriorityQueue.h"

class Project {

public:

    //Project();
    //~Project();

    Task* createTask();
    void removeTask(Task& task);
    void transferTask(Task& task, Project& targetProject);

    float getMinimumWeeklyHours() const;
    void setMinimumWeeklyHours(float minimumWeeklyHours);
    float getMaximumWeeklyHours() const;
    void setMaximumWeeklyHours(float maximumWeeklyHours);

    //TODO: change task access over projects
    Task* accessTask(const int index);
    std::vector<Task> associatedTasks;

private:

    PriorityQueue projectQueue;
    float minimumWeeklyHours;
    float maximumWeeklyHours;

};



#endif //SCHEDULER_PROJECT_H
