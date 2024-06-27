/* Chapter 16 - RandomRectangle */
/* TRandom.cp */

// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved. 

#include "TRandom.h"
#include <Events.h>

TRandom::TRandom() {
    fValue =::TickCount();
}

TRandom::TRandom(unsigned long seed) {
    fValue = seed;
}

void TRandom::Advance() 
{
    fValue = fValue * 12345 + 6789;
}

unsigned long TRandom::Value()
{
    return fValue;
}

unsigned long TRandom::ValueInRange(unsigned long low, unsigned long high)
{
    return (Value() % (high - low+ 1)) + low;
}
