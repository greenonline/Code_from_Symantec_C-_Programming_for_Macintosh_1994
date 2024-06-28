/* Chapter 20 - C++Calc */
/* TGrafPortSetter.h */


#pragma once

#include <QuickDraw.h> 
#include <TCL.h>

class TGrafPortSetter TCL_AUTO_DESTRUCT_OBJECT { 
public:
    TGrafPortSetter(GrafPtr newGrafPtr); 
    virtual ~TGrafPortSetter();
private:
    GrafPtr fOldGrafPtr;
};


inline TGrafPortSetter::TGrafPortSetter(GrafPtr newGrafPtr)
{
    ::GetPort(&fOldGrafPtr); 
    ::SetPort(newGrafPtr);
    TCL_END_CONSTRUCTOR;
}
inline TGrafPortSetter::~TGrafPortSetter()
{
    TCL_START_DESTRUCTOR; 
    ::SetPort(fOldGrafPtr);
}
