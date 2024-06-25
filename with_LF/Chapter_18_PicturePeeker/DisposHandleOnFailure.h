/* Chapter 18 - PicturePeeker */
/* DisposHandleOnFailure.h */

#pragma once

#include "THandleFailure..h"

// disposes the handle passed in the constructor on failure 
class TDisposHandleOnFailure: public THandleFailure { 
public:
    TCL_DECLARE_CLASS 
    TDisposHandleOnFailure(Handle h);
    -TDisposHandleOnFailure();
private:
    Handle fHandle;
};