/* Chapter 19 - TickTock */
/* CQuitApplicationChore.h */


#pragma once 

#include <CChore.h>

class CQuitApplicationChore: public CChore { 
public:
    virtual void Perform(long *maxSleep);
};