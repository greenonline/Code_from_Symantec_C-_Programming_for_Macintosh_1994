/* Chapter 18 - PicturePeeker *//* CCutCopyPastePicture.h */#pragma once#include <CPicture.h>class CCutCopyPastePicture: public CPicture { public:    CCutCopyPastePicture(CView *anEnclosure, CBureaucrat *aSupervisor, short aWidth, short aHeight, short aHEncl, short aVEncl, SizingOption aHSizing, SizingOption aVSizing);    virtual void UpdateMenus();    virtual void DoCommand(long cmd); };