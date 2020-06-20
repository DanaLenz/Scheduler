//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H



//#include "Project.h"
//#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>
#include "IDGenerator.h"


class Task {

    friend class TaskManager;
public:

    Task(std::string name);

    bool isProjectDependant() const;
    bool isOptional() const;
    void setProjectDependant(bool val);
    void setOptional(bool val);
    const std::string &getName() const;
    void setName(const std::string &name);
    float getNeededTime() const;
    void setNeededTime(float neededTime);


private:

    std::string name;
    float neededTime;
    bool projectDependant;
    bool optional;

    ID id;

    //TODO: task recurrence
    //TODO: task deadlines
};

bool operator==(const Task& lhs, const Task& rhs);

#endif //SCHEDULER_TASK_H
