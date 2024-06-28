/* Chapter 20 - C++Calc */
/* CQuitOnCloseWindow.h */

#pragma once 

#include <CWindow.h>

class CQuitOnCloseWindow: public CWindow { 
public:
    CQuitOnCloseWindow(short WINDid, Boolean aFloating, CDirector *aSupervisor);
    virtual ~CQuitOnCloseWindow(); 
};
