//
// Created by Dana on 15.03.2020.
//

#include "Timeslot.h"

const TimeDefs::TimePeriod &Timeslot::getStartTime() const {
    return startTime;
}

const TimeDefs::TimePeriod &Timeslot::getDuration() const {
    return duration;
}

Timeslot::Timeslot(const TimeDefs::Date &date, const TimeDefs::TimePeriod &startTime, const TimeDefs::TimePeriod &duration) : date{date}, startTime{startTime}, duration{duration} {}

const TimeDefs::Date &Timeslot::getDate() const {
    return date;
}

bool operator<(const Timeslot& lhs, const Timeslot& rhs) {

    if(lhs.getDate() != rhs.getDate())
        return lhs.getDate() < rhs.getDate();
    else
        return lhs.getStartTime() < rhs.getStartTime();
}
