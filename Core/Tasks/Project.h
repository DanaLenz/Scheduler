//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_PROJECT_H
#define SCHEDULER_PROJECT_H


#include <unordered_set>
#include <iterator>
#include <vector>
#include "Task.h"
#include "../PriorityQueue.h"


class Project {

public:

    //TODO: Project constructors
    Project(std::string name);
    ~Project();

    void removeTask(Task& task);
    void addTask(Task * task);

    float getMinimumWeeklyHours() const;
    void setMinimumWeeklyHours(float minimumWeeklyHours);
    float getMaximumWeeklyHours() const;
    void setMaximumWeeklyHours(float maximumWeeklyHours);
    std::unordered_set<Task*> getTasks();
    const std::string &getName() const;

    void setName(const std::string &name);
    ID getID() const;

private:

    std::string name;
    //TODO: implement projectQueue
    PriorityQueue projectQueue;
    //TODO: project maximum and minimum weekly hours
    float minimumWeeklyHours;
    float maximumWeeklyHours;
    std::unordered_set<Task*> associatedTasks;
    //TODO: Project Tags
    const unsigned int id;

};

bool operator==(const Project& lhs, const Project& rhs);

#endif //SCHEDULER_PROJECT_H
