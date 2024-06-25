/* Chapter 18 - PicturePeeker */
/* CPictureClipboardTask.h */


#pragma once

#include <CPicture.h> 
#include <CTask.h>

class CPictureClipboardTask: public CTask { 
public:
    CPictureClipboardTask(CPicture *thePicture, long command);

    virtual -CPictureClipboardTask(); 
    virtual void Do();
    virtual void Undo();
    virtual void Redo();


private:
    CPicture *fPicture;
    long fCommand;
    Handle fOldScrap;
    PicHandle fOldMacPicture;
