//
// Created by Dana on 20.03.2020.
//

#include "IDGenerator.h"

ID IDGenerator::getID() {

    unsigned int id;
    if(!idPool.empty()) {
        id = idPool.back();
        idPool.pop_back();
    }

    id = nextID++;
    lastID = id;
    return id;
}
