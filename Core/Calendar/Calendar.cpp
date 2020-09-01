//
// Created by dana on 29.08.20.
//

#include "Calendar.h"

Calendar::Calendar(const Date &firstDay, const Date &lastDay) : startDate{firstDay}, endDate{lastDay} {

    assert(startDate <= endDate &&
            "First date of a calendar is past it's last date.");
}

void Calendar::clear() {

    timeslots.clear();

}

void Calendar::createTimeslot(const Date &date, const TimePeriod &startTime, const TimePeriod &duration) {

    //TODO: check overlap
    //TODO: is there a std function doing this?

    if(date < startDate || date > endDate) {
        //TODO: Error: outside of calendar range
        return;
    }

    for(std::vector<Timeslot>::const_iterator it = timeslots.begin(); it != timeslots.end(); ++it) {
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

void Calendar::deleteTimeslot(Timeslot &timeslot) {
    timeslots.erase(std::remove(timeslots.begin(), timeslots.end(), timeslot));
}

void Calendar::appendTimeslot(const TimeslotRule &tsr, const Date &date) {
    timeslots.push_back(std::move(tsr.createTimeslot(date)));
}

