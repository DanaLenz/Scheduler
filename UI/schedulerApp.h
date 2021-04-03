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

class schedulerApp : public wxApp {

public:
    virtual bool OnInit();

private:
    TaskManager taskManager;
    CalendarGenerator calendarGenerator;


};


#endif //SCHEDULER_SCHEDULERAPP_H
