/* Chapter 19 - TickTock */
/* CClockPane.h */


/**** ****/
#pragma once

#include <CPane.h>
#include <Quickdraw.h>
#include "CDawdleBureaucratChore.h"

class CClockPane: public CPane { 
public:

    CClockPane(CView *anEnclosure, CBureaucrat *aSupervisor, short aWidth, short aHeight,
short aHEncl, short aVEncl,
SizingOption aHSizing, SizingOption aVSizing);

    virtual ~CClockPane();

    virtual void Draw(Rect *area);
    virtual void Activate(void);
    virtual void Deactivate(void);

    virtual void Dawdle(long *maxSleep);

    virtual void UpdateMenus();
    virtual void DoCommand(long theCommand);

protected:
    enum {cmdShowSeconds 1024, cmdDigital=1025, cmdAnalog=1026);
    virtual void DrawClock(const Rect &clockSize);
    virtual void CopyFromOffscreen(const Rect &areaToCopy);
    virtual void CreateOffscreen(const Rect &area);
    virtual void UpdateOffscreen(const Rect &area);
    virtual long CalculateSleepTime();
    virtual void DrawAnalogClock(const Rect &clockSize, unsigned long now}; 
    virtual void DrawDigitalClock(const Rect &clockSize, unsigned long now}; 
    virtual void GetDigitalString(unsigned long now, Str255 s}; 
    virtual void GetDigitalFontAndSize(const Str255 s, const Rect &clockSize, short *font, short *size};
    virtual void GetDigitalStringLocation(const Str255 s, const Rect &clockSize, short *h, short *v); 

private:
    CDawdleBureaucratChore *fidleChore;
    Boolean fIdleChoreIsInstalled;
    BitMap  fBitMap;
    GrafPtr fGrafPtr;
    Boolean fShowseconds;
    Boolean fDigital;
};


