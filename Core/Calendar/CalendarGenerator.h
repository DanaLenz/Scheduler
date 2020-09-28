//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_CALENDARGENERATOR_H
#define SCHEDULER_CALENDARGENERATOR_H

#include <set>
#include <vector>
#include "Timeslot.h"
#include "../Definitions.h"
#include "TimeslotRule.h"
#include "Calendar.h"

class CalendarGenerator {

public:

    Calendar generateCalendar(const Date &startDate, const Date &endDate) const;
    void createTimeslotRule(const unsigned short weekday_num, const long start_hour, const long start_minutes, const long duration);
    void deleteTimeslotRule(TimeslotRule& timeslotRule);
    void printRules() const;

private:

    std::set<TimeslotRule> timeslotRules;
};


#endif //SCHEDULER_CALENDARGENERATOR_H
