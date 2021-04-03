//
// Created by dana on 02.04.21.
//

#ifndef SCHEDULER_MENUBAR_H
#define SCHEDULER_MENUBAR_H


#include "wx/wx.h"

class Menubar : public wxFrame {

public:
    Menubar(const wxString &title);

    void OnQuit(wxCommandEvent& event);

    wxMenuBar *menubar;
    wxMenu *file;

};


#endif //SCHEDULER_MENUBAR_H
