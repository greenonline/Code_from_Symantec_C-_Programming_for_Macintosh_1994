/* Chapter 20 - C++Calc */
/* CFloatText.h */

#pragma once

#include <CEditText.h>

class CFloatText: public CEditText { 
public:
    CFloatText(

CView *anEnclosure,
CBureaucrat *aSupervisor,
short  aWidth,
short  aHeight,
short aHEncl,
short aVEncl,
SizingOption aHSizing,
SizingOption aVSizing,
short aLineWidth);

    virtual long double GetValue();
    virtual void SetValue(long double value); 
    virtual void  GetTextString(Str255 s); 
    virtual void SetMaxDisplayWidth(short numChars);
protected: 
    virtual void ValueToText(long double value, Str255 s);
private:
    short fMaxDisplayChars;

};
