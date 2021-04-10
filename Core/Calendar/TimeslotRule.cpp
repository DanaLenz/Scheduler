//
// Created by dana on 16.06.20.
//

#include "TimeslotRule.h"


TimeslotRule::TimeslotRule(const Weekday &weekday, const TimeDefs::TimePeriod &startTime, const TimeDefs::TimePeriod &duration)
        : weekday{(unsigned short) weekday}, startTime{startTime}, duration{duration}  {}


bool operator<(const TimeslotRule& lhs, const TimeslotRule& rhs) {

    // sort by weekday first,
    // start time second
    // this is unique if there is no overlap

    if(lhs.getWeekday() != rhs.getWeekday())
        return lhs.getWeekday() < rhs.getWeekday();
    else
        return lhs.getStartTime() < rhs.getStartTime();

}

bool operator==(const TimeslotRule &lhs, const TimeslotRule &rhs) {
    return (lhs.getWeekday() == rhs.getWeekday()
        && lhs.getStartTime() == rhs.getStartTime());
}

const TimeDefs::TimePeriod &TimeslotRule::getStartTime() const {
    return startTime;
}

const TimeDefs::TimePeriod &TimeslotRule::getDuration() const {
    return duration;
}

const TimeDefs::Weekday TimeslotRule::getWeekday() const {
    return weekday;
}

void TimeslotRule::addTag(const std::string &tag) {
    tags.insert(tag);
}

void TimeslotRule::removeTag(const std::string &tag) {
    tags.erase(tag);
}

std::vector<std::string> TimeslotRule::getAllTags() {

    std::vector<std::string> result;
    for(const auto &el : tags)
        result.push_back(el);

    return result;
}
