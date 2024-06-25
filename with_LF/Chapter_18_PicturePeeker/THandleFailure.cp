/* Chapter 18 - PicturePeeker */
/* THandleFailure.cp */

// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved.
#ifdef TCL_PCH 
#include <TCLHeaders> 
#endif

#include "THandleFailure.h"

TCL_DEFINE_CLASS_M0(THandleFailure);

THandleFailure::THandleFailure() {
    fSucceeded = FALSE;
    TCL_END_CONSTRUCTOR
}

THandleFailure::-THandleFailure() {
    TCL_START_DESTRUCTOR
}

void THandleFailure::Success() {
    fSucceeded = true;
}