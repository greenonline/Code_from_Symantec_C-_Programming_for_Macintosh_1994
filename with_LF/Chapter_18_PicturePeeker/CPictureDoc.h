/* Chapter 18 - PicturePeeker */
/* CPictureDoc.h */

#pragma once

#include <CDocument.h> 
#include <CPicture.h>

class CPictureDoc: public CDocument { 
public:
    virtual void NewFile();
    virtual void OpenFile(SFReply *macReply);
    virtual Boolean DoSave();
    virtual Boolean DoSaveAs(SFReply *macSFReply);
protected:
    virtual void BuildWindow();
private:
    CPicture *fPicture;
};