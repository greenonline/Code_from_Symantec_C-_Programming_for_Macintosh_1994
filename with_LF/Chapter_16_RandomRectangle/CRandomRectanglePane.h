/* Chapter 16 - RandomRectangle */
/* CRandomRectanglePane.h */

#pragma once

#include <CPane.h> 
#include "TRandom.h"

class CRandomRectanglePane: public CPane { public:
CRandomRectanglePane(CView *anEnclosure, CBureaucrat *aSupervisor,
short aWidth, short aHeight,
short aHEncl, short aVEncl,
SizingOption aHSizing, SizingOption aVSizing);

 virtual void Dawdle(long *maxSleep);

protected: 
    virtual void DrawRectangleinRandomColor(const Rect *r);
    virtual void  DrawRectangleinRandomPattern(const Rect *r);

private:
    TRandom fRandom;
};


