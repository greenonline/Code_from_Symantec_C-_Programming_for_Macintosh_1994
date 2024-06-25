/* Chapter 20 - C++Calc */
/* Calculator.h */


#pragma once

class TCalculator { 
public:
    TCalculator();
    void Enter(long double num);
    void Add();
    void Subtract();
    void Multiply();
    void Divide();
    long double GetX();
    long double GetY();
    long double GetZ();
private:
    long double PopX();
    void SetX(long double num);
    void SetY(long double num);
    void SetZ(long double num);
    long double fX;
    long double fY;
    long double fZ;
};
