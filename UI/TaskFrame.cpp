//
// Created by dana on 24.03.21.
//

#include "TaskFrame.h"
#include "TaskRuleDialog.h"

TaskFrame::TaskFrame(wxWindow * parent, TaskManager &tm) : wxPanel(parent),
                                                               taskManager(tm) {

    // ---------------------------------------------------------------------------------


    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");


    Bind(wxEVT_MENU, [=](wxCommandEvent&) {Close(true);}, wxID_EXIT);
    Bind(wxEVT_MENU, [=](wxCommandEvent&) {wxMessageBox("Ayyy ", "???", wxOK | wxICON_INFORMATION);}, wxID_ABOUT);

    // ---------------------------------------------------------------------------------

    wxBoxSizer *sizer_top = new wxBoxSizer(wxVERTICAL);

    // ---------------------------------------------------------------------------------

    wxBoxSizer *sizer_tasklist = new wxBoxSizer(wxHORIZONTAL);

    tasklistctrl = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(1200,300));
    tasklistctrl->AppendTextColumn("ID");
    tasklistctrl->AppendTextColumn("Task");
    tasklistctrl->AppendTextColumn("Project");
    tasklistctrl->AppendTextColumn("Estimated Time (minutes)");
    tasklistctrl->AppendToggleColumn("Optional");
    tasklistctrl->AppendToggleColumn("Tied to Project");
    tasklistctrl->AppendTextColumn("Start Date");
    tasklistctrl->AppendTextColumn("End Date");
    tasklistctrl->AppendTextColumn("Recurrence Type");
    tasklistctrl->AppendTextColumn("Recurrence Value");
    tasklistctrl->AppendTextColumn("Deadline Type");
    tasklistctrl->AppendTextColumn("Value");

    sizer_tasklist->Add(tasklistctrl, 1, wxEXPAND);

    sizer_top->Add(sizer_tasklist, 1, wxEXPAND);


    //sizer_top->Add(tasklistctrl);

    // ---------------------------------------------------------------------------------

    wxButton *button_add = new wxButton(this, ID_TASK_Add, wxString("&Add"));
    wxButton *button_delete = new wxButton(this, ID_TASK_Delete, wxString("Delete"));
    wxButton *button_edit = new wxButton(this, ID_TASK_Edit, wxString("Edit"));

    Bind(wxEVT_BUTTON, &TaskFrame::OnAdd, this, ID_TASK_Add);
    Bind(wxEVT_BUTTON, &TaskFrame::OnDelete, this, ID_TASK_Delete);
    Bind(wxEVT_BUTTON, &TaskFrame::OnEdit, this, ID_TASK_Edit);

    wxBoxSizer *sizer_buttons = new wxBoxSizer(wxHORIZONTAL);
    sizer_buttons->Add(button_add);
    sizer_buttons->Add(button_delete);
    sizer_buttons->Add(button_edit);

    sizer_top->Add(sizer_buttons, 0, wxALIGN_CENTER_HORIZONTAL);

    refreshTaskRules();
    SetSizerAndFit(sizer_top);

}


void TaskFrame::OnTest(wxCommandEvent& event) {
    wxMessageBox("Test success.");
}


void TaskFrame::OnAdd(wxCommandEvent& event) {

    auto id =  taskManager.createTaskRule("");
    auto &tr = taskManager.getTaskRule(id);

    TaskRuleDialog *trd = new TaskRuleDialog(this, tr);

    // returns 0 if adding was successful
    if(trd->ShowModal())
        taskManager.deleteTaskRule(id);

    refreshTaskRules();

}

void TaskFrame::OnEdit(wxCommandEvent &event) {

    auto row = tasklistctrl->GetSelectedRow();
    std::string stid = tasklistctrl->GetTextValue(row, 0).ToStdString(wxConvUTF8);
    auto id = std::stoi(stid);
    auto &tr = taskManager.getTaskRule(id);
    TaskRuleDialog *trd = new TaskRuleDialog(this, tr);
    trd->ShowModal();

    refreshTaskRules();
}

void TaskFrame::OnDelete(wxCommandEvent &event) {

    auto row = tasklistctrl->GetSelectedRow();
    std::string stid = tasklistctrl->GetTextValue(row, 0).ToStdString(wxConvUTF8);
    auto id = std::stoi(stid);
    taskManager.deleteTaskRule(id);
    tasklistctrl->DeleteItem(row);

}

void TaskFrame::addTaskRule(const ID id, const TaskRule* const taskRule, const Project * const project) {

    wxVector<wxVariant> data;
    data.push_back(wxVariant(std::to_string(id)));
    data.push_back(wxVariant(taskRule->getName()));
    data.push_back(wxVariant(project->getName()));
    data.push_back(wxVariant(std::to_string(taskRule->getNeededTime())));
    data.push_back(wxVariant(taskRule->isOptional()));
    data.push_back(wxVariant(taskRule->isProjectDependant()));

    TimeDefs::Date startDate = taskRule->getStartDate();
    data.push_back(wxVariant(boost::gregorian::to_simple_string(startDate)));

    TimeDefs::Date endDate = taskRule->getEndDate();
    data.push_back(wxVariant(boost::gregorian::to_simple_string(endDate)));

    switch(taskRule->getRecurrenceType()) {
        case RecurrenceType::INFINITE :
            data.push_back(wxVariant("Infinite"));
            data.push_back(wxVariant("-"));
            break;

        case RecurrenceType::EVERY_X_DAYS :
            data.push_back(wxVariant("Every X Days"));
            data.push_back(wxVariant(std::to_string(taskRule->getEveryXDays().days())));
            break;

        case RecurrenceType::X_IN_WEEK :
            data.push_back(wxVariant("X Each Week"));
            data.push_back(wxVariant(wxVariant(std::to_string(taskRule->getXtimes()))));
            break;
    }

    switch(taskRule->getDeadlineType()) {
        case DeadlineType::NONE :
            data.push_back(wxVariant("None"));
            data.push_back(wxVariant("-"));
            break;
        case DeadlineType::ABSOLUTE :
            data.push_back(wxVariant("Absolute"));
            data.push_back(wxVariant(boost::gregorian::to_simple_string(taskRule->getAbsoluteDeadline())));
            break;
        case DeadlineType::RELATIVE :
            data.push_back(wxVariant("Relative"));
            data.push_back(wxVariant(std::to_string(taskRule->getRelativeDeadline().days())));
            break;
    }

    tasklistctrl->AppendItem(data);

}

void TaskFrame::refreshTaskRules() {

    tasklistctrl->DeleteAllItems();

    for(auto &id : taskManager.getAllTaskRules()) {

        auto tr = &taskManager.getTaskRule(id);
        auto project = &taskManager.getProject(taskManager.getAssignedProject(id));
        addTaskRule(id, tr, project);
    }
}
