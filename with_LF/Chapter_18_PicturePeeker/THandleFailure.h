/* Chapter 18 - PicturePeeker */
/* THandleFailure.h */


#pragma once 

#include <TCL.h>

/* calls HandleFailure if a failure occurred during its lifetime.
   Use like:
   {
       THandleFailure aFailureObject;
       // do something which could fail
       aFailureObject.Success();
   } // aFailureObject.HandleFailure() called if Success was not called.
*/

class THandleFailure TCL_AUTO_DESTRUCT_OBJECT { 
public:
    TCL_DECLARE_CLASS
    THandleFailure();
    ~THandleFailure(); // stack-based, don't need virtual

    void Success(); 
protected:
    Boolean fSucceeded;
};


