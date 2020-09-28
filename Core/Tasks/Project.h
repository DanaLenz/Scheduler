//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_PROJECT_H
#define SCHEDULER_PROJECT_H


#include <unordered_set>
#include <iterator>
#include <vector>
#include "Task.h"
#include "../Definitions.h"

class Project {
    friend class TaskManager;

public:

    //TODO: Project constructors
    explicit Project(std::string name);

    [[nodiscard]] float getMinimumWeeklyHours() const;
    void setMinimumWeeklyHours(float minimumWeeklyHours);

    [[nodiscard]] float getMaximumWeeklyHours() const;
    void setMaximumWeeklyHours(float maximumWeeklyHours);

    [[nodiscard]] const std::string &getName() const;
    void setName(const std::string &name);

    [[nodiscard]]  bool isTaskAssigned(ID taskID);

    Priority getPriority() const;

    void setPriority(Priority priority);


private:

    std::string name;
    //Priority priority;
    //Date deadline;
    //TODO: project maximum and minimum weekly hours
    float minimumWeeklyHours;
    float maximumWeeklyHours;
    //TODO: Project Tags

    ID id;

    std::vector<ID> assignedTasks;

};

bool operator==(const Project& lhs, const Project& rhs);

#endif //SCHEDULER_PROJECT_H
