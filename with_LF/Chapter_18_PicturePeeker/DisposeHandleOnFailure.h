/* Chapter 18 - PicturePeeker */
/* DisposeHandleOnFailure.h */
/* listed as TDisposHandleOnFailure.h on page 617 */
/* Renamed so as not to be included by any file because this file is useless. */
/* TFailureObjects.h is missing. */
/* This file seems to be a prototype of the file, now renamed as TDisposHandleOnFailure.h (PKA (listed in book, on page 619,  as) DisposeHandleOnFailure.h)


#pragma once

//#include "TFailureObjects.h"

// disposes the handle passed in the constructor on failure 
class TDisposHandleOnFailure: public TCatchFailure { 
public:
    TDisposHandleOnFailure(Handle h);
protected:
    virtual void HandleFailure(OSErr err, long message); 
private:
    Handle fHandle;