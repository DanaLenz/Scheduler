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
    friend class TaskManager;

public:

    //TODO: Project constructors
    explicit Project(std::string name);

    float getMinimumWeeklyHours() const;
    void setMinimumWeeklyHours(float minimumWeeklyHours);
    float getMaximumWeeklyHours() const;
    void setMaximumWeeklyHours(float maximumWeeklyHours);
    const std::string &getName() const;

    void setName(const std::string &name);

private:

    std::string name;
    //TODO: implement projectQueue
    PriorityQueue projectQueue;
    //TODO: project maximum and minimum weekly hours
    float minimumWeeklyHours;
    float maximumWeeklyHours;
    //TODO: Project Tags

    ID id;

    std::vector<ID> assignedTasks;

};

bool operator==(const Project& lhs, const Project& rhs);

#endif //SCHEDULER_PROJECT_H
