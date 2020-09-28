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
    IDGenerator();
    void releaseID(ID);

private:
    std::deque<ID> idPool = {};
    ID nextID = 0;
    ID lastID = 0;
};


#endif //SCHEDULER_IDGENERATOR_H
