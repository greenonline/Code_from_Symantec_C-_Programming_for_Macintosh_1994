/* Chapter 20 - C++Calc */
/* CQuitApplicationChore.cp */

// Copyright© 1993·94, Neil Rhodes and Julie McKeehan. All rights reserved. 

#include "CQuitApplicationChore.h"
#include <CApplication.h>

extern CApplication *gApplication;

void CQuitApplicationChore::Perform(long *maxSleep) {
    gApplication->Quit();
}

