//
// Created by dana on 01.04.21.
//

#include "TimeslotFrame.h"
#include "TimeslotDialog.h"

TimeslotFrame::TimeslotFrame(wxWindow * parent, CalendarGenerator &cal) : wxPanel(parent),
                                                               calendar(cal) {


    // ---------------------------------------------------------------------------------

    wxBoxSizer *sizer_top = new wxBoxSizer(wxVERTICAL);

    // ---------------------------------------------------------------------------------

    wxBoxSizer *sizer_timeslotlist = new wxBoxSizer(wxHORIZONTAL);

    timeslotlistctrl = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(500,300));

    timeslotlistctrl->AppendTextColumn("Weekday");
    timeslotlistctrl->AppendTextColumn("Start Time");
    timeslotlistctrl->AppendTextColumn("Duration");

    sizer_timeslotlist->Add(timeslotlistctrl, 1, wxEXPAND);

    sizer_top->Add(sizer_timeslotlist, 1, wxEXPAND);


    // ---------------------------------------------------------------------------------

    wxButton *button_add = new wxButton(this, ID_TS_Add, wxString("&Add"));
    wxButton *button_delete = new wxButton(this, ID_TS_Delete, wxString("Delete"));
    wxButton *button_edit = new wxButton(this, ID_TS_Edit, wxString("Edit"));

    Bind(wxEVT_BUTTON, &TimeslotFrame::OnAdd, this, ID_TS_Add);
    Bind(wxEVT_BUTTON, &TimeslotFrame::OnDelete, this, ID_TS_Delete);
    Bind(wxEVT_BUTTON, &TimeslotFrame::OnEdit, this, ID_TS_Edit);

    wxBoxSizer *sizer_buttons = new wxBoxSizer(wxHORIZONTAL);
    sizer_buttons->Add(button_add);
    sizer_buttons->Add(button_delete);
    sizer_buttons->Add(button_edit);

    sizer_top->Add(sizer_buttons, 0, wxALIGN_CENTER_HORIZONTAL);

    refreshTSRules();
    SetSizerAndFit(sizer_top);

}



void TimeslotFrame::OnAdd(wxCommandEvent& event) {

    TimeslotDialog *tsd = new TimeslotDialog(this, calendar);

    tsd->ShowModal();

    refreshTSRules();

}

void TimeslotFrame::OnEdit(wxCommandEvent &event) {

    auto row = timeslotlistctrl->GetSelectedRow();
    //std::string stid = tasklistctrl->GetTextValue(row, 0).ToStdString(wxConvUTF8);
    //auto id = std::stoi(stid);
    //auto &tr = taskManager.getTaskRule(id);
    //TaskRuleDialog *trd = new TaskRuleDialog(this, tr);
    //trd->ShowModal();

    refreshTSRules();
}

void TimeslotFrame::OnDelete(wxCommandEvent &event) {
/*
    auto row = tasklistctrl->GetSelectedRow();
    std::string stid = tasklistctrl->GetTextValue(row, 0).ToStdString(wxConvUTF8);
    auto id = std::stoi(stid);
    taskManager.deleteTaskRule(id);
    tasklistctrl->DeleteItem(row);*/

}

void TimeslotFrame::addTimeslotRule(const TimeslotRule* const timeslotRule) {

    wxVector<wxVariant> data;

    auto wkd = timeslotRule->getWeekday().as_long_string();
    data.push_back(wxVariant(wkd));

    auto startTime = boost::posix_time::to_simple_string(timeslotRule->getStartTime());
    data.push_back(wxVariant(startTime));

    auto duration = boost::posix_time::to_simple_string(timeslotRule->getDuration());
    data.push_back(wxVariant(duration));


    timeslotlistctrl->AppendItem(data);

}

void TimeslotFrame::refreshTSRules() {

    timeslotlistctrl->DeleteAllItems();

    for(const auto &tsr : calendar.getTimeslotRules()) {

        addTimeslotRule(tsr);
    }
}
