/* Chapter 18 - PicturePeeker */
/* CPictureApp.cp */

// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.
/*****
*
* CPictureApp.c
*
* *****/

#include "CPictureApp.h" 
#include "CPictureDoc.h" 
#include "TDeleteOnFailure.h" 
#include <Global.h>

const short kExtraMasters = 1;
const Size kRainyDayFund = 45000;
const Size kCriticalBalance = 40000;
const Size kToolboxBalance = 20000;

extern OSType gSignature;  // The application's signature

CPictureApp::CPictureApp() CAboutBoxApplication(kExtraMasters, kRainyDayFund, kCriticalBalance, kToolboxBalance) 

{
    TCL_END_CONSTRUCTOR
}

void CPictureApp::CreateDocument() {
    CPictureDoc *theDocument = new CPictureDoc;

    TDeleteOnFailure<CPictureDoc> freer(theDocument);
    theDocument->NewFile(); 
    freer.Success();
}

void CPictureApp::OpenDocument(SFReply *macReply)
{
    CPictureDoc *theDocument = new CPictureDoc;


    TDeleteOnFailure<CPictureDoc> freer(theDocument);
    theDocument->OpenFile(macReply); 
    freer.Success();
}

void CPictureApp::SetUpFileParameters() {

    CApplication::SetUpFileParameters();

    sfNumTypes =1; 
    sfFileTypes[0] = 'PICT'; 
    gSignature = 'C++3';
}


