//
// Created by dana on 09.04.21.
//

#ifndef SCHEDULER_TAGPANEL_H
#define SCHEDULER_TAGPANEL_H

#include <wx/wx.h>
#include <wx/dataview.h>
#include "../Core/TagManager.h"

class TagPanel : public wxPanel {

public:
    TagPanel(wxWindow * parent, TagManager &tagManager, TaskManager &taskManager, CalendarGenerator &calGen);

protected:
    void OnAdd(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
    void OnDelete(wxCommandEvent& event);
    void refreshTags();

private:

    TagManager &tagManager;
    TaskManager &taskManager;
    CalendarGenerator &calendarGenerator;

    wxTextCtrl *text_name;
    wxStaticText *label_name;

    wxDataViewListCtrl *taglistctrl;

    wxButton *button_add;
    wxButton *button_edit;
    wxButton *button_delete;

    void addTag(const std::string &tag);


};


enum {
    IDTAGS_Name,
    IDTAGS_Add,
    IDTAGS_Edit,
    IDTAGS_Delete
};


#endif //SCHEDULER_TAGPANEL_H
