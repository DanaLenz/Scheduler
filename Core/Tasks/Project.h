//
// Created by Dana on 15.03.2020.
//

#ifndef SCHEDULER_PROJECT_H
#define SCHEDULER_PROJECT_H


#include <unordered_set>
#include <vector>
#include "../Definitions.h"

/**
 * A project, user created, that is a titled collection of
 * task rules.
 */
class Project {
    friend class TaskManager;

public:


    /**
     * Create a new project with an empty name.
     */
    Project();

    /**
     * Create a project with a name.
     * Handy since a name will usually be given before other information.
     * @param name Name of the project
     */
    explicit Project(std::string name);


    /**
     * The minimum hours that should be spend on a project per week.
     * This denotes a strong preference, not a guarantee.
     * @return Preferred minimal amount of hours that should be spend on a project per week
     */
    [[nodiscard]] float getMinimumWeeklyHours() const;
    /**
     * The minimum hours that should be spend on a project per week.
     * This denotes a strong preference, not a guarantee.
     * @param minimumWeeklyHours Preferred minimal amount of hours that should be spend on a project per week
     */
    void setMinimumWeeklyHours(float minimumWeeklyHours);

    /**
     * The maximal amount of hours that should be spent on a project
     * each week. This is a strong preference, not a guarantee, and
     * may be ignored to meet a deadline.
     * @return Preferred maximal amount of hours spent on a project each week
     */
    [[nodiscard]] float getMaximumWeeklyHours() const;
    /**
     * The maximal amount of hours that should be spent on a project
     * each week. This is a strong preference, not a guarantee, and
     * may be ignored to meet a deadline.
     * @param maximumWeeklyHours Preferred maximal amount of hours spent on a project each week
     */
    void setMaximumWeeklyHours(float maximumWeeklyHours);

    /**
     * Note: project names can be changed freely, since they are
     * identified by their ID
     * @return Name of the project
     */
    [[nodiscard]] const std::string &getName() const;
    /**
     * Note: project names can be changed freely, since they are
     * identified by their ID
     * @param name New name for the project
     */
    void setName(const std::string &name);

    /**
     * All non-optional tasks belonging to a project should be scheduled (if possible)
     * before the deadline. Additionally, as many optional tasks as possible should
     * be scheduled.
     * No task belonging to a project will be scheduled past its deadline.
     * @return Deadline for all tasks of a project
     */
    [[nodiscard]] const TimeDefs::Date &getDeadline() const;

    /**
     * All non-optional tasks belonging to a project should be scheduled (if possible)
     * before the deadline. Additionally, as many optional tasks as possible should
     * be scheduled.
     * No task belonging to a project will be scheduled past its deadline.
     * @param deadline Deadline for all tasks of a project
     */
    void setDeadline(const TimeDefs::Date &deadline);


private:

    std::string name;
    TimeDefs::Date deadline;
    float minimumWeeklyHours;
    float maximumWeeklyHours;

};

bool operator==(const Project& lhs, const Project& rhs);

#endif //SCHEDULER_PROJECT_H
