/* Chapter 20 - C++Calc */
/* CQuitOnCloseWindow.cp */


// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.

#include "CQuitOnCloseWindow.h" 
#include "CQuitApplicationChore.h" 
#include <CApplication.h>

extern CApplication *gApplication;

CQuitOnCloseWindow::CQuitOnCloseWindow(short WINDid, Boolean aFloating, CDirector *aSupervisor) :
CWindow(WINDid, aFloating, aSupervisor)
{
    TCL_END_CONSTRUCTOR;
}

CQuitOnCloseWindow::~CQuitOnCloseWindow() {
    TCL_START_DESTRUCTOR;
    gApplication->AssignUrgentChore(new CQuitApplicationChore);
}