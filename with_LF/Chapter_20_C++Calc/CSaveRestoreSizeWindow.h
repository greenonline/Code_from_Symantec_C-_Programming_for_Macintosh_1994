/* Chapter 20 - C++Calc */
/* CSaveRestoreSizeWindow.h */


#pragma once

#include "CQuitOnCloseWindow.h" 
#include <CDataFile.h>

class CSaveRestoreSizeWindow: public CQuitOnCloseWindow { 
public:
    CSaveRestoreSizeWindow( short windID,
    Boolean aFloating, CDirector *aSupervisor);
    virtual ~CSaveRestoreSizeWindow();

protected:
    virtual void StoreInfoInFile(CDataFile *aFile);
    virtual void SetInfoFromFile(CDataFile *aFile); 
    virtual void SpecifyFile(CFile *aFile);

private:
    CDataFile *fDataFile;
};