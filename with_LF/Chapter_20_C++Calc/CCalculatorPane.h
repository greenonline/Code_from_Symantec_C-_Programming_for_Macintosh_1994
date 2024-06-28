/* Chapter 20 - C++Calc */
/* CCalculatorPane.h */


#pragma once

#include <CPane.h> 
#include "Calculator.h" 
#include "CFloatText.h" 
#include <CButton.h>

class CCalculatorPane: public CPane { 
public:
    CCalculatorPane(CView *anEnclosure,
CBureaucrat *aSupervisor,
short aWidth, short aHeight,
short aHEncl, short aVEncl,
SizingOption aHSizing, SizingOption aVSizing);

    virtual void UpdateMenus();
    virtual void DoCommand(long theCommand);
    virtual void DoKeyDown(char theChar, Byte keyCode, EventRecord *macEvent); 
    virtual void Draw(Rect *r);

protected:
    enum {cmdFirstCommand = 1025,
    cmdAdd = cmdFirstCommand, cmdMultiply, cmdDivide, cmdSubtract, cmdEnter,
    cmdPeriod, cmdE, cmdClearEntry, cmdChangeSign, 
    cmd0, cmd1, cmd2, cmd3,
    cmd4, cmd5, cmd6, cmd7, cmd8, cmd9, cmdLastCommand = cmd9 };

    virtual void UpdateDisplay();
    virtual void EnterCurrentNumber();
    virtual void CreateCommandButton(short rowNumber, short colNumber, long command);

private:
    TCalculator fCalculator;
    CFloatText *fCalcDisplay;
    unsigned char fCurrentNumber[9];
    CButton *fButtons[cmdLastCommand - cmdFirstCommand + 1];
};