/* Chapter 19 - TickTock */
/* CClockApp.cp */



// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved.

/*****
* CClockApp.c
*
* *****/

#include "CClockApp.h"
#include "CClockPane.h"
#include <CDecorator.h>
#include <CDirector.h>
#include <CScrollPane.h>
#include <Commands.h>
#include "CSaveRestoreSizeWindow.h"

const short kExtraMasters = 1;
const Size kRainyDayFund  = 20480;
const Size kCriticalBalance  = 20480;
const Size kToolboxBalance = 20480;
const short kWINDStarter = 500;


CClockApp::CClockApp() : CAboutBoxApplication(kExtraMasters, kRainyDayFund,
kCriticalBalance, kToolboxBalance)
{
}


void CClockApp::StartUpAction(short numPreloads) {

    CAboutBoxApplication::StartUpAction(numPreloads);

    const Boolean kFloatingWindow = TRUE;
    const short kMinWindowHeight = 30;
    const short kMinWindowWidth = 30;
  

    CDirector *aDirector =new CDirector(this);

    CSaveRestoreSizeWindow *aWindow =
new CSaveRestoreSizeWindow(kWINDStarter, !kFloatingWindow, aDirector);
    aDirector->itsWindow = aWindow; 
    Rect sizeRect = aWindow->sizeRect; 
    sizeRect.top = kMinWindowHeight; 
    sizeRect.left = kMinWindowWidth; 
    aWindow->SetSizeRect(&sizeRect);

    aWindow->Select(); 
    CClockPane *thePane =
new CClockPane(aWindow, aDirector, 0, 0, 0, 0, sizELASTIC, sizELASTIC); thePane->FitToEnclosure(TRUE, TRUE);
    aDirector->itsGopher = thePane;
    thePane->BecomeGopher(TRUE);
}