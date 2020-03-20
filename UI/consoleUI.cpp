//
// Created by Dana on 19.03.2020.
//

#include "consoleUI.h"
#include <iostream>


void consoleUI::printTasks(TaskManager *taskManager) {
    for(auto p = taskManager->iteratorProjectsBegin();
             p == taskManager->iteratorProjectsEnd();
             p++)
    {
        std::cout << p->getName() << std::endl;
    }
}
