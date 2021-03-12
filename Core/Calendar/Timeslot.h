//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_TIMESLOT_H
#define SCHEDULER_TIMESLOT_H

#include "../Tasks/Task.h"
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
     * @param task Task to be assigned
     */
    void assign(Task &task);

    /**
     * @return True iff a task is assigned to this time slot
     */
    [[nodiscard]] bool isAssigned() const;
    /**
     * Removes assigned task.
     * (This does not change anything in the task.)
     */
    void unassign();

    /**
     * @return Starting time of the time slot
     */
    [[nodiscard]] const TimeDefs::TimePeriod &getStartTime() const;
    /**
     * @param startTime Starting time of the time slot
     */
    void setStartTime(const TimeDefs::TimePeriod &startTime);

    /**
     * @return Duration of the time slot
     */
    [[nodiscard]] const TimeDefs::TimePeriod &getDuration() const;
    /**
     * @param duration Duration of the time slot
     */
    void setDuration(const TimeDefs::TimePeriod &duration);

    /**
     * @return (Starting) Date of the time slot
     */
    [[nodiscard]] const TimeDefs::Date &getDate() const;
    /**
     * @param date (Starting) Date of the time slot
     */
    void setDate(const TimeDefs::Date &date);

private:

    TimeDefs::Date date;

    TimeDefs::TimePeriod startTime;
    TimeDefs::TimePeriod duration;

    //std::vector<Tag> tags;
    Task* assignedTask = nullptr;
};

bool operator<(const Timeslot& lhs, const Timeslot& rhs);

#endif //SCHEDULER_TIMESLOT_H
