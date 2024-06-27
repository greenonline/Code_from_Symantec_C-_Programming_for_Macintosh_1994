/* Chapter 16 - RandomRectangle */
/* CRandomRectanglePane.cp */

// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved. 

#include <Global.h>
#include "CRandomRectanglePane.h"

CRandomRectanglePane::CRandomRectanglePane(CView *anEnclosure, CBureaucrat *aSupervisor,
short aWidth, short aHeight,
short aHEncl, short aVEncl,
SizingOption aHSizing, SizingOption aVSizing) : CPane(anEnclosure, aSupervisor, aWidth, aHeight,
aHEncl, aVEncl, aHSizing, aVSizing)
{
    TCL_END_CONSTRUCTOR
}

void CRandomRectanglePane::DrawRectangleInRandomColor(const Rect *r) {
    RGBColor aColor; 
    PixPatHandle myPixPat;

    aColor.red = fRandom.Value(); 
    fRandom.Advance();
    aColor.blue =fRandom.Value(); 
    fRandom.Advance();
    aColor.green =fRandom.Value(); 
    fRandom.Advance();

    myPixPat =NewPixPat(); 
    MakeRGBPat(myPixPat, &aColor); 
    FillCRect(r, myPixPat); 
    DisposPixPat(myPixPat);
}

void CRandomRectanglePane::DrawRectangleInRandomPattern(const Rect *r) 
{
    Pattern aPattern;

    GetIndPattern(&aPattern, sysPatListID, fRandom.ValueInRange(1, 31)); 
    fRandom.Advance();
    FillRect(r, &aPattern);
}

void CRandomRectanglePane::Dawdle(long *maxSleep) 
{
    Rect r;
    Point p1;
    Point p2; 
    LongRect frameSize;

    GetFrame(&frameSize);

    p1.h = fRandom.ValueInRange(frameSize.left, frameSize.right); 
    fRandom.Advance();
    p1.v =fRandom.ValueInRange(frameSize.top, frameSize.bottom);
    fRandom.Advance();
    p2.h = fRandom.ValueInRange(frameSize.left, frameSize.right); 
    fRandom.Advance();
    p2.v = fRandom.ValueInRange(frameSize.top, frameSize.bottom); 
    fRandom.Advance();

    ::Pt2Rect(p1, p2, &r);

    Prepare(); // prepare coordinate system for drawing

    if (gSystem.hasColorQD)
        DrawRectangleInRandomColor(&r);
    else 
        DrawRectangleInRandomPattern(&r);

    *maxSleep =20; // one rectangle every 113 second
}
