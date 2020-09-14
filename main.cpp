#include <iostream>
#include "Core/Tasks/Project.h"
#include "Core/Tasks/TaskManager.h"
#include "UI/consoleUI.h"
#include "Core/Calendar/CalendarGenerator.h"

#include "boost/date_time/gregorian/gregorian.hpp"

int main() {
    //TODO: FIRST: redesign
    //TODO: include tests
    //TODO: look at similar open-source programs to get better ideas
    //TODO: the way of creating and accessing tasks needs to be different
    TaskManager* tm = TaskManager::getTaskManager();

    auto ducks = tm->createProject("Ducks");
    auto roombas = tm->createProject("Roombas");

    auto dance = tm->createTask("make your statement, face your fear");
    auto release = tm->createTask("release the ducks", ducks);
    auto summon = tm->createTask("dummon", ducks);
    auto pet = tm->createTask("put laser on roomba", roombas);
    auto empower = tm->createTask("appease superintelligence", roombas);


    CalendarGenerator cG{};
    cG.createTimeslotRule(3, 16, 0, 30);
    cG.createTimeslotRule(5, 13, 15, 90);
    cG.createTimeslotRule(4, 14, 45, 120);
    cG.createTimeslotRule(4, 11, 0, 30);
    cG.printRules();
    Calendar calendar = cG.generateCalendar(boost::gregorian::date(2021, 01,01), boost::gregorian::date(2021, 01, 07));
    calendar.printTimeslots();

    //priorityQ.order();
    //scheduler.schedule();

    return 0;
}