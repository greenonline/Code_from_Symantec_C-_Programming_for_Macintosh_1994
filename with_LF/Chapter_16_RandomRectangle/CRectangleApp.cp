/* Chapter 16 - RandomRectangle */
/* CRectangleApp.cp */



// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved. 

/*****
* CRectangleApp.cp
*
* *****/

#include "CRectangleApp.h" 
#include "CRandomRectanglePane.h" 
#include <CDirector.h>
#include <CWindow.h>

const short const Size const Size const Size
kExtraMasters 1i kRainyDayFund 45000; kCriticalBalance = 40000; kToolboxBalance = 20000;
CRectangleApp::CRectangleApp() : CApplication(kExtraMasters, kRainyDayFund,
kCriticalBalance, kToolboxBalance)

{
    TCL_END_CONSTRUCTOR
}

void CRectangleApp::StartUpAction(short numPreloads) {
CApplication::StartUpAction(numPreloads);
const short const Boolean const Boolean const Boolean
kWINDResourceID = 500;
kWindowFloats = kFitHorizontal kFitVertical =
TRUE; TRUE; TRUE;
CDirector *aDirector =new CDirector(this);
CWindow *aWindow =new CWindow(kWINDResourceID, lkWindowFloats, aDirector); aDirector->itsWindow = aWindow;
CRandomRectanglePane *thePane =
new CRandomRectanglePane(aWindow, aDirector, 0, 0, 0, 0,
sizELASTIC, sizELASTIC); thePane->FitToEnclosure(kFitHorizontal, kFitV ertical); aDirector->itsGopher = thePane; thePane->BecomeGopher(TRUE); // so it starts dawdling
}