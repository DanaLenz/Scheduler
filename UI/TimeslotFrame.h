//
// Created by dana on 01.04.21.
//

#ifndef SCHEDULER_TIMESLOTFRAME_H
#define SCHEDULER_TIMESLOTFRAME_H


#include <wx/wx.h>
#include <wx/dataview.h>
#include "../Core/Calendar/CalendarGenerator.h"

class TimeslotFrame : public wxPanel {

public:
    TimeslotFrame(wxWindow *parent, CalendarGenerator &cg);
    void addTimeslotRule(const TimeslotRule* const timeslotRule);
    //virtual ~TaskFrame();

protected:

    void OnAdd(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
    void OnDelete(wxCommandEvent& event);
    void refreshTSRules();

private:

    wxDataViewListCtrl *timeslotlistctrl;
    CalendarGenerator& calendar;

};

enum {
    ID_TS_Add = 2,
    ID_TS_Delete = 3,
    ID_TS_Edit = 4
};



#endif //SCHEDULER_TIMESLOTFRAME_H
