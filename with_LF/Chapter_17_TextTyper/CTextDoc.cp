/* Chapter 17 - TextTyper */
/* CTextDoc.cp */



// Copyright © 1993, Neil Rhodes and Julie McKeehan. All rights reserved.


#include "CTextDoc.h" 
#include <CEditText.h> 
#include <CScrollPane.h> 
#include <CDesktop.h> 
#include <CWindow.h> 
#include <CDataFile.h> 
#include <CDecorator.h> 
#include <TBUtilities.h>

extern CDesktop *gDesktop;
extern OSType gSignature;
extern CDecorator *gDecorator;


void CTextDoc::NewFile()
{
    BuildWindow();
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

void CTextDoc::BuildWindow()
{
    const short kWINDResourceID = 500;
    const Boolean kWindowFloats = TRUE;
    const Boolean kFitHorizontal = TRUE;
    const Boolean kFitVertical = TRUE; 
    const Boolean kHasHorizontalScrollbar = TRUE;
    const Boolean kHasVerticalScrollbar = TRUE;
    const Boolean kHasGrowBox = TRUE;
    const short kEditTextWidth = 72*6;
    const Boolean kRedraw = TRUE;

    CWindow *aWindow =new CWindow(kWINDResourceID, !kWindowFloats, this);
    itsWindow = aWindow;
    CScrollPane *theScrollPane = new CScrollPane(aWindow, this, 10, 10, 0, 0,
sizELASTIC, sizELASTIC, kHasHorizontalScrollbar, kHasVerticalScrollbar, kHasGrowBox); 
    theScrollPane->FitToEnclFrame(kFitHorizontal, kFitVertical);

    CEditText *thePane =new CEditText(theScrollPane, this, 1, 1, 0, 0, sizELASTIC, sizELASTIC, kEditTextWidth);
    itsGopher = thePane;
    itsMainPane = thePane;
    fEditText = thePane; 
    
    theScrollPane->InstallPanorama(thePane); thePane->FitToEnclosure(kFitHorizontal, kFitVertical);

    Rect margin;
    ::SetRect(&margin, 2, 2, -2, -2);
    thePane->ChangeSize(&margin, !kRedraw);

    gDecorator->PlaceNewWindow(itsWindow);
}

void CTextDoc::OpenFile(SFReply *macReply){
    CDataFile *theDataFile;
    Handle theData;
    Str63 theName;
    OSErr theError;
    const long  kMaxFileSize =32000;

    theDataFile =new CDataFile;
    itsFile =theDataFile;
    theDataFile->SFSpecify(macReply);
    theDataFile->Open(fsRdPerm);

    TRY {
        if (theDataFile->GetLength() > kMaxFileSize)
::Failure(paramErr, excExceedTELimit); theData =theDataFile->ReadAll();
    } CATCH { 
        theDataFile->Close();
    }
    ENDTRY;

    TRY {
        theDataFile->Close();
        BuildWindow();
        fEditText->SetTextHandle(theData);
    } CATCH {
        ::DisposHandle(theData); throw_same_();
    }
    ENDTRY; 

    ::DisposHandle(theData);

    itsFile->GetName(theName);
    itsWindow->SetTitle(theName);
    itsWindow->Select();
}

Boolean CTextDoc::DoSave() 
{
    Handle theData;

    if (itsFile == NULL)
        return(DoSaveFileAs());
    else {
        CDataFile *theDataFile = (CDataFile *) itsFile;
        theData =fEditText->GetTextHandle();
        theDataFile->Open(fsWrPerm);
        TRY {
            theDataFile->WriteAll(theData);
        } CATCH {
            theDataFile->Close();
        }
        ENDTRY;
        theDataFile->Close();
        dirty = FALSE;
        return(TRUE);
    }
}

Boolean CTextDoc::DoSaveAs(SFReply *macSFReply)
{
    if (itsFile != NULL)
        TCLForgetObject(itsFile);

    CDataFile *theDataFile = new CDataFile;
    itsFile =theDataFile;
    theDataFile->SFSpecify(macSFReply);
    if (theDataFile->ExistsOnDisk())
        theDataFile->ThrowOut();
    theDataFile->CreateNew(gSignature, 'TEXT');

    itsWindow->SetTitle(macSFReply->fName);
    return(DoSave());
}