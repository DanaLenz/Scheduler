#include <iostream>
#include "Core/Tasks/Project.h"
#include "Core/Tasks/TaskManager.h"
#include "UI/consoleUI.h"

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
    auto empower = tm->createTask("Empower Roombas", roombas);
    auto laser = tm->createTask("Put laser on Roomba", roombas);

    tm->testPrint();

    tm->transferTask(summon, roombas);
    tm->transferTask(pet);

    tm->testPrint();

    tm->deleteProject(ducks);

    tm->testPrint();

    return 0;
}