//
// Created by dana on 03.10.20.
//

#include "TaskRule.h"

const std::map<std::string, RecurrenceType> TaskRule::recurrenceTypeStrings = {{"X Times Each Week", RecurrenceType::X_IN_WEEK},
                                                             {"Every X Days", RecurrenceType::EVERY_X_DAYS},
                                                             {"Infinite", RecurrenceType::INFINITE}};

const TimeDefs::Date &TaskRule::getStartDate() const {
    return startDate;
}

void TaskRule::setStartDate(const TimeDefs::Date &startDate) {
    TaskRule::startDate = startDate;
}

const TimeDefs::Date &TaskRule::getEndDate() const {
    return endDate;
}

void TaskRule::setEndDate(const TimeDefs::Date &endDate) {
    TaskRule::endDate = endDate;
}

RecurrenceType TaskRule::getRecurrenceType() const {
    return recurrenceType;
}

void TaskRule::setRecurrenceType(RecurrenceType recurrenceType) {
    TaskRule::recurrenceType = recurrenceType;
}

size_t TaskRule::getXtimes() const {
    return xtimes;
}

void TaskRule::setXtimes(size_t xtimes) {
    TaskRule::xtimes = xtimes;
}

const TimeDefs::DateDuration &TaskRule::getEveryXDays() const {
    return everyXDays;
}

void TaskRule::setEveryXDays(const TimeDefs::DateDuration &everyXDays) {
    TaskRule::everyXDays = everyXDays;
}

const std::string &TaskRule::getName1() const {
    return name;
}

void TaskRule::setName1(const std::string &name) {
    TaskRule::name = name;
}

float TaskRule::getNeededTime1() const {
    return neededTime;
}

void TaskRule::setNeededTime1(float neededTime) {
    TaskRule::neededTime = neededTime;
}

bool TaskRule::isProjectDependant1() const {
    return projectDependant;
}

void TaskRule::setProjectDependant1(bool projectDependant) {
    TaskRule::projectDependant = projectDependant;
}

bool TaskRule::isOptional1() const {
    return optional;
}

void TaskRule::setOptional1(bool opt) {
    optional = opt;
}

DeadlineType TaskRule::getDeadlineType() const {
    return deadlineType;
}

void TaskRule::setDeadlineType(DeadlineType deadlineType) {
    TaskRule::deadlineType = deadlineType;
}

const TimeDefs::Date &TaskRule::getAbsoluteDeadline() const {
    return absoluteDeadline;
}

void TaskRule::setAbsoluteDeadline(const TimeDefs::Date &absoluteDeadline) {
    TaskRule::absoluteDeadline = absoluteDeadline;
}

const TimeDefs::DateDuration &TaskRule::getRelativeDeadline() const {
    return relativeDeadline;
}

void TaskRule::setRelativeDeadline(const TimeDefs::DateDuration &relativeDeadline) {
    TaskRule::relativeDeadline = relativeDeadline;
}

TimeDefs::Date today() {
    return boost::gregorian::day_clock::local_day();
}

TaskRule::TaskRule(std::string name) : Task(name),
startDate {today()},
endDate {today()},
recurrenceType {RecurrenceType::X_IN_WEEK},
xtimes {1},
everyXDays {7},
relativeDeadline {7},
deadlineType {DeadlineType::NONE}
{}
