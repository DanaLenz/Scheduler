//
// Created by dana on 24.03.21.
//

#ifndef SCHEDULER_TASKFRAME_H
#define SCHEDULER_TASKFRAME_H

#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/dataview.h>
#include "../Core/Tasks/TaskManager.h"

class TaskFrame : public wxPanel {

public:
    TaskFrame(wxWindow * parent, TaskManager &tm);
    void addTaskRule(const ID id, const TaskRule* const taskRule, const Project * const project);
    //virtual ~TaskFrame();

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
    ID_TASK_Add = 2,
    ID_TASK_Delete = 3,
    ID_TASK_Edit = 4
};




#endif //SCHEDULER_TASKFRAME_H
