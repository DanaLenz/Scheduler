//
// Created by dana on 29.08.20.
//

#include "Calendar.h"
#include <algorithm>

Calendar::Calendar(const TimeDefs::Date &firstDay, const TimeDefs::Date &lastDay) : startDate{firstDay}, endDate{lastDay} {

    assert(startDate <= endDate &&
            "First date of a calendar is past it's last date.");

    assert(!startDate.is_not_a_date() &&
            "Start Date is not a date.");

    assert(!endDate.is_not_a_date() &&
           "End Date is not a date.");
}

void Calendar::clear() {
    timeslots.clear();
}


void Calendar::deleteTimeslot(std::vector<Timeslot>::iterator it) {
    timeslots.erase(it);
}


void Calendar::printInfo() const {

    //std::cout << startDate.day_count() << std::endl;
    //assert(!startDate.is_not_a_date() && "StartDate not a date.");

    std::cout << "Calendar Information: " << std::endl;
    std::cout << "Start Date: " << startDate << std::endl;
    std::cout << "End Date: " << endDate << std::endl;
    std::cout << std::endl;

}

void Calendar::printTimeslots() const {

    std::cout << "Timeslots:" << std::endl;
    std::cout << std::endl;

    for(auto& ts : timeslots) {
        std::cout << "Date: " << ts.getDate() << std::endl;
        std::cout << "Weekday: " << ts.getDate().day_of_week() << std::endl;
        std::cout << "Start: " << ts.getStartTime() << std::endl;
        std::cout << "Duration: " << ts.getDuration() << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;

}

/*
void Calendar::appendTimeslot(const TimeslotRule &tsr, const TimeDefs::Date &date) {
    timeslots.push_back(std::move(tsr.createTimeslot(date)));
}
 */

/*
void Calendar::createTimeslot(const TimeDefs::Date &date, const TimeDefs::TimePeriod &startTime, const TimeDefs::TimePeriod &duration) {

    //TODO: check overlap
    //TODO: is there a std function doing this?

    if(date < startDate || date > endDate) {
        //TODO: Error: outside of calendar range
        return;
    }

    for(auto it = timeslots.begin(); it != timeslots.end(); ++it) {
        if(it->getDate() >= date)
            if(it->getStartTime() >= startTime){
                if(startTime < (it->getStartTime() + it->getDuration())
                    || (it + 1)->getStartTime() < (startTime + duration))
                {
                    //TODO: Error, timeslot overlap
                    return;
                }
                timeslots.insert(++it, Timeslot{date, startTime, duration});
                return;
            }
    }

    timeslots.emplace_back(date, startTime, duration);

}
*/