/* Chapter 20 - C++Calc */
/* CCalculatorApp.h */


/*****
* CCalculatorApp.h
*
*
* *****/

#pragma once

#include "CAboutBoxApplication.h"

class CCalculatorApp: public CAboutBoxApplication {
public:
    CCalculatorApp();
    void StartUpAction(short numPreloads);
};
