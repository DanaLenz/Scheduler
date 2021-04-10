//
// Created by dana on 09.04.21.
//

#include "TagPanel.h"

TagPanel::TagPanel(wxWindow *parent, TagManager &tm, TaskManager &tam, CalendarGenerator &cg) : wxPanel(parent), tagManager(tm), taskManager(tam), calendarGenerator(cg) {

    wxBoxSizer *sizer_top = new wxBoxSizer(wxVERTICAL);

    taglistctrl = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(1200,300));
    taglistctrl->AppendTextColumn("Tag");
    taglistctrl->AppendTextColumn("Associated Tasks");
    taglistctrl->AppendTextColumn("Associated TSRs");
    sizer_top->Add(taglistctrl);

    text_name = new wxTextCtrl(this, IDTAGS_Name);
    sizer_top->Add(text_name);

    wxBoxSizer *sizer_buttons = new wxBoxSizer(wxHORIZONTAL);

    button_add = new wxButton(this, IDTAGS_Add, wxString("&Add"));
    button_delete = new wxButton(this, IDTAGS_Delete, wxString("Delete"));
    button_edit = new wxButton(this, IDTAGS_Edit, wxString("Edit"));

    Bind(wxEVT_BUTTON, &TagPanel::OnAdd, this, IDTAGS_Add);
    Bind(wxEVT_BUTTON, &TagPanel::OnDelete, this, IDTAGS_Delete);
    Bind(wxEVT_BUTTON, &TagPanel::OnEdit, this, IDTAGS_Edit);

    sizer_buttons->Add(button_add);
    sizer_buttons->Add(button_delete);
    sizer_buttons->Add(button_edit);

    sizer_top->Add(sizer_buttons);

    refreshTags();
    SetSizerAndFit(sizer_top);

}

void TagPanel::OnAdd(wxCommandEvent &event) {

    auto string = text_name->GetValue().ToStdString(wxConvUTF8);
    tagManager.addTag(string);
    refreshTags();

}

void TagPanel::OnEdit(wxCommandEvent &event) {

}

void TagPanel::OnDelete(wxCommandEvent &event) {

    auto row = taglistctrl->GetSelectedRow();
    auto tag = taglistctrl->GetTextValue(row, 0).ToStdString(wxConvUTF8);
    tagManager.deleteTag(tag);
    refreshTags();
}

void TagPanel::refreshTags() {

    taglistctrl->DeleteAllItems();

    for(const auto &tag : tagManager.getAllTags()) {
        addTag(tag);
    }


}

void TagPanel::addTag(const std::string &tag) {

    wxVector<wxVariant> data;

    data.push_back(tag);

    wxString tagTasks = "";
    for(const auto &el : tagManager.getTasksOfTag(tag)) {
        tagTasks.append(taskManager.getTaskRule(el).getName());
        tagTasks.append(" ");
    }

    data.push_back(tagTasks);


    wxString tagTSRs = "";
    for(const auto &el : tagManager.getTimeslotsOfTag(tag)) {
        tagTSRs.append(el->getWeekday().as_long_string());
        tagTSRs.append(", ");
        tagTSRs.append(boost::posix_time::to_simple_string(el->getStartTime()));
        tagTasks.append(" ");
    }

    data.push_back(tagTSRs);

    taglistctrl->AppendItem(data);

}
