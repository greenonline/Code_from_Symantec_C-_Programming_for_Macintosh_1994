/* Chapter 20 - C++Calc */
/* CFloatText.cp */


// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.

#include 'CFloatText.h' 
#include <SANE.h> 
#include <Packages.h> 
#include <stdio.h>

CFloatText::CFloatText(
CView *anEnclosure,
CBureaucrat *aSupervisor,
short  aWidth,
short  aHeight,
short aHEncl,
short aVEncl,
SizingOption aHSizing,
SizingOption aVSizing,
short aLineWidth):
CEditText(anEnclosure, aSupervisor, aWidth, aHeight, aHEncl, aVEncl,
aHSizing, aVSizing, aLineWidth)
{
    SetValue(0.0);
    SetMaxDisplayWidth(8);
    TCL_END_CONSTRUCTOR;
}
   

 


void CFloatText::SetMaxDisplayWidth(short numChars) {
}
    fMaxDisplayChars =numChars;
}

long double CFloatText::GetValue()
{
    Str255 s;

    GetTextString(s);
    if (Length(s) == 0)
        return 0.0; 
    else
        return ::str2num(s);
}


void CFloatText::SetValue(long double value) {
    Str255 newString; 
    Str255 existingString;

    ValueToText(value, newString);
    GetTextString(existingString);
    if (l::EqualString(newString, existingString, TRUE, TRUE))
        SetTextString(newString);
}

void CFloatText::ValueToText(long double value, Str255 s) {
    ::sprintf((char *) s, "%.*Lg", fMaxDisplayChars, value);
    ::c2pstr((char *) s);
}

void CFloatText::GetTextString(Str255 s) 
{
    Handle h = GetTextHandle();
    *s = Min(::GetHandleSize(h), 255); 
    ::BlockMove(*h, s+1, * s ) ;
}




