//
// Created by dana on 03.10.20.
//

#ifndef SCHEDULERQUICKINTERFACE_TASKRULE_H
#define SCHEDULERQUICKINTERFACE_TASKRULE_H


#include "../Definitions.h"
#include "Task.h"

/**
 * Defines the types of recurrence patterns that are possible for tasks.
 * When defining a new pattern, it has to be added in the generateEncodings() function.
 *
 * X_IN_WEEK: Do a task X times in week, e.g. exercise twice a week. To set the amount, use the variable xtimes.
 * EVERY_X_DAYS: (e.g. "Do Laundry" every 4 days. To set the interval, use the variable everyXDays.
 * INFINITE: A task that should be scheduled when free time is left, e.g. "Review Notes". A task of this type
 * can not have a deadline and will be the lowest priority.
 */
enum class RecurrenceType {
    INFINITE, X_IN_WEEK, EVERY_X_DAYS
};

/**
 * Defines the types of deadlines that can be generated for a task of this rule.
 *
 * ABSOLUTE: All tasks generated from this rule will have the date stored in
 * RELATIVE:
 * NONE: No deadline.
 */
enum class DeadlineType {
    ABSOLUTE, RELATIVE, NONE
};

class TaskRule : public Task {

    friend class TaskManager;

private:

    TimeDefs::Date startDate;
    TimeDefs::Date endDate;
    RecurrenceType recurrenceType;

    //type 2: x in a week
    size_t xtimes;

    //type 3: every x days
    TimeDefs::DateDuration everyXDays;

    DeadlineType deadlineType;

    TimeDefs::Date absoluteDeadline;
    TimeDefs::DateDuration relativeDeadline;


public:

    static const std::map<std::string, RecurrenceType> recurrenceTypeStrings;

    explicit TaskRule (std::string name);

    const TimeDefs::Date &getStartDate() const;

    void setStartDate(const TimeDefs::Date &startDate);

    const TimeDefs::Date &getEndDate() const;

    void setEndDate(const TimeDefs::Date &endDate);

    RecurrenceType getRecurrenceType() const;

    void setRecurrenceType(RecurrenceType recurrenceType);

    size_t getXtimes() const;

    void setXtimes(size_t xtimes);

    const TimeDefs::DateDuration &getEveryXDays() const;

    void setEveryXDays(const TimeDefs::DateDuration &everyXDays);

    const std::string &getName1() const;

    void setName1(const std::string &name);

    float getNeededTime1() const;

    void setNeededTime1(float neededTime);

    bool isProjectDependant1() const;

    void setProjectDependant1(bool projectDependant);

    bool isOptional1() const;

    void setOptional1(bool optional);

    DeadlineType getDeadlineType() const;

    void setDeadlineType(DeadlineType deadlineType);

    const TimeDefs::Date &getAbsoluteDeadline() const;

    void setAbsoluteDeadline(const TimeDefs::Date &absoluteDeadline);

    const TimeDefs::DateDuration &getRelativeDeadline() const;

    void setRelativeDeadline(const TimeDefs::DateDuration &relativeDeadline);

};


#endif //SCHEDULERQUICKINTERFACE_TASKRULE_H
