/* Chapter 19 - TickTock */
/* Clock.cp */


// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved. 
/******************************************************************************
Clock.c
******************************************************************************/

#include "CClockApp.h"

void main() {
    CClockApp *clockApp;
    clockApp = new CClockApp; 
    clockApp->Run(); 
    clockApp->Exit();
}