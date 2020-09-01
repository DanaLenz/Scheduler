//
// Created by dana on 16.06.20.
//

#include "TimeslotRule.h"

const TimePeriod &TimeslotRule::getStartTime() const {
    return startTime;
}

void TimeslotRule::setStartTime(const TimePeriod &startTime) {
    TimeslotRule::startTime = startTime;
}

const TimePeriod &TimeslotRule::getDuration() const {
    return duration;
}

void TimeslotRule::setDuration(const TimePeriod &duration) {
    TimeslotRule::duration = duration;
}

bool TimeslotRule::isRecurrent() const {
    return recurrent;
}

void TimeslotRule::setRecurrent(bool recurrent) {
    TimeslotRule::recurrent = recurrent;
}

TimeslotRule::TimeslotRule(Weekday &weekday, TimePeriod &startTime, TimePeriod &duration)
    : weekday{weekday}, startTime{startTime}, duration{duration} {}

Timeslot TimeslotRule::createTimeslot(const Date &date) const {
    return Timeslot{date, startTime, duration};
}

const bool TimeslotRule::getWeekday() const {
    return weekday;
}

//TODO: does this constructor get called by other constructors?
TimeslotRule::TimeslotRule()
    : startTime{}, duration{startTime, startTime}, recurrent{false}, tags{}, weekday{0} {}

bool operator<(const TimeslotRule& lhs, const TimeslotRule& rhs) {

    // sort by weekday first,
    // start time second
    // this is unique if there is no overlap

    if(lhs.getWeekday() != rhs.getWeekday())
        return lhs.getWeekday() < rhs.getWeekday();
    else
        return lhs.getStartTime() < rhs.getStartTime();

}
