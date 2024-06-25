/* Chapter 17 - TextTyper */
/* CTextApp.h */


#pragma once

#include <CApplication.h>

class CTextApp: public CApplication {
public:
    CTextApp();

    virtual void CreateDocument();
    virtual void OpenDocument(SFReply *macReply);
    virtual void SetUpFileParameters();
};
