//
// Created by dana on 16.06.20.
//

#ifndef SCHEDULER_TIMESLOTRULE_H
#define SCHEDULER_TIMESLOTRULE_H

#include "Definitions.h"
#include "Timeslot.h"
#include <vector>

class TimeslotRule {

public:

    TimeslotRule(Weekday &weekday, TimePeriod &startTime, TimePeriod& duration);

    //For Scheduler:
    Timeslot createTimeslot(const Date& date) const;

    //For the Interface:
    const TimePoint &getStartTime() const;
    void setStartTime(const TimePeriod &startTime);

    //TODO: why do automatically generated getters have '&' before function name?
    const TimePeriod &getDuration() const;
    void setDuration(const TimePeriod &duration);


    void setWeekday(const Weekday &weekday);
    const bool getWeekday() const;

private:

    TimePeriod startTime;
    TimePeriod duration;

    boost::gregorian::greg_weekday weekday;

    std::vector<Tag> tags;

};

bool operator<(const TimeslotRule& lhs, const TimeslotRule& rhs);

#endif //SCHEDULER_TIMESLOTRULE_H
