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
void CRandomRectanglePane::DrawRectangleinRandomColor(const Rect *r) {
RGBColor aColor; PixPatHandle myPixPat;
aColor.red = fRandom.Value(); fRandom.Advance();
aColor.blue =fRandom.Value(); fRandom.Advance();
aColor.green =fRandom.Value(); fRandom.Advance();
myPixPat =NewPixPat(); MakeRGBPat(myPixPat, &aColor); FillCRect(r, myPixPat); DisposPixPat(myPixPat);
}

void CRandomRectanglePane::DrawRectangleinRandomPattern(const Rect *r) {
Pattern aPattern;
GetindPattern(&aPattern, sysPatListID, fRandom.ValueinRange(1, 31)); fRandom.Advance();
FillRect(r, &aPattern);
}
void CRandomRectanglePane::Dawdle(long *maxSleep) {
Rect Point Point LongRect
r;
p1 j
p2; frameSize;
GetFrame(&frameSize);
p1.h = fRandom.ValueinRange(frameSize.left, frameSize.right); fRandom.Advance();
p1.v =fRandom.ValueinRange(frameSize.top, frameSize.bottom);


 fRandom.Advance()i
p2.h = fRandom.ValuelnRange(frameSize.left, frameSize.right); fRandom.Advance()i
p2.v = fRandom.ValuelnRange(frameSize.top, frameSize.bottom); fRandom.Advance();
::Pt2Rect(p1, p2, &r);
Prepare(); II prepare coordinate system for drawing
if (gSystem.hasColorQD) DrawRectanglelnRandomColor(&r);
else DrawRectanglelnRandomPattern(&r);
*maxSleep =20; II one rectangle every 113 second
}
