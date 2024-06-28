/* Chapter 18 - PicturePeeker */
/* TWithFileOpen.cp */

// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved.

#ifdef TCL_PCH 
#include <TCLHeaders> 
#endif

#include "TWithFileOpen.h" 

TCL_DEFINE_CLASS_M0(TWithFileOpen);

TWithFileOpen::TWithFileOpen(CFile *theFile, SignedByte permission) {
    theFile->Open(permission); 
    fFile =theFile;
}

TWithFileOpen::~TWithFileOpen() {
    if (fFile != NULL) fFile->Close();
}