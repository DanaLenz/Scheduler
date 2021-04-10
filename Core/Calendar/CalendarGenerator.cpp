//
// Created by Dana on 15.03.2020.
//


#include "CalendarGenerator.h"

TimeslotRule& CalendarGenerator::createTimeslotRule(const Weekday &weekday, const std::string start_time, const long duration) {


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
    TimeDefs::Weekday boost_weekday {(unsigned short) weekday};
    TimeDefs::TimePeriod boost_startTime = boost::posix_time::duration_from_string(start_time);
    TimeDefs::TimePeriod boost_duration {0, duration, 0, 0};

    TimeslotRule tsr {weekday, boost_startTime, boost_duration};

    size_t insert;

    for(insert = 0; insert < timeslotRules.size(); insert++) {

        auto &compare = timeslotRules.at(insert);

        if(compare.getWeekday() < boost_weekday)
            continue;
        /*
        //check overlap
        else if(compare.getWeekday() == boost_weekday) {
            if (compare.getStartTime() < boost_startTime &&
                compare.getStartTime() + compare.getDuration() > boost_startTime)
                //TODO: overlap!
                return timeslotRules.end();

            else if (compare.getStartTime() > boost_startTime &&
                boost_startTime + boost_duration > compare.getStartTime())
                return timeslotRules.end();

            else if (compare.getStartTime() == boost_startTime)
                    return timeslotRules.end();
        }*/
        else  // case: later weekday, position found
            break;
    }

    //TODO: this wont work if the position is at end of vector
    auto iter = timeslotRules.begin() + insert;
    auto ret = timeslotRules.emplace(iter, TimeslotRule {weekday, boost_startTime, boost_duration});

    return *ret;
}


void CalendarGenerator::deleteTimeslotRule(TimeslotRule &timeslotRule) {
    timeslotRules.erase(std::remove(timeslotRules.begin(), timeslotRules.end(), timeslotRule));
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

const std::map<std::string, Weekday> CalendarGenerator::weekdayStrings = {{"Sunday", Weekday::SUNDAY}, {"Monday", Weekday::MONDAY},
                                                      {"Tuesday", Weekday::TUESDAY}, {"Wednesday", Weekday::WEDNESDAY},
                                                      {"Thursday", Weekday::THURSDAY}, {"Friday", Weekday::FRIDAY},
                                                      {"Saturday", Weekday::SATURDAY}};

void CalendarGenerator::printRules() const {

    for(const auto &rule : timeslotRules) {
        std::cout << "New Rule: " << std::endl;
        std::cout << "Weekday: " << rule.getWeekday() << std::endl;
        std::cout << "Start Time: " << rule.getStartTime() << std::endl;
        std::cout << "Duration: " << rule.getDuration() << std::endl;
        std::cout << std::endl;
    }
}

std::vector<TimeslotRule *> CalendarGenerator::getTimeslotRules() {

    std::vector<TimeslotRule *> result;

    for(auto &tsr : timeslotRules) {
        result.push_back(&tsr);
    }

    return result;
}

TimeslotRule& CalendarGenerator::getReference(const TimeDefs::Weekday &weekday, const TimeDefs::TimePeriod &startTime) const {

    for(auto &tsr : timeslotRules)
        if(tsr.getWeekday() == weekday && tsr.getStartTime() == startTime)
            return const_cast<TimeslotRule &>(tsr); //this is bad. i am aware that this is bad.
}
