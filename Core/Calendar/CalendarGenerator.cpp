//
// Created by Dana on 15.03.2020.
//

#include "CalendarGenerator.h"

void CalendarGenerator::createTimeslotRule(const unsigned short weekday_num, const long start_hour, const long start_minutes,
                                           const long duration) {
    Weekday boost_weekday {weekday_num};
    TimePeriod boost_startTime {start_hour, start_minutes, 0};
    TimePeriod boost_duration {duration/60, duration%60, 0};
    timeslotRules.emplace(boost_weekday, boost_startTime, boost_duration);
}


void CalendarGenerator::deleteTimeslotRule(TimeslotRule &timeslotRule) {
    timeslotRules.erase(timeslotRule);
}


//TODO: In CalendarGenerator: Is there a more organic way to iterate over a date period?
Calendar CalendarGenerator::generateCalendar(const Date &firstDay, const Date &lastDay) const {

    auto calendar = new Calendar{firstDay, lastDay};

    if (timeslotRules.empty()) return *calendar;

    for(Date currDay = firstDay; currDay <= lastDay; currDay += boost::gregorian::date_duration(1))
        for(auto &tsr : timeslotRules)
            if(tsr.getWeekday() == currDay.day_of_week())
                calendar->appendTimeslot(tsr, currDay);

     return *calendar;
}

void CalendarGenerator::printRules() const {

    for(const auto &rule : timeslotRules) {
        std::cout << "New Rule: " << std::endl;
        std::cout << "Weekday: " << rule.getWeekday() << std::endl;
        std::cout << "Start Time: " << rule.getStartTime() << std::endl;
        std::cout << "Duration: " << rule.getDuration() << std::endl;
        std::cout << std::endl;
    }
}