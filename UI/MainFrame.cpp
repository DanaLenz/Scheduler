//
// Created by dana on 24.03.21.
//

#include "MainFrame.h"

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Test") {


    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Test, "&Hello");
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Ayo");


    Bind(wxEVT_MENU, &MainFrame::OnTest, this, ID_Test);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);

}


void MainFrame::OnExit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox("Ayyy ", "???", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnTest(wxCommandEvent& event) {
    wxMessageBox("Test success.");
}