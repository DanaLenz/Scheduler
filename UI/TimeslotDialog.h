//
// Created by dana on 01.04.21.
//

#ifndef SCHEDULER_TIMESLOTDIALOG_H
#define SCHEDULER_TIMESLOTDIALOG_H

#include <wx/wx.h>
#include <wx/gtk/dialog.h>
#include <wx/timectrl.h>
#include <wx/combobox.h>
#include <string>
#include "../Core/Calendar/TimeslotRule.h"
#include "../Core/Calendar/CalendarGenerator.h"

class TimeslotDialog : public wxDialog {

public:
    TimeslotDialog(wxWindow * parent, CalendarGenerator &cal, wxWindowID id = wxID_ANY, const wxString &title = "Timeslot Rule", const wxPoint &position = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);



private:

    CalendarGenerator& calendarGenerator;

    wxStaticText *label_weekday;
    wxComboBox *combo_weekday;

    wxStaticText *label_startTime;
    wxTimePickerCtrl *time_startTime;

    wxStaticText *label_duration;
    wxTextCtrl *text_duration;

    wxButton *button_save;
    wxButton *button_cancel;

    void OnCancel(wxCommandEvent &event);
    void OnSave(wxCommandEvent &event);

};

enum {
    ID_comboWeekday,
    ID_timeStart,
    ID_textDuration,
    IDTRD_buttonSave,
    IDTRD_buttonCancel
};


#endif //SCHEDULER_TIMESLOTDIALOG_H
