/* Chapter 18 - PicturePeeker */
/* TDisposHandleOnFailure.cp */



// Copyright © 1993, Neil Rhodes and Julie McKeehan. All rights reserved. 

#include "TDisposHandleOnFailure.h"

TCL_DEFINE_CLASS_M1(TDisposHandleOnFailure, THandleFailure); 

TDisposHandleOnFailure::TDisposHandleOnFailure(Handle h)
{
    fHandle = h;
    TCL_END_CONSTRUCTOR
}

TDisposHandleOnFailure::~TDisposHandleOnFailure()
{
    TCL_START_DESTRUCTOR
    if (!fSucceeded && fHandle != NULL)
        ::DisposHandle(fHandle);
}