//
// Created by Dana on 15.03.2020.
//


#include "CalendarGenerator.h"

void CalendarGenerator::createTimeslotRule(const unsigned short weekday_num, const long start_hour, const long start_minutes,
                                           const long duration) {
    TimeDefs::Weekday boost_weekday {weekday_num};
    TimeDefs::TimePeriod boost_startTime {start_hour, start_minutes, 0};
    TimeDefs::TimePeriod boost_duration {duration/60, duration%60, 0};
    timeslotRules.emplace(boost_weekday, boost_startTime, boost_duration);
}


void CalendarGenerator::deleteTimeslotRule(TimeslotRule &timeslotRule) {
    timeslotRules.erase(timeslotRule);
}


//TODO: In CalendarGenerator: Is there a more organic way to iterate over a date period?
Calendar CalendarGenerator::generateCalendar(const TimeDefs::Date &firstDay, const TimeDefs::Date &lastDay) const {

    auto calendar = new Calendar{firstDay, lastDay};

    if (timeslotRules.empty()) return *calendar;

     // time slot rules are sorted
     // calculate the right index for a time slot based on the number of time slot rules
     // and instances added
     const size_t amount_timeslots = timeslotRules.size();
     size_t index = 0;                                          // counts
     std::vector<Timeslot> timeslots;
     for(auto &tsr : timeslotRules) {

         //find start day
         auto startDay = firstDay;
         for(size_t i = 1; i < 7; i++){
             if(tsr.getWeekday() == startDay.day_of_week())
                 break;
             else
                 startDay = startDay + boost::gregorian::date_duration(1);
         }

         //TODO: messy loop with 3 manual counters
         size_t offset = 0;
         for(auto &currDay = startDay; currDay <= lastDay; currDay += boost::gregorian::date_duration(7)){
            size_t number_added = 0;
            timeslots[index+(offset*number_added)] = Timeslot(currDay, tsr.getStartTime(), tsr.getDuration());
            offset++;
            number_added++;
         }

         index++;
     }
    calendar->timeslots = timeslots;

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