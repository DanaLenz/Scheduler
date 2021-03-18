//
// Created by dana on 22.07.20.
//

#ifndef SCHEDULER_DEFINITIONS_H
#define SCHEDULER_DEFINITIONS_H

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

    using Priority = int;

namespace TimeDefs {

    using Date = boost::gregorian::date;
    using DatePeriod = boost::gregorian::date_period;
    using DateDuration = boost::gregorian::date_duration;

    using Weekday = boost::gregorian::greg_weekday;

    using TimePoint = boost::posix_time::ptime;
    using TimePeriod = boost::posix_time::time_duration;
}

#endif //SCHEDULER_DEFINITIONS_H
