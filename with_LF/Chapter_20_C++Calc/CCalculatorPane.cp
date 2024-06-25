/* Chapter 20 - C++Calc */
/* CCalculatorPane.cp */



// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.

#include "CCalculatorPane.h" 
#include <CBartender.h>
#include <CClipboard.h>
#include "CButtonWithFontAndSize.h" 
#include <CPaneBorder.h>
#include <Global.h>

extern CBartender *gBartender; 
extern CClipboard *gClipboard;

void CCalculatorPane::CreateCommandButton(short rowNumber, short colNumber, long command) {
    CButtonWithFontAndSize *aButton;
    Str255 buttonName;
    const short kButtonWidth = 18;
    const short kButtonHeight =16;
    const short kColumnWidth = 23;
    const short kColumnHeight =22;




    const short kLeftMargin = 9;
    const short kTopMargin = 29;
    const short kButtonTitleStringID = 1025;

    GetindString(buttonName, kButtonTitleStringID, command - cmdFirstCommand + 1 ) ;
    aButton= new CButtonWithFontAndSize(kButtonWidth, kButtonHeight,     kLeftMargin + (colNumber-1)* kColumnHeight,
kTopMargin + (rowNumber-1) * kColumnHeight,
buttonName, TRUE, 0, this, this, "\pGeneva", 9);
    aButton->SetClickCmd(command); 
    fButtons[command - cmdFirstCommand] = aButton;
}

CCalculatorPane::CCalculatorPane(CView *anEnclosure, CBureaucrat *aSupervisor, short aWidth, short aHeight,
short aHEncl, short aVEncl,
SizingOption aHSizing, SizingOption aVSizing) :
CPane(anEnclosure, aSupervisor, aWidth, aHeight,
aHEncl, aVEncl, aHSizing, aVSizing)
{
    canst short kFloatTextWidth= 86;
    canst short kFloatTextHeight = 20; 
    canst short kFloatTextLeftMargin = 10;
    canst short kFloatTextTopMargin = 9;

    wantsClicks = true;
    fCalcDisplay = new CFloatText(this, aSupervisor, kFloatTextWidth, kFloatTextHeight, kFloatTextLeftMargin, kFloatTextTopMargin, sizFIXEDSTICKY , sizFIXEDSTICKY , - 1 ) ;
    fCalcDisplay->Specify(kNotEditable, kNotSelectable, kNotStylable); 
    fCalcDisplay->SetFontName("\pMonaco"); fCalcDisplay->SetFontSize(9);
    fCalcDisplay->SetMaxDisplayWidth(sizeof(fCurrentNumber)-1);

    CPaneBorder *border= new CPaneBorder(kBorderFrame); border->SetPenSize(1, 1); 
    fCalcDisplay->SetBorder(border);

    CreateCommandButton(5, 2, cmd0);
    CreateCommandButton(5, 3, cmdPeriod);
    CreateCommandButton(5, 4, cmdEnter);

    CreateCommandButton(4, 1, cmd1);
    CreateCommandButton(4, 2, cmd2);
    CreateCommandButton(4, 3, cmd3);
    CreateCommandButton(4, 4, cmdChangeSign);

    CreateCommandButton(3, 1, cmd4);
    CreateCommandButton(3,  2, cmd5);
    CreateCommandButton(3,  3, cmd6);
    CreateCommandButton(3, 4, cmdAdd);

    CreateCommandButton(2, 1, cmd7);
    CreateCommandButton(2, 2, cmd8);
    CreateCommandButton(2, 3, cmd9);
    CreateCommandButton(2, 4, cmdSubtract);
    CreateCommandButton(1, 1, cmdClearEntry);
    CreateCommandButton(1,  2, cmdE);
    CreateCommandButton(1, 3, cmdDivide);
    CreateCommandButton(1, 4, cmdMultiply);

    Length(fCurrentNumber) = 0;
    TCL_END_CONSTRUCTOR;
}


void CCalculatorPane::UpdateDisplay() {
    fCalcDisplay->SetValue(fCalculator.GetX());
}

void CCalculatorPane::UpdateMenus() {
    CPane::UpdateMenus();

    if (Length(fCurrentNumber) > 0) gBartender->EnableCmd(cmdClear);
    gBartender->EnableCmd(cmdCopy);
    if (gClipboard->GetData('TEXT', NULL)> 0)
        gBartender->EnableCmd(cmdPaste);
}


 void CCalculatorPane::Draw(Rect *r)
{
    } 
}
if (lgSystem.hasColorQD)
    ::FillRect(r, &qd.ltGray);
else {
    RGBColor aColor;
    PixPatHandle myPixPat;

    aColor.red = aColor.green =aColor.blue = 0xaaaa; // light gray
    myPixPat =::NewPixPat();
    ::MakeRGBPat(myPixPat, &aColor);
    ::FillCRect(r,myPixPat);
    ::DisposPixPat(myPixPat);
}

