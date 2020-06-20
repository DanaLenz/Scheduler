//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_TIMESLOT_H
#define SCHEDULER_TIMESLOT_H

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "../Tasks/Task.h"
#include "Tag.h"

class Timeslot {
    //TODO: read boost datetime documentation

public:
    //TODO: multiple tasks per slot
    void assign(Task& task);
    bool isAssigned() const;
    void unassign();

    explicit Timeslot(boost::posix_time::ptime startTime,
                      boost::posix_time::time_period duration);

    const boost::posix_time::ptime &getStartTime() const;

    void setStartTime(const boost::posix_time::ptime &startTime);

    const boost::posix_time::time_period &getDuration() const;

    void setDuration(const boost::posix_time::time_period &duration);

private:

    boost::posix_time::ptime startTime;
    boost::posix_time::time_period duration;

    //std::unordered_set<Tag> tags;
    Task* assignedTask = nullptr;
};

bool operator<(const Timeslot& lhs, const Timeslot& rhs);

#endif //SCHEDULER_TIMESLOT_H
