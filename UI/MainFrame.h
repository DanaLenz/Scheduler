//
// Created by dana on 24.03.21.
//

#ifndef SCHEDULER_MAINFRAME_H
#define SCHEDULER_MAINFRAME_H

#include <wx/wxprec.h>
#include <wx/wx.h>

class MainFrame : public wxFrame {

public:
    MainFrame();
    //virtual ~MainFrame();

protected:

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnTest(wxCommandEvent& event);

private:


};

enum {
    ID_Test = 1
};



#endif //SCHEDULER_MAINFRAME_H
