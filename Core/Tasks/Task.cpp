//
// Created by Dana on 15.03.2020.
//

#include "Task.h"


void Task::assignProject(ID project) {
    assignedProjectID = project;
}

//TODO: constructor needs to assign to NOJECT

Task::Task(std::string name, IDGenerator& idGenerator, ID project)
        : name(std::move(name)), neededTime(0), projectDependant(false), optional(false),
        assignedProjectID(project), id(idGenerator.getID()) {}

bool operator==(const Task& lhs, const Task& rhs) {
    return std::addressof(lhs) == std::addressof(rhs);
}

//warning: you are entering the dull, barren wasteland of setters and getters

ID Task::getID() const{ return id; }
bool Task::isProjectDependant() const { return projectDependant; }
bool Task::isOptional() const { return optional; }
void Task::setProjectDependant(const bool val) { projectDependant = val; }
void Task::setOptional(const bool val) { optional = val; }
const std::string &Task::getName() const { return name; }
void Task::setName(const std::string &name) { Task::name = name; }
float Task::getNeededTime() const { return neededTime; }
void Task::setNeededTime(float neededTime) { Task::neededTime = neededTime; }
ID Task::getAssignedProjectID() const  { return assignedProjectID; }
