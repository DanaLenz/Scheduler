//
// Created by dana on 06.04.21.
//

#ifndef SCHEDULER_PROJECTPANEL_H
#define SCHEDULER_PROJECTPANEL_H

#include <wx/wx.h>
#include <wx/dataview.h>
#include "../Core/Tasks/TaskManager.h"
#include "../Core/Tasks/Project.h"

class ProjectPanel : public wxPanel {

public:
    ProjectPanel(wxWindow * parent, TaskManager &tm);
    void addProject(const ID id, const Project* const project);
    //virtual ~TaskFrame();

protected:

    void OnAdd(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
    void OnDelete(wxCommandEvent& event);
    void refreshProjects();

private:

    wxDataViewListCtrl *projectlistctrl;
    TaskManager& taskManager;
    std::map<void*, ID> itemIDs;

};

enum {
    ID_PROJECT_Add = 2,
    ID_PROJECT_Delete = 3,
    ID_PROJECT_Edit = 4
};


#endif //SCHEDULER_PROJECTPANEL_H
