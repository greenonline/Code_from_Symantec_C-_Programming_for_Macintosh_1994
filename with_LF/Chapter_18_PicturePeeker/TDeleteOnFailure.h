/* Chapter 18 - PicturePeeker */
/* DeleteOnFailure.h */


#pragma once

#include "THandleFailure.h"

// disposes the handle passed in the constructor on failure

template<class T> class TDeleteOnFailure: public THandleFailure { 
public:
    TDeleteOnFailure(T *object)
    {
        fObject = object; 
        TCL_END_CONSTRUCTOR
    };
    ~TDeleteOnFailure()
    {
        TCL_START_DESTRUCTOR
        if (!fSucceeded)
            delete fObject;
    };
private:
    T *fObject;
};
