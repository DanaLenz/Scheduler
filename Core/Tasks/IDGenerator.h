//
// Created by Dana on 20.03.2020.
//

#ifndef SCHEDULER_IDGENERATOR_H
#define SCHEDULER_IDGENERATOR_H

#include <deque>

using ID = unsigned int;

class IDGenerator {

public:
    ID getID();

private:
    static std::deque<ID> idPool;
    unsigned int nextID;
    unsigned int lastID;
};


#endif //SCHEDULER_IDGENERATOR_H
