//
// Created by dana on 26.03.21.
//

#ifndef SCHEDULER_TASKRULEDIALOG_H
#define SCHEDULER_TASKRULEDIALOG_H


#include <wx/wx.h>
#include <wx/propgrid/props.h>
#include <wx/datectrl.h>
#include <wx/grid.h>
#include "../Core/Tasks/TaskRule.h"

class TaskRuleDialog : public wxDialog {

public:
    TaskRuleDialog(wxWindow * parent, TaskRule &tr, wxWindowID id = wxID_ANY, const wxString &title = "Task Rule", const wxPoint &position = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);

private:

    TaskRule &taskRule;

    // ------------------------
    // Task-related definitions
    // ------------------------

    wxTextCtrl *text_name;
    wxStaticText *label_name;

    wxComboBox *combo_project;
    wxStaticText *label_project;

    wxTextCtrl *text_time;
    wxStaticText *label_time;
    //wxNumericPropertyValidator validator_time;

    wxCheckBox *check_dependant;
    wxStaticText *label_dependant;

    wxCheckBox *check_optional;
    wxStaticText *label_optional;


    // ------------------------
    // Time-related definitions
    // ------------------------

    wxCheckBox *check_start;
    wxDatePickerCtrl *date_start;
    wxStaticText *label_start;

    wxCheckBox *check_end;
    wxDatePickerCtrl *date_end;
    wxStaticText *label_end;

    wxComboBox *combo_recurrenceType;
    wxStaticText *label_recurrenceType;

    wxTextCtrl *text_recurrence;
    //wxNumericPropertyValidator validator_recurrence;
    wxStaticText *label_recurrence;

    wxComboBox *combo_deadlineType;
    wxStaticText *label_deadlineType;

    wxDatePickerCtrl *date_absoluteDeadline;
    wxStaticText *label_absoluteDeadline;

    wxTextCtrl *text_relativeDeadline;
    //wxNumericPropertyValidator *validator_relativeDeadline;
    wxStaticText *label_relativeDeadline;

    // ------------------------
    // Layout Definitions
    // ------------------------

    wxButton *button_save;
    wxButton *button_cancel;

    void OnSave(wxCommandEvent &event);
    void OnCancel(wxCommandEvent &event);

    void OnDLTypeSelection(wxCommandEvent& event);


};


enum {

    ID_textName,
    ID_comboProject,
    ID_textTime,
    ID_checkDependant,
    ID_checkOptional,
    ID_buttonSave,
    ID_buttonCancel,
    ID_checkStart,
    ID_dateStart,
    ID_checkEnd,
    ID_dateEnd,
    ID_comboRecurrence,
    ID_textRec,
    ID_comboDeadline,
    ID_dateAbsolute,
    ID_textRelative,
    ID_labelRec,
    ID_labelDeadline

};


#endif //SCHEDULER_TASKRULEDIALOG_H
