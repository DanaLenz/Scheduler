//
// Created by dana on 24.03.21.
//

#include "MainFrame.h"
#include "TaskRuleDialog.h"

MainFrame::MainFrame(const wxString &title, TaskManager &tm) : wxFrame(NULL, wxID_ANY, title),
                                                                                         taskManager(tm) {

    // ---------------------------------------------------------------------------------

    assert(&tm == &taskManager);

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Test, "&Hello");
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Ayo");


    Bind(wxEVT_MENU, &MainFrame::OnTest, this, ID_Test);
    Bind(wxEVT_MENU, [=](wxCommandEvent&) {Close(true);}, wxID_EXIT);
    Bind(wxEVT_MENU, [=](wxCommandEvent&) {wxMessageBox("Ayyy ", "???", wxOK | wxICON_INFORMATION);}, wxID_ABOUT);

    // ---------------------------------------------------------------------------------

    wxBoxSizer *sizer_top = new wxBoxSizer(wxVERTICAL);

    // ---------------------------------------------------------------------------------

    wxBoxSizer *sizer_tasklist = new wxBoxSizer(wxHORIZONTAL);

    tasklistctrl = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(600,300));
    tasklistctrl->AppendTextColumn("ID");
    tasklistctrl->AppendTextColumn("Task");
    tasklistctrl->AppendTextColumn("Project");
    tasklistctrl->AppendTextColumn("Estimated Time (minutes)");
    tasklistctrl->AppendToggleColumn("Optional");
    tasklistctrl->AppendToggleColumn("Tied to Project");

    sizer_tasklist->Add(tasklistctrl, 1, wxEXPAND);

    sizer_top->Add(sizer_tasklist, 1, wxEXPAND);


    //sizer_top->Add(tasklistctrl);

    // ---------------------------------------------------------------------------------

    wxButton *button_add = new wxButton(this, ID_Add, wxString("&Add"));
    wxButton *button_delete = new wxButton(this, ID_Delete, wxString("Delete"));
    wxButton *button_edit = new wxButton(this, ID_Edit, wxString("Edit"));

    Bind(wxEVT_BUTTON, &MainFrame::OnAdd, this, ID_Add);
    Bind(wxEVT_BUTTON, &MainFrame::OnDelete, this, ID_Delete);
    Bind(wxEVT_BUTTON, &MainFrame::OnEdit, this, ID_Edit);

    wxBoxSizer *sizer_buttons = new wxBoxSizer(wxHORIZONTAL);
    sizer_buttons->Add(button_add);
    sizer_buttons->Add(button_delete);
    sizer_buttons->Add(button_edit);

    sizer_top->Add(sizer_buttons, 0, wxALIGN_CENTER_HORIZONTAL);

    refreshTaskRules();
    SetSizerAndFit(sizer_top);

}


void MainFrame::OnTest(wxCommandEvent& event) {
    wxMessageBox("Test success.");
}

void MainFrame::OnAdd(wxCommandEvent& event) {

    auto id =  taskManager.createTaskRule("");
    auto &tr = taskManager.getTaskRule(id);

    TaskRuleDialog *trd = new TaskRuleDialog(this, tr);

    // returns 0 if adding was successful
    if(trd->ShowModal())
        taskManager.deleteTaskRule(id);

    refreshTaskRules();

}

void MainFrame::OnEdit(wxCommandEvent &event) {

    auto row = tasklistctrl->GetSelectedRow();
    std::string stid = tasklistctrl->GetTextValue(row, 0).ToStdString(wxConvUTF8);
    auto id = std::stoi(stid);
    auto &tr = taskManager.getTaskRule(id);
    TaskRuleDialog *trd = new TaskRuleDialog(this, tr);
    trd->ShowModal();

    refreshTaskRules();
}

void MainFrame::OnDelete(wxCommandEvent &event) {

    auto row = tasklistctrl->GetSelectedRow();
    std::string stid = tasklistctrl->GetTextValue(row, 0).ToStdString(wxConvUTF8);
    auto id = std::stoi(stid);
    taskManager.deleteTaskRule(id);
    tasklistctrl->DeleteItem(row);

}

void MainFrame::addTaskRule(const ID id, const TaskRule* const taskRule, const Project * const project) {

    wxVector<wxVariant> data;
    data.push_back(wxVariant(std::to_string(id)));
    data.push_back(wxVariant(taskRule->getName()));
    data.push_back(wxVariant(project->getName()));
    data.push_back(wxVariant(std::to_string(taskRule->getNeededTime())));
    data.push_back(wxVariant(taskRule->isOptional()));
    data.push_back(wxVariant(taskRule->isProjectDependant()));
    tasklistctrl->AppendItem(data);

}

void MainFrame::refreshTaskRules() {

    tasklistctrl->DeleteAllItems();

    for(auto &id : taskManager.getAllTaskRules()) {

        auto tr = &taskManager.getTaskRule(id);
        auto project = &taskManager.getProject(taskManager.getAssignedProject(id));
        addTaskRule(id, tr, project);
    }
}