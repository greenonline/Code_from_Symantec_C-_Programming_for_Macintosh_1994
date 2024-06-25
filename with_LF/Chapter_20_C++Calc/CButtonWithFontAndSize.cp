/* Chapter 20 - C++Calc */
/* CButtonWithFontAndSize.cp */

// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.

#include "CButtonWithFontAndSize.h"

CButtonWithFontAndSize::CButtonWithFontAndSize(short aWidth, short aHeight,
short aHEncl, short aVEncl,
StringPtr title, Boolean fVisible, short procID,
CView *anEnclosure, CBureaucrat *aSupervisor, StringPtr fontName, short fontSize) : CButton(aWidth, aHeight, aHEncl, aVEncl, title, fVisible, useWFont | procID, anEnclosure, aSupervisor)
{
 
    short fontNumber;

    ::GetFNum(fontName, &fontNumber);
    fFont =fontNumber;
    fFontSize =fontSize;

    TCL_END_CONSTRUCTOR;
}

void CButtonWithFontAndSize::Draw(Rect *area)
{

    ::TextFont(fFont);
    ::TextSize(fFontSize);
    CButton::Draw(area);
}