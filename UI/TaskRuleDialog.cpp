//
// Created by dana on 26.03.21.
//

#include "TaskRuleDialog.h"
#include "../Core/Tasks/TaskRule.h"
#include <wx/sizer.h>
#include <wx/datetime.h>
#include <wx/grid.h>


TaskRuleDialog::TaskRuleDialog(wxWindow *parent, TaskRule &tr, wxWindowID id, const wxString &title, const wxPoint &position,
                               const wxSize &size, long style) : wxDialog(parent, id, title, position, size, style), taskRule(tr) {


    wxFlexGridSizer *sizer_top = new wxFlexGridSizer(2);

    // ---------------------------------------------------------------------------------
    // ---------------------------- Task-Related Input ---------------------------------
    // ---------------------------------------------------------------------------------

    label_name = new wxStaticText(this, wxID_ANY, wxT("Name"));
    label_project = new wxStaticText(this, wxID_ANY, wxT("Project"));
    label_time = new wxStaticText(this, wxID_ANY, wxT("Estimated Time"));
    label_dependant = new wxStaticText(this, wxID_ANY, wxT("Attached to Project"));
    label_optional = new wxStaticText(this, wxID_ANY, wxT("Optional"));

    //validator_time = new wxNumericPropertyValidator(wxNumericPropertyValidator::Unsigned);
    //validator_time = wxNumericPropertyValidator{wxNumericPropertyValidator::Unsigned};

    text_name = new wxTextCtrl(this, ID_textName, taskRule.getName());
    combo_project = new wxComboBox(this, ID_comboProject);
    text_time = new wxTextCtrl(this, ID_textTime, std::to_string(taskRule.getNeededTime()));

    check_dependant = new wxCheckBox(this, ID_checkDependant, wxT("dependant"));
    if(taskRule.isProjectDependant())
        check_dependant->SetValue(true);

    check_optional = new wxCheckBox(this, ID_checkOptional, wxT("optional"));
    if(taskRule.isOptional())
        check_optional->SetValue(true);


    //wxStaticBoxSizer *sizer_task = new wxStaticBoxSizer(wxHORIZONTAL, this);
    auto *sizer_task = new wxGridSizer(2);

    sizer_task->Add(label_name);
    sizer_task->Add(text_name);

    sizer_task->Add(label_project);
    sizer_task->Add(combo_project);

    sizer_task->Add(label_time);
    sizer_task->Add(text_time);

    sizer_task->Add(label_dependant);
    sizer_task->Add(check_dependant);

    sizer_task->Add(label_optional);
    sizer_task->Add(check_optional);


    // ---------------------------------------------------------------------------------
    // ---------------------------- Time-Related Input ---------------------------------
    // ---------------------------------------------------------------------------------


    check_start = new wxCheckBox(this, ID_checkStart, "Start Date");
    date_start = new wxDatePickerCtrl (this, ID_dateStart, wxDateTime::Today());
    //label_start = new wxStaticText(this, wxID_ANY, wxT("Start Date"));

    check_end = new wxCheckBox(this, ID_checkEnd, "End Date");
    date_end = new wxDatePickerCtrl (this, ID_dateEnd, wxDateTime::Today());
    //label_end = new wxStaticText(this, wxID_ANY, wxT("End Date"));

    wxArrayString recStrings;
    for(const auto &pair : TaskRule::recurrenceTypeStrings)
        recStrings.Add(pair.first);

    combo_recurrenceType = new wxComboBox(this, ID_comboRecurrence, recStrings[0], wxDefaultPosition, wxDefaultSize,
                                          recStrings);
    label_recurrenceType = new wxStaticText(this, wxID_ANY, "Recurrence Type");

    text_recurrence = new wxTextCtrl(this, ID_textRec, std::to_string(taskRule.getXtimes()));
    //validator_recurrence = new  wxNumericPropertyValidator( wxNumericPropertyValidator::Unsigned);
    label_recurrence = new wxStaticText(this, ID_labelRec, "Times a week");

    wxArrayString dlStrings;
    for(const auto &pair : TaskRule::deadlineTypeStrings)
        dlStrings.Add(pair.first);
    combo_deadlineType = new wxComboBox(this, ID_comboDeadline, dlStrings[0], wxDefaultPosition, wxDefaultSize, dlStrings);
    label_deadlineType = new wxStaticText(this, wxID_ANY, "Deadline Type");

    date_absoluteDeadline = new wxDatePickerCtrl (this, ID_dateAbsolute, wxDateTime::Today());
    label_absoluteDeadline = new wxStaticText(this, ID_labelDeadline, "Deadline");

    text_relativeDeadline = new wxTextCtrl(this, ID_textRec, "1");
    //validator_relativeDeadline = new  wxNumericPropertyValidator( wxNumericPropertyValidator::Unsigned);
    label_relativeDeadline = new wxStaticText(this, wxID_ANY, "Days to Deadline");


    auto *sizer_time = new wxGridSizer(2);

    sizer_time->Add(check_start);
    sizer_time->Add(date_start);

    sizer_time->Add(check_end);
    sizer_time->Add(date_end);

    sizer_time->Add(label_recurrenceType);
    sizer_time->Add(combo_recurrenceType);

    sizer_time->Add(label_recurrence);
    sizer_time->Add(text_recurrence);

    sizer_time->Add(label_deadlineType);
    sizer_time->Add(combo_deadlineType);

    sizer_time->Add(label_absoluteDeadline);
    sizer_time->Add(date_absoluteDeadline);

    sizer_time->Add(label_relativeDeadline);
    sizer_time->Add(text_relativeDeadline);


    // ---------------------------------------------------------------------------------
    // ---------------------------- Tag-Related Input ----------------------------------
    // ---------------------------------------------------------------------------------




    // ---------------------------------------------------------------------------------
    // -------------------------------- Layout -----------------------------------------
    // ---------------------------------------------------------------------------------

    auto sizer_button = new wxBoxSizer(wxHORIZONTAL);

    button_save = new wxButton(this, ID_buttonSave, wxT("Save"));
    button_cancel = new wxButton(this, ID_buttonCancel, wxT("Cancel"));

    sizer_button->Add(button_save);
    sizer_button->Add(button_cancel);

    sizer_top->Add(sizer_task, 1, wxEXPAND);
    sizer_top->Add(sizer_time, 1, wxEXPAND);
    sizer_top->Add(sizer_button, 0);

    Bind(wxEVT_BUTTON, &TaskRuleDialog::OnCancel, this, ID_buttonCancel);
    Bind(wxEVT_BUTTON, &TaskRuleDialog::OnSave, this, ID_buttonSave);

    //Bind(wxEVT_COMBOBOX, &TaskFrame::OnDLTypeSelection, this, ID_comboDeadline);

    SetSizerAndFit(sizer_top);
    Centre();


}

