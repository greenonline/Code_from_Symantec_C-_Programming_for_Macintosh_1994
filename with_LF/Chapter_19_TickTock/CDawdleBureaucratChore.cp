/* Chapter 19 - TickTock */
/* CDawdleBureaucratChore.cp */


// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved. 

#include "CDawdleBureaucratChore.h"

CDawdleBureaucratChore::CDawdleBureaucratChore(CBureaucrat *theBureaucrat)
{
    fBureaucratToDawdle =theBureaucrat;
}
void CDawdleBureaucratChore::Perform(long *maxSleep)
{

    fBureaucratToDawdle->Dawdle(maxSleep);
}