/* Chapter 18 - PicturePeeker */
/* THandleLocker.h */


#pragma once

#include "TCL.h" 
#include <Memory.h>

class THandleLocker TCL_AUTO_DESTRUCT_OBJECT { 
public:
    TCL_DECLARE_CLASS
    THandleLocker(Handle h);
    ~THandleLocker();
private:
    Handle fHandle;
    char fState;
};