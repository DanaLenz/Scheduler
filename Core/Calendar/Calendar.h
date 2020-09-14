//
// Created by dana on 29.08.20.
//

#ifndef SCHEDULER_CALENDAR_H
#define SCHEDULER_CALENDAR_H

#include "Definitions.h"
#include "Timeslot.h"
#include "TimeslotRule.h"
#include <vector>

class CalendarGenerator;

class Calendar {

    friend CalendarGenerator;

public:

    Calendar(const Date &firstDay, const Date &lastDay);

    // deletes the saved timeslots
    // does not reset or modify startDate and endDate
    void clear();

    // adds exactly one new timeslot at the end of the calendar,
    // as speficied by the passed timeslot-rule
    // the standard way to add timeslots
    void appendTimeslot(const TimeslotRule &tsr, const Date &date);

    // manually creates and inserts a timeslot
    // needs to search for the appropritate position
    void createTimeslot(const Date &date, const TimePeriod &startTime, const TimePeriod &duration);

    // TODO: In Calendar: delete function taking an iterator
    // removes one specified timeslot from the calendar
    void deleteTimeslot(std::vector<Timeslot>::iterator);

    // print functions for debugging
    void printInfo() const;
    void printTimeslots() const;

private:

    //TODO: guarantee that all timeslots are between start & end date
    //TODO: timeslots need to be guaranteed to be sorted
    std::vector<Timeslot> timeslots;

    Date startDate;
    Date endDate;

    };


#endif //SCHEDULER_CALENDAR_H
