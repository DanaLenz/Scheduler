//
// Created by Dana on 15.03.2020.
//

#include "Timeslot.h"

const TimePeriod &Timeslot::getStartTime() const {
    return startTime;
}

void Timeslot::setStartTime(const TimePeriod &startTime) {
    Timeslot::startTime = startTime;
}

const TimePeriod &Timeslot::getDuration() const {
    return duration;
}

//TODO: changing time information in Timeslots might change their positions in a CalendarGenerator
void Timeslot::setDuration(const TimePeriod &duration) {
    Timeslot::duration = duration;
}

void Timeslot::assign(Task &task) {
    assignedTask = &task;
}

bool Timeslot::isAssigned() const {
    return assignedTask != nullptr;
}

void Timeslot::unassign() {
    assignedTask = nullptr;
}

Timeslot::Timeslot(const Date &date, const TimePeriod &startTime, const TimePeriod &duration)
: date{date}, startTime{startTime}, duration{duration} {}

const Date &Timeslot::getDate() const {
    return date;
}

void Timeslot::setDate(const Date &date) {
    Timeslot::date = date;
}

bool operator<(const Timeslot& lhs, const Timeslot& rhs) {

    if(lhs.getDate() != rhs.getDate())
        return lhs.getDate() < rhs.getDate();
    else
        return lhs.getStartTime() < rhs.getStartTime();
}
