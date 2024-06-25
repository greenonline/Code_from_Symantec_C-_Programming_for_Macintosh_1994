/* Chapter 20 - C++Calc */
/* CCalculatorApp.cp */


// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved.
/*****
* CCalculatorApp.c
* *
*****/



#include "CCalculatorApp.h" 
#include "CCalculatorPane.h" 
#include <CDirector.h>
#include "CSaveRestoreSizeWindow.h"

const short kExtraMasters = 1;
const Size kRainyDayFund = 20480;
const Size kCriticalBalance = 20480;
const Size kToolboxBalance = 20480;
const short kWINDStarter = 500;

CCalculatorApp::CCalculatorApp() CAboutBoxApplication(kExtraMasters, kRainyDayFund, kCriticalBalance, kToolboxBalance) 
{
    TCL_END_CONSTRUCTOR;
}



void CCalculatorApp::StartUpAction(short numPreloads)
{
    CAboutBoxApplication::StartUpAction(numPreloads);

    const Boolean kFloatingWindow = TRUE;
    const short kMinWindowHeight = 30;
    const short kMinWindowWidth = 30;

    CDirector *aDirector =new CDirector(this);

    CSaveRestoreSizeWindow *aWindow =
new CSaveRestoreSizeWindow(kWINDStarter, !kFloatingWindow, aDirector);
    aDirector->itsWindow = aWindow;

    aWindow->Select();
    CCalculatorPane *thePane =
new CCalculatorPane(aWindow, aDirector, 0, 0, 0, 0,
sizELASTIC, sizELASTIC);
    thePane->FitToEnclosure(TRUE, TRUE);
    aDirector->itsGopher = thePane;
    thePane->BecomeGopher(TRUE);
}

