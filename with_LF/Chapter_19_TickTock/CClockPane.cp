/* Chapter 19 - TickTock */
/* CClockPane.cp */

// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved.

#include "CClockPane.h"
#include "CDawdleBureaucratChore.h"
#include <Global.h>
#include <Commands.h>
#include <CApplication.h>
#include <CBartender.h>
#include <Packages.h>
#include <SANE.h>
#include "Utilities.h"
#include "TGrafPortSetter.h"
  
   

 
extern CApplication *gApplication; 
extern CBartender *gBartender;
extern long gSleepTime;

CClockPane::CClockPane(CView *anEnclosure, CBureaucrat *aSupervisor, short aWidth, short aHeight,
short aHEncl, short aVEncl,
SizingOption aHSizing, SizingOption aVSizing) : CPane(anEnclosure, aSupervisor, aWidth, aHeight,
aHEncl, aVEncl, aHSizing, aVSizing)
{

    fIdleChore = NULL;
    fIdleChoreIsInstalled = FALSE;
    fBitMap.baseAddr = NULL;
    fGrafPtr = NULL;
    SetRect(&fBitMap.bounds, 0, 0, 0, 0);

    fIdleChore = new CDawdleBureaucratChore(this);
    fGrafPtr = (GrafPtr) ::NewPtrCanFail(sizeof(GrafPort));

    ::FailNIL(fGrafPtr); 
    ::OpenPort(fGrafPtr);

    fDigital = false; 
    fShowSeconds = true;
}

CClockPane::~CClockPane() {
    if (fIdleChoreIsInstalled)
        gApplication->CancelIdleChore(fIdleChore);
    TCLForgetObject(fIdleChore); 
    if (fBitMap.baseAddr != NULL)
        ::DisposPtr(fBitMap.baseAddr); 
    if (fGrafPtr != NULL) {
        ::ClosePort(fGrafPtr); 
        ::DisposPtr((Ptr) fGrafPtr);
    }
}

void CClockPane::Activate(void)
{
    CPane::Activate();
    if (fIdleChoreIsInstalled) {
        gApplication->CancelIdleChore(fIdleChore);
        fIdleChoreIsInstalled =false; 
    }
}

void CClockPane::Deactivate(void) {
    CPane::Deactivate(); 
    gApplication->AssignIdleChore(fIdleChore); 
    fIdleChoreIsInstalled = true;
}

void CClockPane::UpdateMenus() {
    CPane::UpdateMenus();

    gBartender->EnableCmd(cmdShowSeconds); 
    gBartender->EnableCmd(cmdDigital);
    gBartender->EnableCmd(cmdAnalog);

    gBartender->CheckMarkCmd(cmdShowSeconds, fShowSeconds);
    gBartender->CheckMarkCmd(cmdDigital, fDigital) ;
    gBartender->CheckMarkCmd(cmdAnalog, !fDigital);
}

void CClockPane::DoCommand(long theCommand)
{
    switch (theCommand) { 
        case cmdShowSeconds:
            fShowSeconds = !fShowSeconds;
            Refresh ();
            if (fShowSeconds)
                gSleepTime = 1;   // Make Dawdle start being called
            break;
        case cmdDigital:
            if (!fDigital) {
                fDigital = TRUE;
                Refresh();
            } 
            break;
        case cmdAnalog:
            if (fDigital) {
                fDigital = FALSE;
                Refresh();
            }
            break;  
        default: 
            CPane::DoCommand(theCommand);
            break;
    }
}

inline short Round(float f)
{
    return (short) (f + 0.5);

}

void CClockPane::UpdateOffscreen(const Rect &area) 
{
    LongRect frame; 
    Rect qdFrame;

    GetFrame(&frame); 
    ::LongToQDRect(&frame, &qdFrame);
    CreateOffscreen(qdFrame); //we would use area, if we weren't dawdling

    TGrafPortSetter setPort(fGrafPtr); 
    DrawClock(qdFrame);
}

void CClockPane::Draw(Rect *area) {
    UpdateOffscreen(*area);
    CopyFromOffscreen(*area);
}

// fractionOfCircle: 0 means straight up, .25 means to the right
void DrawLine(const Rect &frame, long double fractionOfCircle, short size) {

    long double angle= 2 * 3.14159 * (1-(fractionOfCircle - 0.25));
    short radiusX = (frame.right - frame.left) / 2;
    short radiusY = (frame.bottom - frame.top) / 2;
    short xCoord = ::Round(::cos(angle) * radiusX);
    short yCoord = ::Round(::sin(angle) * radiusY);

    ::PenSize(size, size);
    ::MoveTo(frame.left + radiusX, frame.top+ radiusY); 
    ::Line(xCoord, -yCoord); // Macintosh uses Y decreasing
}

