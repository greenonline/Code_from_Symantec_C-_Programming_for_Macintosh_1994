/* Chapter 16 - RandomRectangle */
/* CRectangleApp.h */

/*****
* CRectangleApp.h
*
* Application class for a typical application. 
*
*****/

#pragma once

#include <CApplication.h>

class CRectangleApp: public CApplication { 
public:
    CRectangleApp();
    virtual void StartUpAction(short numPreloads);
};