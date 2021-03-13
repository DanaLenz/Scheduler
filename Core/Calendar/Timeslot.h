//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_TIMESLOT_H
#define SCHEDULER_TIMESLOT_H

#include "../Definitions.h"

/**
 * In general, a timeslot is a single instance of a timeslot-
 * rule, defining a single, concrete period of time that can be assigned a task.
 */
class Timeslot {

public:

    /**
     * A date, start time and duration are required to define a time slot.
     * @param date Date the time slot starts (and usually ends) on
     * @param startTime Time the time slot starts on
     * @param duration Duration of the time slot
     */
    Timeslot(const TimeDefs::Date &date, const TimeDefs::TimePeriod &startTime, const TimeDefs::TimePeriod &duration);

    /**
     * @return Starting time of the time slot
     */
    [[nodiscard]] const TimeDefs::TimePeriod &getStartTime() const;

    /**
     * @return Duration of the time slot
     */
    [[nodiscard]] const TimeDefs::TimePeriod &getDuration() const;

    /**
     * @return (Starting) Date of the time slot
     */
    [[nodiscard]] const TimeDefs::Date &getDate() const;


private:

    TimeDefs::Date date;

    TimeDefs::TimePeriod startTime;
    TimeDefs::TimePeriod duration;

    //std::vector<Tag> tags;
};

bool operator<(const Timeslot& lhs, const Timeslot& rhs);

#endif //SCHEDULER_TIMESLOT_H