inline short NumberOfBytesRoundedUpToAMultipleOf2(short num) {
    return (num + 15) / 16 * 2;
}
void CClockPane::CreateOffscreen(const Rect &area) {
    if (area.left != fBitMap.bounds.left ||
        area.right != fBitMap.bounds.right ||
        area.top != fBitMap.bounds.top ||
        area.bottom != fBitMap.bounds.bottom) {


        fBitMap.bounds = area;
        fBitMap.rowBytes =
::NumberOfBytesRoundedUpToAMultipleOf2(fBitMap.bounds.right - fBitMap.bounds.left);
        if (fBitMap.baseAddr != NULL)
            ::DisposPtr(fBitMap.baseAddr);
        fBitMap.baseAddr =
::NewPtrCanFail(fBitMap.rowBytes * (fBitMap.bounds.bottom - fBitMap.bounds.top));
        ::FailNIL(fBitMap.baseAddr);
        ::RectRgn(fGrafPtr->visRgn, &area);
        ::RectRgn(fGrafPtr->clipRgn, &area);
        fGrafPtr->portRect =area;

        TGrafPortSetter setPort(fGrafPtr);
        ::SetPortBits(&fBitMap);
    }
}

void CClockPane::GetDigitalString(unsigned long now, Str255 s) {
    ::IUTimeString(now, fShowSeconds, s);
}

void CClockPane::GetDigitalFontAndSize(const Str255 s, const Rect &clockSize, short *font, short *size)
{
    *font = geneva;
    *size = 9;
}

void CClockPane::GetDigitalStringLocation(const Str255 s, const Rect &clockSize, short *h, short *v)
{
    FontInfo fInfo;

    ::GetFontInfo(&fInfo);
    short excessHeight =clockSize.bottom - clockSize.top - fInfo.descent - fInfo.ascent; 
    if (excessHeight < 0)
        *v =clockSize.bottom; 
    else
        *v = clockSize.bottom - fInfo.descent - excessHeight / 2;

    short excessWidth = clockSize.right - clockSize.left - ::StringWidth(s);
    if (excessWidth < 0)
        *h = clockSize.left;
    else
        *h = clockSize.left + excessWidth / 2;
}

void CClockPane::DrawDigitalClock(const Rect &clockSize, unsigned long now) {

    Str255 nowStr;
    short  h;
    short v;
    short font;
    short size;

    GetDigitalString(now, nowStr); GetDigitalFontAndSize(nowStr, clockSize, &font, &size);
    ::TextFont(font); 
    ::TextSize(size);
    GetDigitalStringLocation(nowStr, clockSize, &h, &v); 
    ::MoveTo(h, v);
    ::DrawString(nowStr);
}

void CClockPane::DrawAnalogClock(const Rect &clockSize, unsigned long now) {

    DateTimeRec nowDateTime;
    const short kSecondHandThickness = 1;
    const short kMinuteHandThickness = 2;
    const short kHourHandThickness = 3;
  
    ::Secs2Date(now, &nowDateTime);

    if (fShowSeconds)
        DrawLine(clockSize, ((float) nowDateTime.second) / 60.0,
kSecondHandThickness);
    DrawLine(clockSize, nowDateTime.minute / 60.0, kMinuteHandThickness);

    Rect smallFrame = clockSize;        // hour hand will be inscribed here
    const kHourHandSmallerConstant =2;  // half as big as other hands
    ::InsetRect(&smallFrame,
      (clockSize.right - clockSize.left)/(2 * kHourHandSmallerConstant), 
      (clockSize.bottom - clockSize.top)/(2 * kHourHandSmallerConstant));

    DrawLine(smallFrame, nowDateTime.hour / 12.0, kHourHandThickness);
}


 void CClockPane::DrawClock(const Rect &clockSize)
{
    unsigned long now; 

    ::GetDateTime(&now); 

    ::EraseRect(&clockSize);

    if (fDigital) 
        DrawDigitalClock(clockSize, now);
    else
        DrawAnalogClock(clockSize, now);

}

void CClockPane::CopyFromOffscreen(const Rect &areaToCopy)
{
    ::CopyBits(&fBitMap, &thePort->portBits, &areaToCopy, &areaToCopy, srcCopy, 0L);
}

long CClockPane::CalculateSleepTime() {
    const short kTicksPerSecond =60;

    if (fShowSeconds)
        return kTicksPerSecond;
    else {
        unsigned long now;
 
        DateTimeRec  nowDateTime;
        const short kSecondsPerMinute =60;

         GetDateTime(&now);
        Secs2Date(now, &nowDateTime);
        return kTicksPerSecond * (kSecondsPerMinute - nowDateTime.second);
    }
}

void CClockPane::Dawdle(long *maxSleep) {
    LongRect frame; 
    Rect qdFrame;

    GetFrame(&frame);
    ::LongToQDRect(&frame, &qdFrame);
    UpdateOffscreen(qdFrame);

    Prepare();
    CopyFromOffscreen(qdFrame);

    *maxSleep = CalculateSleepTime();
}





