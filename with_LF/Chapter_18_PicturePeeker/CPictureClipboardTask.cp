/* Chapter 18 - PicturePeeker */
/* CPictureClipboardTask.cp */

// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved. 

#include "CPictureClipboardTask.h"
#include <CClipboard.h>

extern CClipboard *gClipboard; 
const LongPt kZeroZeroPt ={0, 0};

// cmdTyping is first string, cmdCut is next CPictureClipboardTask::CPictureClipboardTask(CPicture *thePicture,
long command):
CTask(command · cmdCut + 2)
{
    fOldMacPicture = NULL;
    fOldScrap = NULL;
    fPicture =thePicture;
    fCommand = command;
    TCL_END_CONSTRUCTOR
}

CPictureClipboardTask::-CPictureClipboardTask() {
    TCL_START_DESTRUCTOR 
    if (!IsUndone()) {
        switch (fCommand) { 
            case cmdCut:
                ::DisposHandle((Handle) fOldMacPicture);
                ::DisposHandle(fOldScrap);
                break;
            case cmdClear:
                ::DisposHandle((Handle) fOldMacPicture);
                break;
            case cmdPaste:
                ::DisposHandle((Handle) fOldMacPicture); 
                // old scrap is now the picture
                break;
            case cmdCopy:
                // old picture remains the picture 
                ::DisposHandle(fOldScrap);
                break;
        } 
    } else
        if (fOldScrap I= NULL) 
            ::DisposHandle(fOldScrap);
}

void CPictureClipboardTask::Do() {
    if (fCommand I = cmdClear) { 
        Handle h;

        gClipboard·>GetData('PICT', &h);
        fOldScrap = h;
    }
    fOldMacPicture =fPicture->GetMacPicture();
    Redo();
}

void CPictureClipboardTask::Undo()
{
    if (fCommand == cmdCopy || fCommand cmdCut) { 
        gClipboard->EmptyScrap();
        if (fOldScrap I= NULL)
            gClipboard->PutData('PICT', fOldScrap);
    } 
    if (fCommand ! = cmdCopy) {

        fPicture->SetPosition((LongPt *) &kZeroZeroPt);
        fPicture->SetMacPicture(fOldMacPicture);
        fPicture->Refresh();
    }
    undone =TRUE;
}

void CPictureClipboardTask::Redo()
{
    if (fCommand == cmdCopy || fCommand == cmdCut) { 
        gClipboard->EmptyScrap();
        gClipboard->PutData('PICT', (Handle) fOldMacPicture);
    } 
    if (fCommand == cmdCut || fCommand == cmdClear) { 
        fPicture->SetPosition((LongPt *) &kZeroZeroPt);
        fPicture->SetMacPicture(NULL);
    }
    if (fCommand == cmdPaste) { 
        fPicture->SetPosition((LongPt *) &kZeroZeroPt);
        fPicture->SetMacPicture((PicHandle) fOldScrap);

    } 
    if (fCommand ! = cmdCopy)
        fPicture->Refresh();
    undone =FALSE;
}