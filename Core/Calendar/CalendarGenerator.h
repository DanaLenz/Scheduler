//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_CALENDARGENERATOR_H
#define SCHEDULER_CALENDARGENERATOR_H

#include <set>
#include <vector>
#include "Timeslot.h"
#include "Definitions.h"
#include "TimeslotRule.h"
#include "Calendar.h"

class CalendarGenerator {

public:

    Calendar* generateCalendar(const Date &startDate, const Date &endDate);
    void createTimeslotRule(std::string weekday_str, float startTime, size_t duration);
    void deleteTimeslotRule(TimeslotRule& timeslotRule);

private:

    std::set<TimeslotRule> timeslotRules;
};


#endif //SCHEDULER_CALENDARGENERATOR_H
