/* Chapter 16 - RandomRectangle */
/* TRandom.h */


#pragma once
class TRandom { 
public:
    TRandom();
    TRandom(unsigned long seed);

    void Advance();
    unsigned long Value();
    unsigned long ValueinRange(unsigned long low, unsigned long high);
private:
    unsigned long fValue;
};