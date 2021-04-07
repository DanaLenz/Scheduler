//
// Created by Dana on 15.03.2020.
//

#include "Project.h"
#include <algorithm>
#include <iostream>


Project::Project() : Project("") {};

Project::Project(std::string name) : name(std::move(name)), minimumWeeklyMinutes(0), maximumWeeklyMinutes(0)
{}

//simple, boring Getters and Setters below

unsigned int Project::getMinimumWeeklyMinutes() const {
    return minimumWeeklyMinutes;
}

void Project::setMinimumWeeklyMinutes(unsigned int minimumWeeklyHours) {
    Project::minimumWeeklyMinutes = minimumWeeklyHours;
}

unsigned int Project::getMaximumWeeklyMinutes() const {
    return maximumWeeklyMinutes;
}

void Project::setMaximumWeeklyMinutes(unsigned int maximumWeeklyHours) {
    Project::maximumWeeklyMinutes = maximumWeeklyHours;
}

const std::string &Project::getName() const {
    return name;
}

void Project::setName(const std::string &name) {
    Project::name = name;
}

const TimeDefs::Date &Project::getDeadline() const {
    return deadline;
}

void Project::setDeadline(const TimeDefs::Date &deadline) {
    Project::deadline = deadline;
}

bool operator==(const Project& lhs, const Project& rhs) {
    return std::addressof(lhs) == std::addressof(rhs);
}