void CCalculatorPane::DoCommand(long theCommand) {
    switch (theCommand) { 
        case cmdCopy:
            gClipboard->EmptyScrap();
            gClipboard->PutData('TEXT', fCalcDisplay->GetTextHandle());
            break;
        case cmdPaste: 
            Handle h; 
            Str255 s;

            gClipboard->GetData('TEXT'' &h);
            if (GetHandleSize(h) > sizeof(fCurrentNumber)-1)
                SetHandleSize(h, sizeof(fCurrentNumber)-1);
            fCalcDisplay->SetTextHandle(h);
            ::DisposHandle(h); fCalcDisplay->GetTextString(s);
            CopyPString(s, fCurrentNumber);
            break;

        case cmdClear:
            fButtons[cmdClearEntry - cmdFirstCommand]->SimulateClick(); 
            break;

        case cmdClearEntry:


            fCalcDisplay->SetValue(fCalculator.GetX());
            Length(fCurrentNumber) = 0;
            break;
         case cmdAdd:
            this->EnterCurrentNumber();
            fCalculator.Add();
            UpdateDisplay();
            break;
         case cmdSubtract:
            this->EnterCurrentNumber();
            fCalculator.Subtract();
            UpdateDisplay();
            break;
         case cmdMultiply:
            this->EntercurrentNumber();
            fCalculator.Multiply();
            UpdateDisplay();
            break;
         case cmdDivide:
            this->EnterCurrentNumber();
            fCalculator.Divide();
            UpdateDisplay();
            break;
         case cmdEnter:
            fCalculator.Enter(fCalcDisplay->GetValue());
            Length(fCurrentNumber) = 0;
            UpdateDisplay();
            break;
         case cmdChangeSign:
            Str255 minusSign "\p-" ;
            Str255 current;
            fCalcDisplay->GetTextString(current);
            if (Length(current) > 0 && current[1] == '-') {
                ::BlockMove(&current[2], &current[1], Length(current)-1);   
                Length(current) = Length(current)-1;
            } else {
                ::ConcatPStrings(minusSign, current);
                ::CopyPString(minusSign, current);

            }
                fCalcDisplay->SetTextString(current);
                ::CopyPString(current, fCurrentNumber);
                break;
         case cmd0:   
  
         case cmd1:
         case cmd2: 
         case cmd3: 
         case cmd4: 
         case cmd5: 
         case cmd6: 
         case cmd7: 
         case cmd8: 
         case cmd9:
             Str31 numberAsString;

             NumToString(theCommand - cmd0, numberAsString);
             if (Length(fCurrentNumber) + Length(numberAsString) < sizeof(fCurrentNumber)) {
                 ConcatPStrings(fCurrentNumber, numberAsString);
                 fCalcDisplay->SetTextString(fCurrentNumber);

             }
             break;
         case cmdPeriod:
             Str31 periodString = n \p. II j
             if (Length(fCurrentNumber) + Length(periodString) <
sizeof(fCurrentNumber)) {
                 ConcatPStrings(fCurrentNumber, periodString);
                 fCalcDisplay->SetTextString(fCurrentNumber);
             }
             break;
         case cmdE:
             Str31 eString = 11 \pE";
             if (Length(fCurrentNumber) + Length(eString) <
sizeof(fCurrentNumber)) {

                 ConcatPStrings(fCurrentNumber, eString);
                 fCalcDisplay->SetTextString(fCurrentNumber);

              }

              break; 
          default:
              CPane::DoCommand(theCommand);
    }
}

void CCalculatorPane::EnterCurrentNumber() {
}
    if(Length(fCurrentNumber) > 0) { 
        fCalculator.Enter(fCalcDisplay->GetValue()); 
        Length(fCurrentNumber) = 0;
        UpdateDisplay();
}

void CCalculatorPane::DoKeyDown(char theChar, Byte keyCode, EventRecord *macEvent)
{
}
    const kReturnChar =13;
    const kEnterChar =3;
    const kBackspaceChar =8;
    long commandNumber;
    switch (theChar){
        case kBackspaceChar:
            if (Length(fCurrentNumber) == 1)
                DoCommand(cmdClearEntry);
            else if (Length(fCurrentNumber) > 1) {
               Length(fCurrentNumber)--;
               fCalcDisplay->SetTextString(fCurrentNumber);
            }
            return; 
        case '0': 
        case '1': 
        case '2': 
        case '3': 
        case '4': 
        case '5': 
        case '6': 
        case '7': 
        case '8':
        case '9':
            commandNumber = cmd0 + theChar - '0';
            break;
        case 'e':
        case 'E':
            commandNumber = cmdE;
            break;
        case 'c':
        case 'C':
            commandNumber = cmdClearEntry;
            break;
        case'.':
            commandNumber = cmdPeriod;
            break;
        case '+':
            commandNumber = cmdAdd;
            break;
        case '·':
        case '-':
            commandNumber = cmdChangeSign;
            break;
         case '-':
            commandNumber = cmdSubtract;
            break;
         case '*':
            commandNumber = cmdMultiply;
            break; 
         case '/':
            commandNumber = cmdDivide;
            break;
         case kReturnChar: 
         case kEnterChar:
            commandNumber =         cmdEnter;
            break;
        default:
            inherited::DoKeyDown(theChar, keyCode, macEvent);
            return;
    }
    fButtons[commandNumber - cmdFirstCommandJ->SimulateClick();
}