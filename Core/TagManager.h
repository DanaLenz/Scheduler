//
// Created by dana on 09.04.21.
//

#ifndef SCHEDULER_TAGMANAGER_H
#define SCHEDULER_TAGMANAGER_H

#include <map>
#include <vector>

#include "Tasks/Task.h"
#include "Calendar/TimeslotRule.h"
#include "Tasks/TaskManager.h"
#include "Calendar/CalendarGenerator.h"

class TagManager {

public:

    TagManager(const TaskManager &tm, const CalendarGenerator &cal);

    bool addTag(const std::string &name);
    bool deleteTag(const std::string &name);

    [[nodiscard]] std::vector<std::string> getAllTags() const;

    [[nodiscard]] std::vector<ID> getTasksOfTag(const std::string &name) const;
    [[nodiscard]] std::vector<TimeslotRule*> getTimeslotsOfTag(const std::string &name) const;

    void addTag(ID task, const std::string &tag);
    void addTag(TimeslotRule &tsr, const std::string &tag);

    void removeTag(const Task &task, const std::string &tag);
    void removeTag(const TimeslotRule &tsr, const std::string &tag);

private:

    const TaskManager &taskManager;
    const CalendarGenerator &calendarGenerator;

    std::map<std::string, std::vector<ID>> tagTaskAssignment;
    std::map<std::string, std::vector<std::pair<TimeDefs::Weekday, TimeDefs::TimePeriod>>> tagTimeslotAssignment;

};


#endif //SCHEDULER_TAGMANAGER_H
