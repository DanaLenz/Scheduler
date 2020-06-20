//
// Created by Dana on 15.03.2020.
//

#include "Timeslot.h"

const boost::posix_time::ptime &Timeslot::getStartTime() const {
    return startTime;
}

void Timeslot::setStartTime(const boost::posix_time::ptime &startTime) {
    Timeslot::startTime = startTime;
}

const boost::posix_time::time_period &Timeslot::getDuration() const {
    return duration;
}

//TODO: changing time information in Timeslots might change their positions in a Calendar
void Timeslot::setDuration(const boost::posix_time::time_period &duration) {
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
