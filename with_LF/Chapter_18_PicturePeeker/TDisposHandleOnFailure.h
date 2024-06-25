/* Chapter 18 - PicturePeeker */
/* TDisposHandleOnFailure.h */


#pragma once

#include "TFailureObjects.h"

// disposes the handle passed in the constructor on failure 
class TDisposHandleOnFailure: public TCatchFailure { 
public:
    TDisposHandleOnFailure(Handle h);
protected:
    virtual void HandleFailure(OSErr err, long message); 
private:
    Handle fHandle;