//
// Created by Dana on 15.03.2020.
//


#include "CalendarGenerator.h"

std::set<TimeslotRule>::const_iterator CalendarGenerator::createTimeslotRule(const unsigned short weekday_num, const long start_hour, const long start_minutes,
                                                          const long duration) {

   // if(weekday_num < 1 || weekday_num > 7)
        //TODO: Error: bad parameter
   // if (start_hour < 0 || start_hour > 23)
        //TODO: Error: bad parameter
   // if(start_minutes < 0 || start_minutes > 59)
        //TODO: Error: bad parameter
   // if(duration < 0)
        //TODO: Error: bad parameter
   // if(start_hour*60 + start_minutes + duration >= 24*60)
        //TODO: Error: timeslot going over midnight



    // Transform parameter types to internally used boost types
    TimeDefs::Weekday boost_weekday {weekday_num};
    TimeDefs::TimePeriod boost_startTime {start_hour, start_minutes, 0};
    TimeDefs::TimePeriod boost_duration {duration/60, duration%60, 0};

    auto emplace_return = timeslotRules.emplace(boost_weekday, boost_startTime, boost_duration);

    // Check for errors and overlap
   // if(!emplace_return.second)
        //TODO: Error: something has gone wrong when inserting
   // else {

        auto &position = emplace_return.first;

        if(position != timeslotRules.begin()) {
            auto previous = std::prev(position, 1);
            if (boost_weekday == previous->getWeekday())
                if (previous->getStartTime() + previous->getDuration() >= boost_startTime) {
                    //TODO: Error: overlap
                    timeslotRules.erase(position);
                }
        }

        if(std::next(position) != timeslotRules.end()) {
            auto next = std::next(position, 1);
            if (boost_weekday == next->getWeekday())
                if (boost_startTime + boost_duration >= next->getStartTime()) {
                    //TODO: Error: overlap
                    timeslotRules.erase(position);
                }
        }

    //}

    return emplace_return.first;
}


void CalendarGenerator::deleteTimeslotRule(TimeslotRule &timeslotRule) {
    timeslotRules.erase(timeslotRule);
}


Calendar CalendarGenerator::generateCalendar(const TimeDefs::Date &firstDay, const TimeDefs::Date &lastDay) const {

    auto calendar = new Calendar{firstDay, lastDay};

    if (timeslotRules.empty()) return *calendar;

    auto &day = firstDay;
    auto date_period = boost::gregorian::date_period(firstDay, lastDay);

    for(auto date = firstDay; date <= lastDay; date += boost::gregorian::date_duration(1)){

        for(auto &tsr : timeslotRules)
            if(tsr.getWeekday() == date.day_of_week())
                calendar->timeslots.emplace_back(date, tsr.getStartTime(), tsr.getDuration());
    }

    return *calendar;

    /*
     * In principle, the position of each timeslot in the internal array
     * can be calculated in the beginning.
     * However, that does not match the way vectors are intended to be
     * used and leads to unnecessarily messy code. Only
     * modify if this turns out to be a performance bottleneck.
     *
     *   for(auto &currDay = startDay; currDay <= lastDay; currDay += boost::gregorian::date_duration(7)){
     *      size_t number_added = 0;
     *      timeslots[index+(amount_timeslots*number_added)] = Timeslot(currDay, tsr.getStartTime(), tsr.getDuration());
     *      number_added++;
     *   }
     */

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