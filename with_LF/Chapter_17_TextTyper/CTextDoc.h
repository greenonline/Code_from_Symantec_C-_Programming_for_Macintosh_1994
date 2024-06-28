/* Chapter 17 - TextTyper */
/* CTextDoc.h */

#pragma once

#include <CDocument.h> 
#include <CEditText.h>

class CTextDoc: public CDocument { 
public:
    virtual void NewFile();
    virtual void OpenFile(SFReply *macReply);
    virtual Boolean DoSave();
    virtual Boolean DoSaveAs(SFReply *macSFReply);
protected:
    virtual void BuildWindow();
private:
    CEditText *fEditText;
};