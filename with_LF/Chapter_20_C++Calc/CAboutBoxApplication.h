/* Chapter 19 - TickTock */
/* CAboutBoxApplication.h */


#pragma once
#include <CApplication.h>

class CAboutBoxApplication: public CApplication { 
public:
    CAboutBoxApplication(short extraMasters, Size aRainyDayFund, Size aCriticalBalance, Size aToolboxBalance);

virtual void DoCommand(long theCommand); 
};