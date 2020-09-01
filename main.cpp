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

    auto dance = tm->createTask("Dance Numbers");
    auto release = tm->createTask("Release the Ducks", ducks);
    auto summon = tm->createTask("Summon", ducks);
    auto pet = tm->createTask("Pet my Roomba", roombas);
    auto empower = tm->createTask("Appease Roomba Superintelligence", roombas);
    auto laser = tm->createTask("Put laser on Roomba", roombas);


    CalendarGenerator calendar{};
    calendar.createTimeslotRule('wednesday', 16, 30);
    calendar.createTimeslotRule('friday 2', 13.15, 90);
    calendar.createTimeslotRule('monday tuesday 2', 14, 120);
    calendar.createTimeslots(30);
    calendar.printTimeslots();

    //priorityQ.oder();
    //scheduler.schedule();

    return 0;
}