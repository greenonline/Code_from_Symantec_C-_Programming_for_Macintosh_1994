/* Chapter 18 - PicturePeeker */
/* TDisposHandleOnFailure.h */
/* was listed under DisposeHandleOnFailure.h on page 619 */
/* This file is good and works */

#pragma once

#include "THandleFailure.h"

// disposes the handle passed in the constructor on failure 
class TDisposHandleOnFailure: public THandleFailure { 
public:
    TCL_DECLARE_CLASS 
    TDisposHandleOnFailure(Handle h);
    ~TDisposHandleOnFailure();
private:
    Handle fHandle;
};