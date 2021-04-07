//
// Created by dana on 02.04.21.
//

#ifndef SCHEDULER_MAINFRAME_H
#define SCHEDULER_MAINFRAME_H

#include <wx/menu.h>
#include <wx/notebook.h>
#include "wx/wx.h"
#include "../Core/Tasks/TaskManager.h"
#include "../Core/Calendar/CalendarGenerator.h"


class MainFrame : public wxFrame {

public:
    MainFrame(const wxString &title, TaskManager &taskManager, CalendarGenerator &calendarGen);

private:

    TaskManager &taskManager;
    CalendarGenerator &calendarGen;

    wxMenuBar *menubar;
    wxMenu *menuTasks;
    wxMenu *menuFile;
    wxMenu *menuOutput;
    wxMenu *menuHelp;

    wxPanel *m_panel; // Panel containing notebook and other controls
    wxNotebook *notebook;

};

enum {
    IDMenu_viewTasks,
    IDMenu_addTaskRule,
    IDPanel_tasks,
    IDMENU_OUT,
    IDMENU_SAVE
};

#endif //SCHEDULER_MAINFRAME_H
