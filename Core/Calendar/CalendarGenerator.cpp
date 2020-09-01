//
// Created by Dana on 15.03.2020.
//

#include "CalendarGenerator.h"


void CalendarGenerator::createTimeslotRule(std::string weekday_str, float startTime, size_t duration) {

    timeslotRules.emplace();
}

void CalendarGenerator::deleteTimeslotRule(TimeslotRule &timeslotRule) {
    timeslotRules.erase(timeslotRule);
}

//TODO: In CalendarGenerator: Is there a more organic way to iterate over a date period?
Calendar* CalendarGenerator::generateCalendar(const Date &firstDay, const Date &lastDay) {

    Calendar* calendar_ptr = new Calendar{firstDay, lastDay};

    if (timeslotRules.empty()) return calendar_ptr;

    for(Date currDay = firstDay; currDay <= lastDay; currDay += boost::gregorian::date_duration(1))
        for(auto &tsr : timeslotRules)
            calendar_ptr->appendTimeslot(tsr, currDay);


 /*   //there is a set number of tsr, each creating exactly one timeslot
    //they are ordered
    //so can calculate in advance which positions which timeslots will have

    size_t offset = 0;
    size_t tsr_size = timeslotRules.size();

    for(auto &tsr : timeslotRules) {

        Date nextDate = firstDay;
        size_t nextPosition = offset;

        while(nextDate <= lastDay) {
            calendar_ptr->appendTimeslot(tsr, nextDate);
            nextPosition += tsr_size;
            nextDate += boost::gregorian::date_duration(1);
        }

        offset++;

 */   }

}
