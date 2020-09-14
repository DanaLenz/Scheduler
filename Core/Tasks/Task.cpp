//
// Created by Dana on 15.03.2020.
//

#include "Task.h"

Task::Task(std::string name)
        : name(std::move(name)), neededTime(0), projectDependant(false), optional(false) {}

//bool operator==(const Task& lhs, const Task& rhs) {
//    return std::addressof(lhs) == std::addressof(rhs);
//}

//warning: you are entering the dull, barren wasteland of setters and getters

bool Task::isProjectDependant() const { return projectDependant; }
bool Task::isOptional() const { return optional; }
void Task::setProjectDependant(const bool val) { projectDependant = val; }
void Task::setOptional(const bool val) { optional = val; }
const std::string &Task::getName() const { return name; }
void Task::setName(const std::string &name) { Task::name = name; }
float Task::getNeededTime() const { return neededTime; }
void Task::setNeededTime(float neededTime) { Task::neededTime = neededTime; }
