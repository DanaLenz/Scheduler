//
// Created by Dana on 15.03.2020.
//

#include "Project.h"
#include <algorithm>
#include <iostream>


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

Project::Project(std::string name) : name(name), minimumWeeklyHours(0), maximumWeeklyHours(0)
{}

const std::string &Project::getName() const {
    return name;
}

void Project::setName(const std::string &name) {
    Project::name = name;
}

bool operator==(const Project& lhs, const Project& rhs) {
    return std::addressof(lhs) == std::addressof(rhs);
}
