//
// Created by dana on 09.04.21.
//

#include "TagManager.h"

bool TagManager::addTag(const std::string &name) {

    //tag exists already
    if(tagTaskAssignment.count(name))
        return false;

    tagTaskAssignment[name] = {};
    tagTimeslotAssignment[name] = {};

    return true;

}

bool TagManager::deleteTag(const std::string &name) {

    for(const auto &task : tagTaskAssignment.at(name))
        taskManager.getTaskRule(task).removeTag(name);

    for(const auto &timeslot : tagTimeslotAssignment.at(name))
        calendarGenerator.getReference(timeslot.first, timeslot.second).removeTag(name);

    tagTaskAssignment.erase(name);
    tagTimeslotAssignment.erase(name);

    return true;

}

std::vector<std::string> TagManager::getAllTags() const {

    std::vector<std::string> result;
    for(const auto pair : tagTaskAssignment)
        result.push_back(pair.first);

    return result;
}

std::vector<ID> TagManager::getTasksOfTag(const std::string &name) const {
    return tagTaskAssignment.at(name);
}

std::vector<TimeslotRule *> TagManager::getTimeslotsOfTag(const std::string &name) const {

    std::vector<TimeslotRule *> res;
    for(auto &tsr : tagTimeslotAssignment.at(name)) {
        auto &ref = calendarGenerator.getReference(tsr.first, tsr.second);
        res.push_back(&ref);
    }
    return res;
}

void TagManager::addTag(ID task, const std::string &tag) {

    tagTaskAssignment.at(tag).push_back(task);
    taskManager.getTaskRule(task).addTag(tag);

}

void TagManager::addTag(TimeslotRule &timeslot, const std::string &tag) {

    tagTimeslotAssignment.at(tag).push_back(std::make_pair(timeslot.getWeekday(), timeslot.getStartTime()));
    timeslot.addTag(tag);

}

void TagManager::removeTag(const Task &task, const std::string &tag) {

    for(const auto task : tagTaskAssignment.at(tag))
        taskManager.getTaskRule(task).removeTag(tag);

    tagTaskAssignment.erase(tag);

}

void TagManager::removeTag(const TimeslotRule &timeslot, const std::string &tag) {

    for(const auto ts : tagTimeslotAssignment.at(tag))
        calendarGenerator.getReference(ts.first, ts.second).removeTag(tag);

    tagTimeslotAssignment.erase(tag);

}

TagManager::TagManager(const TaskManager &tm, const CalendarGenerator &cg) : taskManager(tm), calendarGenerator(cg) {

}
