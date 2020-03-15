#include <iostream>
#include "Core/Project.h"

int main() {
    //TODO: the way of creating and accessing tasks needs to be different
    Project p;

    auto ptr = p.createTask();
    ptr->setName("Release the Ducks");

    ptr = p.createTask();
    ptr->setName("Summon");

    for (const Task& t: p.associatedTasks) {
        std::cout << t.getName() << std::endl;
    }

    p.removeTask(*ptr);

    for (const Task& t: p.associatedTasks) {
        std::cout << t.getName() << std::endl;
    }

    std::cout << "Done!" << std::endl;
    return 0;
}