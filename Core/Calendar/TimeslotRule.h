//
// Created by dana on 16.06.20.
//

#ifndef SCHEDULER_TIMESLOTRULE_H
#define SCHEDULER_TIMESLOTRULE_H

#include "../Definitions.h"
#include "Timeslot.h"
#include <vector>
#include <set>

/**
 * Contains the rule to generate one timeslot per week.
 */
class TimeslotRule {

public:

    /**
     * Time slot rules contain the information needed to generate a timeslot each week.
     * Needs to be initialized with a weekday, start time and duration.
     * A timeslot needs to be contained inside a single day.
     */
    TimeslotRule(const Weekday &weekday, const TimeDefs::TimePeriod &startTime, const TimeDefs::TimePeriod &duration);

    /**
     * @return Start time of the time slot rule
     */
    [[nodiscard]] const TimeDefs::TimePeriod &getStartTime() const;
    /**
     * @return Duration of the time slot rule
     */
    [[nodiscard]] const TimeDefs::TimePeriod &getDuration() const;
    /**
     * @return Weekday of the time slot rule
     */
    [[nodiscard]] const TimeDefs::Weekday getWeekday() const;

    /**
     * Tags are implemented as simple strings.
     * This should only be called by TagManager.
     * @param tag A string that should be taken from TagManager.getAllTags()
     */
    void addTag(const std::string &tag);

    /**
     * Remove tag from the list of associated tags. This
     * should only be called by TagManager.
     * @param tag
     * @return
     */
    void removeTag(const std::string &tag);


    [[nodiscard]] std::vector<std::string> getAllTags();


private:

    TimeDefs::TimePeriod startTime;
    TimeDefs::TimePeriod duration;
    TimeDefs::Weekday weekday;

    std::set<std::string> tags;

};

bool operator<(const TimeslotRule& lhs, const TimeslotRule& rhs);

bool operator==(const TimeslotRule& lhs, const TimeslotRule& rhs);

#endif //SCHEDULER_TIMESLOTRULE_H
