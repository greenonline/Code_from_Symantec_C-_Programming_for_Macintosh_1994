/* Chapter 18 - PicturePeeker */
/* TWithFileOpen.h */


#pragma once

#include "TCL.h" 
#include <CFile.h> 
#include <Types.h>

class TWithFileOpen TCL_AUTO_DESTRUCT_OBJECT { 
public:
    TCL_DECLARE_CLASS
    TWithFileOpen(CFile *theFile, SignedByte permission);
    -TWithFileOpen();

private:
    CFile *fFile;
};