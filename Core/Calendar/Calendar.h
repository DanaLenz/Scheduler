//
// Created by dana on 29.08.20.
//

#ifndef SCHEDULER_CALENDAR_H
#define SCHEDULER_CALENDAR_H

#include "../Definitions.h"
#include "Timeslot.h"
#include "TimeslotRule.h"
#include <vector>

class CalendarGenerator;

/**
 * A calendar is effectively a collection of Timeslots.
 * While timeslots can be manually added or deleted, most of them
 * should be added during creation by the CalendarGenerator.
 *
 */
class Calendar {

    friend CalendarGenerator;

public:

    /**
     * Creates a calendar with a start and end date - only values between
     * those dates will be valid for time slots.
     * @param firstDay First date of the calendar
     * @param lastDay Last date of the calendar
     */
    Calendar(const TimeDefs::Date &firstDay, const TimeDefs::Date &lastDay);


    /**
     * Deletes the saved timeslots, but does not change
     * start end end date
     */
    void clear();


    /**
     * Currently unused!
     * Appends a timeslot at the end of the internal vector,
     * currently subject to redesign
     */
    //void appendTimeslot(const TimeslotRule &tsr, const TimeDefs::Date &date);


    /**
     * Currently unused!
     * Creates a timeslot and stores it at the appropriate spot in
     * the internal sorted collection.
     * Needs to perform a search, so this should only be used
     * for individual time slots added after calendar creation.
     * @param date Date of the time slot; for multi-day timeslot first day
     * @param startTime Start time of the time slot
     * @param duration Duration of the time slot
     * (not yet implemented: ensuring no overlapping timeslots can be added)
     */
    //void createTimeslot(const TimeDefs::Date &date, const TimeDefs::TimePeriod &startTime,
    //        const TimeDefs::TimePeriod &duration);

    /**
     * Delete an individual time slot from a calendar
     * @param it iterator to the time slot to be deleted
     */
    void deleteTimeslot(std::vector<Timeslot>::iterator it);

    // print functions for debugging
    /**
     * Print calendar info, except for the list of timeslots
     * currently only start and end date
     */
    void printInfo() const;
    /**
     * Print all held time slots
     * They are (should be?) ordered
     */
    void printTimeslots() const;

private:

    //TODO: guarantee that all timeslots are between start & end date
    //TODO: timeslots need to be guaranteed to be sorted
    std::vector<Timeslot> timeslots;

    const TimeDefs::Date startDate;
    const TimeDefs::Date endDate;

    };


#endif //SCHEDULER_CALENDAR_H
