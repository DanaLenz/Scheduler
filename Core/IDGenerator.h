//
// Created by Dana on 20.03.2020.
//

#ifndef SCHEDULER_IDGENERATOR_H
#define SCHEDULER_IDGENERATOR_H

#include <deque>

using ID = unsigned int;

/**
 * A simple class to generate unique IDs.
 * Currently IDs are unsigned int.
 */
class IDGenerator {

public:

    IDGenerator() = default;

    /**
     * Updates internal values and produces a unique ID.
     * First the pool of unused IDs is checked. If none are available for
     * reuse, a fresh ID is returned.
     *
     * @return An ID that is unique among all active tasks and projects
     */
    ID getID();

    /**
     * Frees an ID for reuse.
     * This should be called when a task or project is deleted.
     *
     * @param id The ID to be freed
     */
    void releaseID(ID id);

private:

    // contains freed variables eligible for reuse
    std::deque<ID> idPool = {};

    // value that will be returned on the net getID() call if the idPool is empty
    ID nextID = 0;

};


#endif //SCHEDULER_IDGENERATOR_H
