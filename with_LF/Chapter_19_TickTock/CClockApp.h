/* Chapter 19 - TickTock */
/* CClockApp.h */


/*****
* CClockApp.h
*
* Application class for a typical application.
*
* *****/
#pragma once
#include "CAboutBoxApplication.h"

class CClockApp: public CAboutBoxApplication {
public:
    CClockApp();
    virtual void StartUpAction(short numPreloads);
};