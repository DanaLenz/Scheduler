//
// Created by Dana on 20.03.2020.
//

#include "IDGenerator.h"

ID IDGenerator::getID() {

    unsigned int id;
    if(!idPool.empty()) {
        id = idPool.back();
        idPool.pop_back();
    } else
        id = nextID++;

    return id;
}

void IDGenerator::releaseID(ID id) {
    idPool.push_back(id);
}

