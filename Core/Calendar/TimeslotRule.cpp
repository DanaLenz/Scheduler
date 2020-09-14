//
// Created by dana on 16.06.20.
//

#include "TimeslotRule.h"


Timeslot TimeslotRule::createTimeslot(const Date &date) const {
    return Timeslot{date, startTime, duration};
}

TimeslotRule::TimeslotRule(const Weekday &weekday, const TimePeriod &startTime, const TimePeriod &duration)
        : weekday{weekday}, startTime{startTime}, duration{duration}  {}


bool operator<(const TimeslotRule& lhs, const TimeslotRule& rhs) {

    // sort by weekday first,
    // start time second
    // this is unique if there is no overlap

    if(lhs.getWeekday() != rhs.getWeekday())
        return lhs.getWeekday() < rhs.getWeekday();
    else
        return lhs.getStartTime() < rhs.getStartTime();

}

const TimePeriod &TimeslotRule::getStartTime() const {
    return startTime;
}

const TimePeriod &TimeslotRule::getDuration() const {
    return duration;
}

const Weekday TimeslotRule::getWeekday() const {
    return weekday;
}