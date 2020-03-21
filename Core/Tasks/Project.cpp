//
// Created by Dana on 15.03.2020.
//

#include "Project.h"
#include <algorithm>


void Project::addTask(Task * task) {
   associatedTasks.insert(task);
}

void Project::removeTask(Task& task) {

   associatedTasks.erase(&task);

    //TODO: where do I put NOJECT?
    if(!task.isProjectDependant())
    {}//transferTask(task, NOJECT);
    else
    {}// taskManager.removeTask(task);
}

//simple, boring Getters and Setters below

float Project::getMinimumWeeklyHours() const {
    return minimumWeeklyHours;
}

void Project::setMinimumWeeklyHours(float minimumWeeklyHours) {
    Project::minimumWeeklyHours = minimumWeeklyHours;
}

float Project::getMaximumWeeklyHours() const {
    return maximumWeeklyHours;
}

void Project::setMaximumWeeklyHours(float maximumWeeklyHours) {
    Project::maximumWeeklyHours = maximumWeeklyHours;
}

Project::Project(std::string name) : name(name), minimumWeeklyHours(0), maximumWeeklyHours(0), id(IDGenerator::getID())
{}

Project::~Project() {

    for(Task* task : associatedTasks){
        this->removeTask(*task);
    }

    //taskManager.removeProject();
}

//TODO: will this return correctly?
std::unordered_set<Task *> Project::getTasks() {
    return associatedTasks;
}

const std::string &Project::getName() const {
    return name;
}

void Project::setName(const std::string &name) {
    Project::name = name;
}

ID Project::getID() const{ return id; }

bool operator==(const Project& lhs, const Project& rhs) {
    return std::addressof(lhs) == std::addressof(rhs);
}
