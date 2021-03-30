//
// Created by dana on 24.03.21.
//

#ifndef SCHEDULER_MAINFRAME_H
#define SCHEDULER_MAINFRAME_H

#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/dataview.h>
#include "../Core/Tasks/TaskManager.h"

class MainFrame : public wxFrame {

public:
    MainFrame(const wxString &title, TaskManager &tm);
    void addTaskRule(const ID id, const TaskRule* const taskRule, const Project * const project);
    //virtual ~MainFrame();

protected:

    //void OnExit(wxCommandEvent& event);
    //void OnAbout(wxCommandEvent& event);
    void OnTest(wxCommandEvent& event);
    void OnAdd(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
    void OnDelete(wxCommandEvent& event);
    void refreshTaskRules();

private:

    wxDataViewListCtrl *tasklistctrl;
    TaskManager& taskManager;
    std::map<void*, ID> itemIDs;

};

enum {
    ID_Test = 1,
    ID_Add = 2,
    ID_Delete = 3,
    ID_Edit = 4
};




#endif //SCHEDULER_MAINFRAME_H
