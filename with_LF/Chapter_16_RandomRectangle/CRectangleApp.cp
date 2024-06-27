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

const short kExtraMasters = 1;
const Size kRainyDayFund = 45000;
const Size kCriticalBalance = 40000;
const Size kToolboxBalance = 20000;

CRectangleApp::CRectangleApp() : CApplication(kExtraMasters, kRainyDayFund,
kCriticalBalance, kToolboxBalance)
{
    TCL_END_CONSTRUCTOR
}

void CRectangleApp::StartUpAction(short numPreloads) 
{
    CApplication::StartUpAction(numPreloads);

    const short kWINDResourceID = 500;
    const Boolean kWindowFloats = TRUE;
    const Boolean kFitHorizontal = TRUE;
    const Boolean kFitVertical = TRUE;
  
    CDirector *aDirector =new CDirector(this);

    CWindow *aWindow =new CWindow(kWINDResourceID, !kWindowFloats, aDirector); 
    aDirector->itsWindow = aWindow;

    CRandomRectanglePane *thePane = new CRandomRectanglePane(aWindow, aDirector, 0, 0, 0, 0, sizELASTIC, sizELASTIC); 
    thePane->FitToEnclosure(kFitHorizontal, kFitVertical); 
    aDirector->itsGopher = thePane; 
    thePane->BecomeGopher(TRUE); // so it starts dawdling
}