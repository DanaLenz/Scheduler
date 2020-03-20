//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H

class Project;

//#include "Project.h"
//#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>
#include "IDGenerator.h"


class Task {

public:

    explicit Task(std::string name);
    Task(std::string name, const Project& project);

    const Project* getAssignedProject() const;
    void assignProject(Project * project);
    bool isProjectDependant() const;
    bool isOptional() const;
    void setProjectDependant(bool val);
    void setOptional(bool val);
    const std::string &getName() const;
    void setName(const std::string &name);
    float getNeededTime() const;
    void setNeededTime(float neededTime);

    //TODO: distributing the implementation of ID over 3 classes is not ideal
    // especially since it is identical for Task and Project
    const unsigned int getID() const;

private:
    std::string name;
    float neededTime;
    bool projectDependant;
    bool optional;
    //TODO: can the assigned Project be const?
    const Project* assignedProject;
    ID id;

    //TODO: task recurrence
    //TODO: task deadlines
};

bool operator==(const Task& lhs, const Task& rhs);

#endif //SCHEDULER_TASK_H
