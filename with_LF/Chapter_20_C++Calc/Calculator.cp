/* Chapter 20 - C++Calc */
/* Calculator.cp */

// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.

#include "Calculator.h"

TCalculator::TCalculator()
{
    fX =0.0;
    fY =0.0;
    fZ =0.0;
}

void TCalculator::Enter(long double num) {
    fZ =fY; fY = fX; fX =num;
}

void TCalculator::Add() {
    long double v = PopX();
    Enter(PopX() + v);
}

void TCalculator::Subtract()
{
    long double v =PopX{);
    Enter{PopX{) - v ) ;
}

void TCalculator::Multiply() {
    long double v = PopX();
    Enter{PopX() * v ) ; 
}

void TCalculator::Divide() {
    long double v = PopX();
    Enter(PopX() I v ) ;
}

long double TCalculator::GetX() {
    return fX;
}

long double TCalculator::GetY() {
    return fY;
}

long double TCalculator::GetZ{) {
    return fZ;
}

void TCalculator::SetX(long double num) {
    fX = num;
}

void TCalculator::SetY(long double num) {
    fY = num;
}

void TCalculator::SetZ{long double num) {
    fZ = num;
}

long double TCalculator::PopX() {
    long double v = GetX();
    fX =fY;
    fY =fZ;
    fZ = 0.0;
    return v;
}
