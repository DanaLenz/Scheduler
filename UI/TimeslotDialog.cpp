//
// Created by dana on 01.04.21.
//

#include "TimeslotDialog.h"

TimeslotDialog::TimeslotDialog(wxWindow *parent, CalendarGenerator &cal, wxWindowID id, const wxString &title,
                               const wxPoint &position, const wxSize &size, long style) : wxDialog(parent, id, title, position, size, style), calendarGenerator(cal) {

    wxFlexGridSizer *sizer_top = new wxFlexGridSizer(2);

    // ---------------------------------------------------------------------------------
    // -------------------------------- TS-Info ----------------------------------------
    // ---------------------------------------------------------------------------------

    auto ts_sizer = new wxGridSizer(2);

    label_weekday = new wxStaticText(this, wxID_ANY, wxT("Weekday"));
    label_startTime = new wxStaticText(this, wxID_ANY, wxT("Start Time"));
    label_duration = new wxStaticText(this, wxID_ANY, wxT("Duration"));

    std::vector<wxString> weekdays;
    for(auto &pair : CalendarGenerator::weekdayStrings) {
        weekdays.push_back(pair.first);
    }

    combo_weekday = new wxComboBox(this, ID_comboWeekday, weekdays.at(0), wxDefaultPosition, wxDefaultSize, 7, weekdays.data());
    time_startTime = new wxTimePickerCtrl(this, ID_timeStart);
    text_duration = new wxTextCtrl(this, ID_textDuration, "0");

    ts_sizer->Add(label_weekday);
    ts_sizer->Add(combo_weekday);

    ts_sizer->Add(label_startTime);
    ts_sizer->Add(time_startTime);

    ts_sizer->Add(label_duration);
    ts_sizer->Add(text_duration);



    // ---------------------------------------------------------------------------------
    // -------------------------------- Layout -----------------------------------------
    // ---------------------------------------------------------------------------------


    auto sizer_button = new wxBoxSizer(wxHORIZONTAL);

    button_save = new wxButton(this, IDTRD_buttonSave, wxT("Save"));
    button_cancel = new wxButton(this, IDTRD_buttonCancel, wxT("Cancel"));

    sizer_button->Add(button_save);
    sizer_button->Add(button_cancel);

    sizer_top->Add(ts_sizer, 1, wxEXPAND);
    sizer_top->Add(sizer_button, 0);

    Bind(wxEVT_BUTTON, &TimeslotDialog::OnCancel, this, IDTRD_buttonCancel);
    Bind(wxEVT_BUTTON, &TimeslotDialog::OnSave, this, IDTRD_buttonSave);

    SetSizerAndFit(sizer_top);
    Centre();

}

void TimeslotDialog::OnCancel(wxCommandEvent &event) {

    EndModal(1);

}

void TimeslotDialog::OnSave(wxCommandEvent &event) {

    auto weekdayInput = combo_weekday->GetValue();
    auto weekday = CalendarGenerator::weekdayStrings.at(weekdayInput.ToStdString(wxConvUTF8));

    auto startInput = time_startTime->GetValue().FormatISOTime().ToStdString(wxConvUTF8);

    auto duration = std::stoi(text_duration->GetValue().ToStdString(wxConvUTF8));

    calendarGenerator.createTimeslotRule(weekday, startInput, duration);

    EndModal(0);

}
