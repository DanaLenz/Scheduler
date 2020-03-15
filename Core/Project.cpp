//
// Created by Dana on 15.03.2020.
//

#include "Project.h"
#include <algorithm>

float Project::getMinimumWeeklyHours() const {
    return minimumWeeklyHours;
}

void Project::setMinimumWeeklyHours(float minimumWeeklyHours) {
    Project::minimumWeeklyHours = minimumWeeklyHours;
}

float Project::getMaximumWeeklyHours() const {
    return maximumWeeklyHours;
}

void Project::setMaximumWeeklyHours(float maximumWeeklyHours) {
    Project::maximumWeeklyHours = maximumWeeklyHours;
}

Task* Project::createTask() {
   associatedTasks.emplace_back(std::move(Task{}));
   return &associatedTasks.back();
}

void Project::removeTask(Task& task) {
    //TODO: where do I put NOJECT?
    if(!task.isProjectDependant())
        ;//transferTask(task, NOJECT);

   associatedTasks.erase(std::find(associatedTasks.begin(), associatedTasks.end(), task));
}

void Project::transferTask(Task &task, Project &targetProject) {

}

Task* Project::accessTask(const int index){
    return &associatedTasks.at(index);
}
