//
// Created by dana on 02.04.21.
//

#include "MainFrame.h"
#include "TaskFrame.h"
#include "TimeslotFrame.h"

MainFrame::MainFrame(const wxString &title, TaskManager &tm, CalendarGenerator &cg) : wxFrame(NULL, wxID_ANY, title),
    taskManager(tm), calendarGen(cg) {

    //menubar = new wxMenuBar;
    //menuTasks = new wxMenu;

    //menuTasks->Append(IDMenu_viewTasks, "View Tasks");
    //menuTasks->Append(IDMenu_addTaskRule, "Add Task Rule");

    //SetMenuBar(menubar);

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    notebook = new wxNotebook(this, wxID_ANY);
    sizer->Add(notebook, wxEXPAND);

    TaskFrame *taskPanel = new TaskFrame(notebook, taskManager);
    notebook->AddPage(taskPanel, "Tasks");

    TimeslotFrame *timeslotPanel = new TimeslotFrame(notebook, calendarGen);
    notebook->AddPage(timeslotPanel, "Timeslots");

    SetClientSize(notebook->GetBestSize());

}