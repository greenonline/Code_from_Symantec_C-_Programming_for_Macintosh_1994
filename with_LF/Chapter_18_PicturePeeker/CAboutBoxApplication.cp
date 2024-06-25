/* Chapter 18 - PicturePeeker */
/* CAboutBoxApplication.cp */

// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved. #include "CAboutBoxApplication.h"
#include <SegLoad.h>

CAboutBoxApplication::CAboutBoxApplication(short extraMasters, Size aRainyDayFund, Size aCriticalBalance, Size aToolboxBalance) : CApplication(extraMasters, aRainyDayFund, aCriticalBalance, aToolboxBalance) 
{
    TCL_END_CONSTRUCTOR
}

void CAboutBoxApplication::DoCommand(long theCommand)
{
    const short kAboutBoxResourceID = 1024;

    switch (theCommand) { 
        case cmdAbout:
            Str255 applicationName;
            short appRefNum;
            Handle h;

            ::PositionDialog('ALRT', kAboutBoxResourceID);
            ::GetAppParms(applicationName, &appRefNum, &h); 
            ::DisposHandle(h);
            ::ParamText(applicationName, NULL, NULL, NULL);
            Alert(kAboutBoxResourceID, NULL);
            break; 
        default:
            CApplication::DoCommand(theCommand);
            break;
    } 
}