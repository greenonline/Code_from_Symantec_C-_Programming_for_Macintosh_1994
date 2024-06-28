/* Chapter 18 - PicturePeeker */
/* CCutCopyPastePicture.cp */



// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.

#include "CCutCopyPastePicture.h" 
#include <CBartender.h>
#include <CClipboard.h>
#include "CPictureClipboardTask.h"

extern CBartender *gBartender; 
extern CClipboard *gClipboard;

CCutCopyPastePicture::CCutCopyPastePicture(CView *anEnclosure, CBureaucrat *aSupervisor,
short aWidth, short aHeight, short aHEncl, short aVEncl, SizingOption aHSizing, SizingOption aVSizing) : CPicture(anEnclosure, aSupervisor, aWidth, aHeight, aHEncl, aVEncl, aHSizing, aVSizing)
{
 TCL_END_CONSTRUCTOR
}

void CCutCopyPastePicture::UpdateMenus() {
    CPicture::UpdateMenus();


    if ( GetMacPicture() != NULL) {
        gBartender->EnableCmd(cmdCopy);
        gBartender->EnableCmd(cmdCut);
        gBartender->EnableCmd(cmdClear);
    }

    if (gClipboard->GetData('PICT', NULL)) 
        gBartender->EnableCmd(cmdPaste);
}

void CCutCopyPastePicture::DoCommand(long cmd)
{
    switch (cmd) {
        case cmdCopy: 
        case cmdCut: 
        case cmdClear: 
        case cmdPaste:
            CPictureClipboardTask *clipTask = new CPictureClipboardTask(this, cmd); 
            itsLastTask =clipTask;
            if (cmd == cmdCopy)
                itsSupervisor->NotifyClean(clipTask); 
            else
                itsSupervisor->Notify(clipTask); clipTask->Do();
            break;
        default: 
            CPicture::DoCommand(cmd);
    }
}