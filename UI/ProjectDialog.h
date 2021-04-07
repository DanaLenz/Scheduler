//
// Created by dana on 06.04.21.
//

#ifndef SCHEDULER_PROJECTDIALOG_H
#define SCHEDULER_PROJECTDIALOG_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include "../Core/Tasks/Project.h"


class ProjectDialog : public wxDialog {

public:
    ProjectDialog(wxWindow * parent, Project &project, wxWindowID id = wxID_ANY, const wxString &title = "Project", const wxPoint &position = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);

private:

    Project &project;

    // ------------------------
    // Project definitions
    // ------------------------

    wxTextCtrl *text_name;
    wxStaticText *label_name;

    wxDatePickerCtrl *date_deadline;
    wxStaticText *label_deadline;

    wxTextCtrl *text_minTime;
    wxStaticText *label_minTime;

    wxTextCtrl *text_maxTime;
    wxStaticText *label_maxTime;

    // ------------------------
    // Layout Definitions
    // ------------------------

    wxButton *button_save;
    wxButton *button_cancel;

    void OnSave(wxCommandEvent &event);
    void OnCancel(wxCommandEvent &event);


};


enum {

    IDPROJECT_textName,
    IDPROJECT_dateDeadline,
    IDPROJECT_textMin,
    IDPROJECT_textMax,
    IDPROJECT_buttonSave,
    IDPROJECT_buttonCancel

};



#endif //SCHEDULER_PROJECTDIALOG_H
