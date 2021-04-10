//
// Created by dana on 02.04.21.
//

#include "MainFrame.h"
#include "TaskFrame.h"
#include "TimeslotFrame.h"
#include "ProjectPanel.h"
#include "TagPanel.h"

MainFrame::MainFrame(const wxString &title, TaskManager &tm, CalendarGenerator &cg, TagManager &tgm) : wxFrame(NULL, wxID_ANY, title),
    taskManager(tm), calendarGen(cg), tagManager(tgm) {


    // ---------------------------------------------------------------------------------
    // ---------------------------------- Menubar --------------------------------------
    // ---------------------------------------------------------------------------------


    menubar = new wxMenuBar;

    menuFile = new wxMenu;
    menuFile->Append(IDMENU_SAVE, "Save");
    menuFile->Append(wxID_EXIT);
    menubar->Append(menuFile, "File");

    menuOutput = new wxMenu;
    menuOutput->Append(IDMENU_OUT, "Output SMT-LIB 2");
    menubar->Append(menuOutput, "Output");

    menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    menubar->Append(menuHelp, "Help");

    Bind(wxEVT_MENU, [=](wxCommandEvent&) {Close(true);}, wxID_EXIT);
    Bind(wxEVT_MENU, [=](wxCommandEvent&) {wxMessageBox("An interface made with wxWidget for the project in development at https://github.com/DanaLenz/Scheduler.git", "About", wxOK | wxICON_INFORMATION);}, wxID_ABOUT);

    SetMenuBar(menubar);


    // ---------------------------------------------------------------------------------


    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    notebook = new wxNotebook(this, wxID_ANY);
    sizer->Add(notebook, wxEXPAND);

    ProjectPanel *projectPanel = new ProjectPanel(notebook, taskManager);
    notebook->AddPage(projectPanel, "Projects");

    TaskFrame *taskPanel = new TaskFrame(notebook, taskManager);
    notebook->AddPage(taskPanel, "Tasks");

    TimeslotFrame *timeslotPanel = new TimeslotFrame(notebook, calendarGen);
    notebook->AddPage(timeslotPanel, "Timeslots");

    TagPanel *tagPanel = new TagPanel(notebook, tagManager, taskManager, calendarGen);
    notebook->AddPage(tagPanel, "Tags");

    SetClientSize(notebook->GetBestSize());

}