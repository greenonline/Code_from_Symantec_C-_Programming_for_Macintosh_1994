/* Chapter 18 - PicturePeeker */
/* CPictureDoc.cp */

// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.

#include "CPictureDoc.h"
#include "CCutCopyPastePicture.h" 
#include <CScrollPane.h>
#include <CDesktop.h>
#include <CWindow.h>
#include <CDataFile.h>
#include <CDecorator.h>
#include <TBUtilities.h>
#include "TDisposHandleOnFailure.h" 
#include "TWithFileOpen.h"
#include "THandleLocker.h"


extern Cdesktop *gDesktop;
extern OSType  gSignature;
extern CDecorator  *gDecorator;
const long kPICTHeaderLength = 512;

void CPictureDoc::NewFile()
{
    BuildWindow() ;

    Str255 wTitle;
    short wCount;
    Str255 wNumber;

    itsWindow->GetTitle(wTitle);
    wCount = gDecorator->GetWCount();
    ::NumToString(wCount, wNumber);
    ::ConcatPStrings(wTitle, "\p-");
    ::ConcatPStrings(wTitle, wNumber);
    itsWindow->SetTitle(wTitle);

    itsWindow->Select();
}

void CPictureDoc::BuildWindow() {

    const short kWINDResourceID = 500;
    const Boolean kWindowFloats = TRUE;
    const Boolean kFitHorizontal = TRUE;
    const Boolean kFitVertical = TRUE;
    const Boolean kHasHorizontalScrollbar = TRUE;
    const Boolean kHasverticalScrollbar = TRUE;
    const Boolean kHasGrowBox = TRUE;
    const Boolean kRedraw = TRUE;

    CWindow *aWindow =new CWindow(kWINDResourceID, !kWindowFloats, this); 
    itsWindow =aWindow;
    CScrollPane *theScrollPane = new CScrollPane(aWindow, this, 10, 10, 0, 0,
sizELASTIC, sizELASTIC,
kHasHorizontalScrollbar, kHasVerticalScrollbar, kHasGrowBox);
    theScrollPane->FitToEnclFrame(kFitHorizontal, kFitVertical);

    CCutCopyPastePicture *thePane =
new ccutCopyPastePicture(theScrollPane, this, 1, 1, 0, 0, sizELASTIC, sizELASTIC);
    itsGopher =thePane;
    itsMainPane =thePane;
    fPicture =thePane;
    theScrollPane->InstallPanorama(thePane);
    thePane->FitToEnclosure(kFitHorizontal, kFitVertical);

    gDecorator->PlaceNewWindow(itsWindow);
}

void CPictureDoc::OpenFile(SFReply *macReply) {
    CDataFile * theDataFile;
    Handle  theData;
    Str63  theName;
    OSErr  theError;


    new CDataFile;

    itsFile = theDataFile;

    theDataFile->SFSpecify(macReply);

    Handle theMacPicture = ::NewHandleCanFail(0);
    ::FailNIL(theMacPicture);
    {
        TWithFileOpen fileOpener(theDataFile, fsRdPerm);
        TDisposHandleOnFailure handleFreer(theMacPicture);

        long thePictureLength =theDataFile->GetLength() - kPICTHeaderLength;
        if (thePictureLength <= 0)
            ::FailOSErr(eofErr);
        theDataFile->SetMark(kPICTHeaderLength, fsFromStart); 
        ::ResizeHandleCanFail(theMacPicture, thePictureLength);
        ::FailMemError();
        {
            THandleLocker lock(theMacPicture);
            theDataFile->ReadSome(*theMacPicture, thePictureLength);
        }

        BuildWindow(); 
        handleFreer.Success();
    }
    fPicture->SetMacPicture((PicHandle) theMacPicture);

    itsFile->GetName(theName);
    itsWindow->SetTitle(theName);

    itsWindow->Select();
}

Boolean CPictureDoc::DoSave() {
    Handle theData;

    if (itsFile == NULL)
        return(DoSaveFileAs());
    else {
        CDataFile *theDataFile = (CDataFile *) itsFile;
        Handle theMacPicture = (Handle) fPicture->GetMacPicture(); {
            TWithFileOpen fileOpener(theDataFile, fsWrPerm);
            char zeros[kPICTHeaderLengthJ;

            for (int i =0; i < kPICTHeaderLength; i++)
               zeros[i] =0;
            theDataFile->WriteSome(zeros, sizeof(zeros));
            THandleLocker lock(theMacPicture);
            theDataFile->WriteSome(*theMacPicture, ::GetHandleSize(theMacPicture));
        }

        dirty =FALSE;
        return(TRUE);
}

Boolean CPictureDoc::DoSaveAs(SFReply *macSFReply) {
    if (itsFile I= NULL)
        delete itsFile;
    CDataFile *theDataFile = new CDataFile;
    itsFile =theDataFile;

    theDataFile->SFSpecify(macSFReply);
    if (theDataFile->ExistsOnDisk())
        theDataFile->ThrowOut();
    theDataFile->CreateNew(gSignature, 'PICT' );

    itsWindow->SetTitle(macSFReply->fName);

    return(DoSave());
}
