/* Chapter 21 - AddressBook */
/* CStreamableDatabase.h */

/****************************************************************************** CStreamableDatabase.h
Copyright © 1994 Neil Rhodes and Julie McKeehan. All rights reserved.
******************************************************************************/ 

#pragma once

#include "Database.h" 

class CStream;

class CStreamableDatabase TCL_AUTO_DESTRUCT_OBJECT { 
public:
    TCL_DECLARE_CLASS

    virtual void PutTo(CStream& stream); 
    virtual void GetFrom(CStream& stream);

    TDatabase &GetDatabase(); 

private:
    TDatabase fDatabase;
};