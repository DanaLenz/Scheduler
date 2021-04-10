//
// Created by dana on 08.04.21.
//

#ifndef SCHEDULER_TIMETABLE_H
#define SCHEDULER_TIMETABLE_H

#include <wx/wx.h>
#include <wx/grid.h>

class Timetable : public wxPanel {

public:
    //Timetable(wxWindow *parent, Schedule &sch);
    //virtual ~TaskFrame();

protected:


private:

    wxGrid grid_timetable;
};

enum {
};



#endif //SCHEDULER_TIMETABLE_H
