//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H


#include <memory>

class Task {

public:
    bool isProjectDependant() const;
    bool isOptional() const;
    void setProjectDependant(bool val);
    void setOptional(bool val);

    const std::string &getName() const;

    void setName(const std::string &name);

    float getNeededTime() const;

    void setNeededTime(float neededTime);

private:
    std::string name = "";
    //recurrence
    float neededTime = 0;
    //project
    //deadlines
    bool projectDependant = false;
    bool optional = false;

};

bool operator==(const Task& lhs, const Task& rhs);

#endif //SCHEDULER_TASK_H
