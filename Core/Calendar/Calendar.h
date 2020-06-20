//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_CALENDAR_H
#define SCHEDULER_CALENDAR_H

#include <set>
#include <vector>
#include "Timeslot.h"

class Calendar {

public:

    Timeslot& createTimeslot(boost::posix_time::ptime startTime,
                        boost::posix_time::time_period duration);
    void deleteTimeslot(Timeslot& timeslot);

    //use timeslotRules to create all timeslots up to and including a certain date
    void createUntil(boost::gregorian::date);

private:

    std::vector<TimeslotRule> timeslotRules;
    std::set<Timeslot> timeslots;
};


#endif //SCHEDULER_CALENDAR_H
