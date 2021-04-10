//
// Created by Dana on 15.03.2020.
//

#include "Task.h"

Task::Task(std::string name)
        : name(std::move(name)), neededTime(0), projectDependant(false), optional(false), startDate(boost::gregorian::day_clock::local_day()) {}

bool operator==(const Task &lhs, const Task &rhs) {
    return std::addressof(lhs) == std::addressof(rhs);
}

//warning: you are entering the dull, barren wasteland of setters and getters

bool Task::isProjectDependant() const {
    return projectDependant;
}

bool Task::isOptional() const {
    return optional;
}

void Task::setProjectDependant(const bool val) {
    projectDependant = val;
}

void Task::setOptional(const bool val) {
    optional = val;
}

const std::string &Task::getName() const {
    return name;
}

void Task::setName(const std::string &n) {
    name = n;
}

size_t Task::getNeededTime() const {
    return neededTime;
}

void Task::setNeededTime(size_t neededTime) {
    Task::neededTime = neededTime;
}

const TimeDefs::Date &Task::getDeadline() const {
    return deadline;
}

void Task::setDeadline(const TimeDefs::Date &deadline) {
    Task::deadline = deadline;
}

const TimeDefs::Date &Task::getStartDate() const {
    return startDate;
}

void Task::setStartDate(const TimeDefs::Date &startDate) {
    Task::startDate = startDate;
}

bool Task::addTag(const std::string &tag) {

    if(tags.count(tag))
        return false;

    tags[tag] = 1;
    return true;

}

bool Task::removeTag(const std::string &tag) {

    if(!tags.count(tag))
        return false;

    tags.erase(tag);
    return true;

}

std::vector<std::string> Task::getAllTags() {

    std::vector<std::string> result;
    for(const auto &pair : tags)
        result.push_back(pair.first);

    return result;
}

int Task::getTagPriority(const std::string &tag) {
    return tags.at(tag);
}

bool Task::setTagPriority(const std::string &tag, int priority) {

    if(!tags.count(tag))
        return false;

    tags.at(tag) = priority;
    return true;
}
