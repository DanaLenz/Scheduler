//
// Created by dana on 24.03.21.
//

#include "schedulerApp.h"
#include "MainFrame.h"

#include <wx/app.h>

bool schedulerApp::OnInit() {

    if(!wxApp::OnInit())
        return false;

    MainFrame *frame = new MainFrame();

    frame->Show(true);

    return true;

}