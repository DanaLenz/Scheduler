//
// Created by Dana on 15.03.2020.
//

#include "Project.h"
#include <algorithm>
#include <iostream>


Project::Project() : Project("") {};

Project::Project(std::string name) : name(std::move(name)), minimumWeeklyHours(0), maximumWeeklyHours(0)
{}

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