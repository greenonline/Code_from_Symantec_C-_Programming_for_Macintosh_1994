/* Chapter 20 - C++Calc */
/* CButtonWithFontAndSize.h */



#pragma once 

#include <CButton.h>

class CButtonWithFontAndSize: public CButton { 
public:
    CButtonWithFontAndSize(short aWidth, short aHeight,
      short aHEncl, short aVEncl,
      StringPtr title, Boolean fVisible, short procID,
      CView *anEnclosure, CBureaucrat *aSupervisor,
      StringPtr fontName, short fontSize);

    virtual void Draw(Rect *area);

private:
    short fFont;
    short fFontSize; 
};

