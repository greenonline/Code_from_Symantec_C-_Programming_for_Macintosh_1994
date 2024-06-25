/* Chapter 20 - C++Calc */
/* CalculatorMain.cp */


// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved. 
/******************************************************************************
Calculator.c
******************************************************************************/
#include "CCalculatorApp.h"

void main() {

    CCalculatorApp *CalculatorApp;
    CalculatorApp = new CCalculatorApp; 
    CalculatorApp->Run(); 
    CalculatorApp->Exit();
}