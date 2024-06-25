/* Chapter 18 - PicturePeeker */
/* DeleteOnCompletion.h */


#pragma once 
#include "TCL.h"

// disposes the handle passed in the constructor on failure 
template<class T> class TDeleteOnCompletion TCL_AUTO_DESTRUCT_OBJECT { 
public:
    TCL_DECLARE_CLASS 
    TDeleteOnCompletion(T *object); 
    ~TDeleteOnCompletion();
private:
    T *fObject;
};

TDeleteOnCompletion::TDeleteOnCompletion() {
    fObject =object;
    TCL_END_CONSTRUCTOR
}

TDeleteOnCompletion::-TDeleteOnCompletion() {
    TCL_START_DESTRUCTOR
    delete fObject;
}
