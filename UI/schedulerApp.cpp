//
// Created by dana on 24.03.21.
//

#include "schedulerApp.h"
#include "TaskFrame.h"
//#include "Menubar.h"

#include <wx/app.h>
#include "wx/menu.h"
#include "MainFrame.h"

bool schedulerApp::OnInit() {

    if(!wxApp::OnInit())
        return false;

    // ---- initialize test data ----

    auto sched = taskManager.createProject("Scheduler project");
    auto health = taskManager.createProject("Health");
    auto dog = taskManager.createProject("Dog");

    auto walk = taskManager.createTaskRule("Walk Dog", dog);
    auto pet = taskManager.createTaskRule("Pet Dog", dog);
    auto clean = taskManager.createTaskRule("Clean Bathroom");

    taskManager.getTaskRule(pet).setOptional(true);

    auto monday = calendarGenerator.createTimeslotRule(1, 15, 0, 2);

    // ------------------------------


    MainFrame *mainFrame = new MainFrame("", taskManager, calendarGenerator);

    mainFrame->Show(true);

    return true;

}