#include <iostream>
#include "Core/Project.h"
#include "Core/TaskManager.h"
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


    consoleUI::printTasks(tm);

    for(auto p = tm->iteratorProjectsBegin();
        p == tm->iteratorProjectsEnd();
        p++) {
        std::cout << p->getName() << std::endl;
    }

    std::cout << "Done!" << std::endl;
    return 0;
}