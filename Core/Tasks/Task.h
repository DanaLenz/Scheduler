//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H



//#include "Project.h"
//#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>
#include "IDGenerator.h"
#include "../Definitions.h"


class Task {

    friend class TaskManager;

public:

    explicit Task(std::string name);

    [[nodiscard]] bool isProjectDependant() const;
    void setProjectDependant(bool val);

    [[nodiscard]] bool isOptional() const;
    void setOptional(bool val);

    [[nodiscard]] const std::string &getName() const;
    void setName(const std::string &name);

    [[nodiscard]] float getNeededTime() const;
    void setNeededTime(float neededTime);

    [[nodiscard]] Priority getPriority() const;

    void setPriority(Priority priority);

    [[nodiscard]] const Date &getDeadline() const;

    void setDeadline(const Date &deadline);

private:

    std::string name;
    float neededTime;
    bool projectDependant;
    bool optional;

    Priority priority;
    Date deadline;

    //ID id;
};

//bool operator==(const Task& lhs, const Task& rhs);

#endif //SCHEDULER_TASK_H
