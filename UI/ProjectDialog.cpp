//
// Created by dana on 06.04.21.
//

#include <wx/valnum.h>
#include "ProjectDialog.h"


ProjectDialog::ProjectDialog(wxWindow *parent, Project &pr, wxWindowID id, const wxString &title, const wxPoint &position,
                               const wxSize &size, long style) : wxDialog(parent, id, title, position, size, style), project(pr) {


    wxFlexGridSizer *sizer_top = new wxFlexGridSizer(2);

    // ---------------------------------------------------------------------------------
    // ---------------------------- Task-Related Input ---------------------------------
    // ---------------------------------------------------------------------------------

    label_name = new wxStaticText(this, wxID_ANY, wxT("Name"));
    text_name = new wxTextCtrl(this, IDPROJECT_textName, project.getName());

    label_deadline = new wxStaticText(this, wxID_ANY, wxT("Deadline"));
    date_deadline = new wxDatePickerCtrl(this, IDPROJECT_dateDeadline);

    label_minTime = new wxStaticText(this, wxID_ANY, wxT("Minimal Weekly Time"));
    auto minString = std::to_string(project.getMinimumWeeklyMinutes());
    wxIntegerValidator<unsigned int> validator_minTime {};
    text_minTime = new wxTextCtrl(this, IDPROJECT_textMin, wxVariant(minString), wxDefaultPosition, wxDefaultSize, 0, validator_minTime);

    label_maxTime = new wxStaticText(this, wxID_ANY, wxT("Maximum Weekly Time"));
    auto maxString = std::to_string(project.getMaximumWeeklyMinutes());
    wxIntegerValidator<unsigned int> validator_maxTime {};
    text_maxTime = new wxTextCtrl(this, IDPROJECT_textMin, wxVariant(maxString), wxDefaultPosition, wxDefaultSize, 0, validator_maxTime);


    auto *sizer_task = new wxGridSizer(2);

    sizer_task->Add(label_name);
    sizer_task->Add(text_name);

    sizer_task->Add(label_deadline);
    sizer_task->Add(date_deadline);

    sizer_task->Add(label_minTime);
    sizer_task->Add(text_minTime);

    sizer_task->Add(label_maxTime);
    sizer_task->Add(text_maxTime);



    // ---------------------------------------------------------------------------------
    // -------------------------------- Layout -----------------------------------------
    // ---------------------------------------------------------------------------------

    auto sizer_button = new wxBoxSizer(wxHORIZONTAL);

    button_save = new wxButton(this, IDPROJECT_buttonSave, wxT("Save"));
    button_cancel = new wxButton(this, IDPROJECT_buttonCancel, wxT("Cancel"));

    sizer_button->Add(button_save);
    sizer_button->Add(button_cancel);

    sizer_top->Add(sizer_task, 1, wxEXPAND);
    sizer_top->Add(sizer_button, 0);

    Bind(wxEVT_BUTTON, &ProjectDialog::OnCancel, this, IDPROJECT_buttonCancel);
    Bind(wxEVT_BUTTON, &ProjectDialog::OnSave, this, IDPROJECT_buttonSave);

    SetSizerAndFit(sizer_top);
    Centre();


}

void ProjectDialog::OnSave(wxCommandEvent &event) {

    auto name = text_name->GetLineText(0).ToStdString(wxConvUTF8);
    project.setName(name);

    auto mintime = std::stoi(text_minTime->GetLineText(0).ToStdString());
    project.setMinimumWeeklyMinutes(mintime);

    auto maxtime = std::stoi(text_maxTime->GetLineText(0).ToStdString());
    project.setMaximumWeeklyMinutes(maxtime);

    auto deadline = date_deadline->GetValue();
    auto stringDeadline = deadline.Format("%F").ToStdString(wxConvUTF8);
    project.setDeadline(boost::gregorian::from_string(stringDeadline));

    EndModal(0);

}

void ProjectDialog::OnCancel(wxCommandEvent &event) {

    EndModal(1);
}
