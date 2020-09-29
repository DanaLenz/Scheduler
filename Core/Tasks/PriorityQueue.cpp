/*


//
// Created by dana on 15.09.20.
//

#include "../Definitions.h"
#include "PriorityQueue.h"
#include <algorithm>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/date_clock_device.hpp>


//----------------------------------------------------------------------------------------------------
//
//                  deprecated/unused functions
//
//----------------------------------------------------------------------------------------------------



ID PriorityQueue::getNextTask() const {
    return nextTask;
}

void PriorityQueue::reset() {
    nextTask = *idQueue.begin();
}

void PriorityQueue::addTask(const ID &taskID) {
    auto pos = findPosition(taskID);
    idQueue.insert(pos, taskID);
}

void PriorityQueue::removeTask(const ID &taskID) {
    idQueue.erase(std::remove(idQueue.begin(), idQueue.end(), taskID), idQueue.end());
}

void PriorityQueue::clear() {

    idQueue.clear();
}

float weightedPriority(const ID &id) {

    //TODO: priority weights should be manually set, not hardcoded inside a function
    //TODO: this function is ugly and terrible

    float deadlineDistanceWeight = 2;
    float projectPriorityWeight = 1;
    float taskPriorityWeight = 0.5;

    auto task = taskMap.at(id);

    auto today = boost::gregorian::day_clock::local_day();
    auto daysUntilDeadline = (task->getDeadline() - today).days();

    //TODO: the way to access a project from a task ID is cumbersome, if TaskManager won't be changed add access function
    int lhPriority = task.getPriority() * taskPriorityWeight
                     + tm->getProject(tm->getAssignedProject(id)).getPriority() * projectPriorityWeight
                     + daysUntilDeadline * deadlineDistanceWeight
                     ;
}

bool weightedCompare(const ID &lh, const ID &rh) {

    return (weightedPriority(lh) < weightedPriority(rh));
}

bool PriorityQueue::isOrdered() const {

    for(auto it = idQueue.begin(); it+1 != idQueue.end(); ++it)
        if(!weightedCompare(*it,*(it+1)))
            return false;

     return true;
}

void PriorityQueue::order() {

    std::sort(idQueue.begin(), idQueue.end(), weightedCompare);
}

std::vector<ID>::const_iterator PriorityQueue::findPosition(const ID &id) const {
    return std::vector<ID>::iterator();
}

void PriorityQueue::testPrint() const {

    std::cout << "TEST PRINT: PriorityQueue"
    for(const auto &id : idQueue)
        std::cout << "ID: " << id << ", Priority: " << weightedPriority(id) << std::endl;

    std::cout << "END TEST PRINT" << std::endl;
    std::cout << std::endl;
}


void PriorityQueue::addTasks(const ID &projectID) {

    auto tm = TaskManager::getTaskManager();
    for(const auto taskID : tm->getAssociatedTasks(projectID))
        addTask(taskID);
}

void PriorityQueue::removeTasks(const ID &projectID) {

    auto tm = TaskManager::getTaskManager();
    for(const auto taskID : tm->getAssociatedTasks(projectID))
        removeTask(taskID);
}

 */

