/* Chapter 18 - PicturePeeker */
/* CPictureApp.h */




/*****
*
* CPictureApp.h
*
*   Application class for a typical application. *****/
*
*****/

#pragma once

#include "CAboutBoxApplication.h"

class CPictureApp: public CAboutBoxApplication { 
public:
    CPictureApp();

    virtual virtual virtual
    void CreateDocument();
    void OpenDocument(SFReply *macReply); void SetUpFileParameters();
};
