//
// Created by dana on 16.06.20.
//

#ifndef SCHEDULER_TIMESLOTRULE_H
#define SCHEDULER_TIMESLOTRULE_H

#include "../Definitions.h"
#include "Timeslot.h"
#include <vector>

class TimeslotRule {

public:

    TimeslotRule(const Weekday &weekday, const TimePeriod &startTime, const TimePeriod &duration);

    //For Scheduler:
    [[nodiscard]] Timeslot createTimeslot(const Date& date) const;

    //For the Interface:
    [[nodiscard]] const TimePeriod &getStartTime() const;
    [[nodiscard]] const TimePeriod &getDuration() const;
    [[nodiscard]] const Weekday getWeekday() const;

private:

    TimePeriod startTime;
    TimePeriod duration;
    Weekday weekday;

//    std::vector<Tag> tags;

};

bool operator<(const TimeslotRule& lhs, const TimeslotRule& rhs);

#endif //SCHEDULER_TIMESLOTRULE_H
