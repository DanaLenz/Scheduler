//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_TIMESLOT_H
#define SCHEDULER_TIMESLOT_H

//#include "boost/date_time/gregorian/gregorian.hpp"
//#include "boost/date_time/posix_time/posix_time.hpp"
#include "Task.h"
#include "Tag.h"

class Timeslot {
    //TODO: read boost datetime documentation

public:
    //TODO: multiple tasks per slot
    Timeslot* assignTimeslot(const Task& task);
    bool isAssigned();

private:
    //boost::posix_time::time_duration length;
    //boost::posix_time::time_duration buffer = 0;
    std::unordered_set<Tag> tags;
};


#endif //SCHEDULER_TIMESLOT_H
