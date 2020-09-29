//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_TIMESLOT_H
#define SCHEDULER_TIMESLOT_H

#include "../Tasks/Task.h"
#include "../Definitions.h"

class Timeslot {

public:

    Timeslot(const Date &date, const TimePeriod &startTime, const TimePeriod &duration);

    void assign(Task &task);

    [[nodiscard]] bool isAssigned() const;
    void unassign();

    [[nodiscard]] const TimePeriod &getStartTime() const;
    void setStartTime(const TimePeriod &startTime);

    [[nodiscard]] const TimePeriod &getDuration() const;
    void setDuration(const TimePeriod &duration);

    [[nodiscard]] const Date &getDate() const;
    void setDate(const Date &date);

private:

    Date date;

    TimePeriod startTime;
    TimePeriod duration;

    //std::vector<Tag> tags;
    Task* assignedTask = nullptr;
};

bool operator<(const Timeslot& lhs, const Timeslot& rhs);

#endif //SCHEDULER_TIMESLOT_H
