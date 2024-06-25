/* Chapter 18 - PicturePeeker */
/* THandleLocker.cp */

// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.

#ifdef TCL_PCH 
#include <TCLHeaders>
#endif

#include "THandleLocker.h"

TCL_DEFINE_CLASS_M0(THandleLocker);

THandleLocker::THandleLocker(Handle h) {
    fHandle =h;
    fState =::HGetState(fHandle);
    ::HLock(h);
}

THandleLocker::-THandleLocker() {
    ::HSetState(fHandle, fState);
}
