//
// Created by dana on 02.04.21.
//

#include "Menubar.h"


Menubar::Menubar(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{

    menubar = new wxMenuBar;
    file = new wxMenu;
    file->Append(wxID_EXIT, wxT("&Quit"));
    menubar->Append(file, wxT("&File"));
    SetMenuBar(menubar);

    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Menubar::OnQuit));
    Centre();

}

void Menubar::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}