void TaskRuleDialog::OnSave(wxCommandEvent &event) {

 /*   if(!validator_time->Validate(text_time)){
        wxMessageBox("The estimated time needs to be a a positive, whole number or zero.");
        return;
    }
*/
    auto name = text_name->GetLineText(0).ToStdString(wxConvUTF8);
    taskRule.setName(name);

    //auto project =
    //taskRule.setProject();

    auto time = std::stoi(text_time->GetLineText(0).ToStdString());
    taskRule.setNeededTime(time);

    auto dependant = check_dependant->IsChecked();
    taskRule.setProjectDependant(dependant);

    auto optional = check_optional->IsChecked();
    taskRule.setOptional(optional);

    auto startDate = date_start->GetValue();
    //taskRule.setStartDate(startDate);

    auto endDate = date_end->GetValue();
    //taskRule.setEndDate(endDate);

    auto recurrenceType = TaskRule::recurrenceTypeStrings.at(combo_recurrenceType->GetValue().ToStdString(wxConvUTF8));
    taskRule.setRecurrenceType(recurrenceType);

    switch (recurrenceType) {

        case RecurrenceType::INFINITE :
            break;

        case RecurrenceType::X_IN_WEEK :
            taskRule.setXtimes(std::stoi(text_recurrence->GetValue().ToStdString(wxConvUTF8)));
            break;

        case RecurrenceType::EVERY_X_DAYS :
            auto daynum = std::stoi(text_recurrence->GetValue().ToStdString(wxConvUTF8));
            TimeDefs::DateDuration dur {daynum};
            taskRule.setEveryXDays(dur);
            break;
    }

    auto deadlineType = TaskRule::deadlineTypeStrings.at(combo_deadlineType->GetValue().ToStdString(wxConvUTF8));

    switch(deadlineType) {

        case DeadlineType::NONE :
            break;

        case DeadlineType::ABSOLUTE :
            taskRule.setDeadlineType(DeadlineType::ABSOLUTE);
            taskRule.setAbsoluteDeadline(boost::gregorian::from_string(date_absoluteDeadline->GetValue().Format("%F").ToStdString(wxConvUTF8)));
            break;

        case DeadlineType::RELATIVE :
            taskRule.setDeadlineType(DeadlineType::RELATIVE);
            taskRule.setRelativeDeadline(TimeDefs::DateDuration {std::stoi(text_relativeDeadline->GetValue().ToStdString(wxConvUTF8))});
            break;

    }

    EndModal(0);

}

void TaskRuleDialog::OnCancel(wxCommandEvent &event) {

    EndModal(1);
}
