/* Chapter 19 - TickTock */
/* CSaveRestoreSizeWindow.cp */

// CSaveRestoreSizeWindow.cp
// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved.

#include "CSaveRestoreSizeWindow.h" 
#include <Folders.h>
#include "TGrafPortSetter.h"

CSaveRestoreSizeWindow::CSaveRestoreSizeWindow(short windID,
Boolean aFloating,
CDirector *aSupervisor) :
CQuitOnCloseWindow(windID, aFloating, aSupervisor)
{
    fDataFile= NULL;

    fDataFile = new CDataFile;
    SpecifyFile(fDataFile); 
    SetInfoFromFile(fDataFile); 
    TCL_END_CONSTRUCTOR;

}

CSaveRestoreSizeWindow::~CSaveRestoreSizeWindow() {
    TCL_START_DESTRUCTOR; 
    StoreInfoInFile(fDataFile); 
    TCLForgetObject(fDataFile);
}

void CSaveRestoreSizeWindow::SpecifyFile(CFile *aFile) {
    short vRefNum;
    long dirID;

    FailOSErr(FindFolder(kOnSystemDisk, kPreferencesFolderType, kCreateFolder, &vRefNum,&dirID));
    aFile->SpecifyHFS("\pTick-Tock Preferences", vRefNum, dirID);
}

void CSaveRestoreSizeWindow::StoreInfoInFile(CDataFile *aFile) {



    if (!aFile->ExistsOnDisk()) 
        aFile->CreateNew('C++5', 'PREF');

    aFile->Open(fsWrPerm);

    Rect theWindowLocSize = macPort->portRect;

    TGrafPortSetter setPort(macPort);
    ::LocalToGlobal((Point *) &theWindowLocSize.top); 
    ::LocalToGlobal((Point *) &theWindowLocSize.bottom);
//} /* TYPO???*/
    TRY {
        aFile->WriteSome((Ptr) &theWindowLocSize, sizeof(theWindowLocSize));
    }
    CATCH { 
        NO_PROPAGATE;  // not writing window location isn't fatal

    }
    ENDTRY; 
    aFile->Close();
}

void CSaveRestoreSizeWindow::SetInfoFromFile(CDataFile *aFile) {
    if (aFile->ExistsOnDisk()) { 
        Rect portRect;

        aFile->Open(fsRdPerm);

        TRY {
            aFile->ReadSome((Ptr) &portRect, sizeof(portRect));
            Move(portRect.left, portRect.top);
            ChangeSize(portRect.right - portRect.left, portRect.bottom - portRect.top);
        }
        CATCH {
            NO_PROPAGATE;   // not reading window location isn't fatal
        }
        ENDTRY; 
        aFile->Close();
    }
}