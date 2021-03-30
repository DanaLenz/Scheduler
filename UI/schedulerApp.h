//
// Created by dana on 24.03.21.
//

#ifndef SCHEDULER_SCHEDULERAPP_H
#define SCHEDULER_SCHEDULERAPP_H

#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/gtk/app.h>
#include "../Core/Tasks/TaskManager.h"

class schedulerApp : public wxApp {

public:
    virtual bool OnInit();

private:
    TaskManager taskManager;

};


#endif //SCHEDULER_SCHEDULERAPP_H
