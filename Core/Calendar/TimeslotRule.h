//
// Created by dana on 16.06.20.
//

#ifndef SCHEDULER_TIMESLOTRULE_H
#define SCHEDULER_TIMESLOTRULE_H

#include "../Definitions.h"
#include "Timeslot.h"
#include <vector>

/**
 * Contains the rule to generate one timeslot per week.
 */
class TimeslotRule {

public:

    /**
     * Time slot rules contain the information needed to generate a timeslot each week.
     * Needs to be initialized with a weekday, start time and duration.
     * A timeslot needs to be contained inside a single day.
     */
    TimeslotRule(const Weekday &weekday, const TimeDefs::TimePeriod &startTime, const TimeDefs::TimePeriod &duration);

    /**
     * @return Start time of the time slot rule
     */
    [[nodiscard]] const TimeDefs::TimePeriod &getStartTime() const;
    /**
     * @return Duration of the time slot rule
     */
    [[nodiscard]] const TimeDefs::TimePeriod &getDuration() const;
    /**
     * @return Weekday of the time slot rule
     */
    [[nodiscard]] const TimeDefs::Weekday getWeekday() const;

private:

    TimeDefs::TimePeriod startTime;
    TimeDefs::TimePeriod duration;
    TimeDefs::Weekday weekday;

//    std::vector<Tag> tags;

};

bool operator<(const TimeslotRule& lhs, const TimeslotRule& rhs);

bool operator==(const TimeslotRule& lhs, const TimeslotRule& rhs);

#endif //SCHEDULER_TIMESLOTRULE_H
