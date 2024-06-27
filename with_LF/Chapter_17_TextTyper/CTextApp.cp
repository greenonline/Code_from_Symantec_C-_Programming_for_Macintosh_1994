/* Chapter 17 - TextTyper */
/* CTextApp.cp */


// Copyright © 1993, Neil Rhodes and Julie McKeehan. All rights reserved.

#include "CTextApp.h" 
#include "CTextDoc.h" 
#include <Global.h>

extern OSType gSignature; // The application's signature
const short kExtraMasters = 1;
const Size kRainyDayFund = 45000;
const Size kCriticalBalance = 40000;
const Size kToolboxBalance = 20000;

   
CTextApp::CTextApp() : CApplication(kExtraMasters, kRainyDayFund, kCriticalBalance, kToolboxBalance)
{
    TCL_END_CONSTRUCTOR
}

void CTextApp::CreateDocument() {
    CTextDoc *theDocument =new CTextDoc; 

    TRY {
        theDocument->NewFile();

    }
    CATCH {
        TCLForgetObject(theDocument);
    }
    ENDTRY
}

void CTextApp::OpenDocument(SFReply *macReply) {

    CTextDoc *theDocument = new CTextDoc;

    TRY {
        theDocument->OpenFile(macReply);
    }
    CATCH {
        TCLForgetObject(theDocument);
    }
    ENDTRY;
}

void CTextApp::SetUpFileParameters()
{
    CApplication::SetUpFileParameters();

    sfNumTypes =1; 
    sfFileTypes[0] = 'TEXT'; 
    gSignature = 'C++2';

}
