//
// Created by dana on 24.03.21.
//

#ifndef SCHEDULER_SCHEDULERAPP_H
#define SCHEDULER_SCHEDULERAPP_H

#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/gtk/app.h>
#include "../Core/Tasks/TaskManager.h"
#include "../Core/Calendar/CalendarGenerator.h"
#include "../Core/TagManager.h"

class schedulerApp : public wxApp {

public:
    schedulerApp();
    virtual bool OnInit();

private:
    TaskManager taskManager;
    CalendarGenerator calendarGenerator;
    TagManager tagManager;

};


#endif //SCHEDULER_SCHEDULERAPP_H
