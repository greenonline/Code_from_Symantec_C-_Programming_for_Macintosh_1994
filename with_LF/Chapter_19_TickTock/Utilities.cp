/* Chapter 19 - TickTock */
/* Utilities.cp */

// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved. 

#include <TCLUtilities.h>
#include "Utilities.h"

Ptr NewPtrCanFail(Size size) {

    Ptr p;
    Boolean savedAlloc;

    savedAlloc =SetAllocation(kAllocCanFail);
    p = NewPtr(size); 
    SetAllocation(savedAlloc);

    return p;
}