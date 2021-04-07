//
// Created by dana on 06.04.21.
//

#include "ProjectPanel.h"
#include "ProjectDialog.h"


ProjectPanel::ProjectPanel(wxWindow * parent, TaskManager &tm) : wxPanel(parent),
                                                           taskManager(tm) {

    // ---------------------------------------------------------------------------------

    wxBoxSizer *sizer_top = new wxBoxSizer(wxVERTICAL);

    // ---------------------------------------------------------------------------------

    wxBoxSizer *sizer_projectlist = new wxBoxSizer(wxHORIZONTAL);

    projectlistctrl = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(1200,300));
    projectlistctrl->AppendTextColumn("ID");
    projectlistctrl->AppendTextColumn("Name");
    projectlistctrl->AppendTextColumn("Deadline");
    projectlistctrl->AppendTextColumn("Min Minutes Weekly");
    projectlistctrl->AppendTextColumn("Max Minutes Weekly");

    sizer_projectlist->Add(projectlistctrl, 1, wxEXPAND);

    sizer_top->Add(sizer_projectlist, 1, wxEXPAND);

    // ---------------------------------------------------------------------------------

    wxButton *button_add = new wxButton(this, ID_PROJECT_Add, wxString("&Add"));
    wxButton *button_delete = new wxButton(this, ID_PROJECT_Delete, wxString("Delete"));
    wxButton *button_edit = new wxButton(this, ID_PROJECT_Edit, wxString("Edit"));

    Bind(wxEVT_BUTTON, &ProjectPanel::OnAdd, this, ID_PROJECT_Add);
    Bind(wxEVT_BUTTON, &ProjectPanel::OnDelete, this, ID_PROJECT_Delete);
    Bind(wxEVT_BUTTON, &ProjectPanel::OnEdit, this, ID_PROJECT_Edit);

    wxBoxSizer *sizer_buttons = new wxBoxSizer(wxHORIZONTAL);
    sizer_buttons->Add(button_add);
    sizer_buttons->Add(button_delete);
    sizer_buttons->Add(button_edit);

    sizer_top->Add(sizer_buttons, 0, wxALIGN_CENTER_HORIZONTAL);

    refreshProjects();
    SetSizerAndFit(sizer_top);

}


void ProjectPanel::OnAdd(wxCommandEvent& event) {

    auto id =  taskManager.createProject("");
    auto &project = taskManager.getProject(id);

    ProjectDialog *trd = new ProjectDialog(this, project);

    // returns 0 if adding was successful
    if(trd->ShowModal())
        taskManager.deleteProject(id);

    refreshProjects();

}

void ProjectPanel::OnEdit(wxCommandEvent &event) {

    auto row = projectlistctrl->GetSelectedRow();
    std::string stid = projectlistctrl->GetTextValue(row, 0).ToStdString(wxConvUTF8);
    auto id = std::stoi(stid);
    auto &project = taskManager.getProject(id);
    ProjectDialog *pd = new ProjectDialog(this, project);
    pd->ShowModal();

    refreshProjects();
}

void ProjectPanel::OnDelete(wxCommandEvent &event) {

    auto row = projectlistctrl->GetSelectedRow();
    std::string stid = projectlistctrl->GetTextValue(row, 0).ToStdString(wxConvUTF8);
    auto id = std::stoi(stid);
    taskManager.deleteProject(id);
    refreshProjects();
}

void ProjectPanel::addProject(const ID id, const Project* const project) {

    wxVector<wxVariant> data;

    data.push_back(wxVariant(std::to_string(id)));
    data.push_back(wxVariant(project->getName()));

    TimeDefs::Date deadline = project->getDeadline();
    data.push_back(wxVariant(boost::gregorian::to_simple_string(deadline)));

    data.push_back(wxVariant(std::to_string(project->getMinimumWeeklyMinutes())));
    data.push_back(wxVariant(std::to_string(project->getMaximumWeeklyMinutes())));

    projectlistctrl->AppendItem(data);

}

void ProjectPanel::refreshProjects() {

    projectlistctrl->DeleteAllItems();

    for(auto &id : taskManager.getAllProjects()) {

        auto project = &taskManager.getProject(id);
        addProject(id, project);
    }
}