

/****************************************************************************** CStreamableDatabase.cp
Copyright © 1994 Neil Rhodes and Julie McKeehan. All rights reserved.
******************************************************************************/

#include "CStreamableDatabase.h" 
#include "Entry.h"
#include <CStream.h>



TCL_DEFINE_CLASS_D0(CStreamableDatabase);

TDatabase &CStreamableDatabase::GetDatabase()
{
return fDatabase;
}

void CStreamableDatabase::PutTo(CStream& stream) {
    long total = 0;
    TIterator iter(fDatabase);

    for (iter.MoveToBeginning(); !iter.NoMore(); iter.MoveForward())
        total++; 
    stream << total;
    for (iter.MoveToBeginning(); !iter.NoMore(); iter.MoveForward()) {

        TEntry *curEntry = (TEntry *) iter.GetCurrent();

        stream << curEntry->GetName();
        stream << curEntry->GetAddress();
        stream << curEntry->GetCity();
        stream << curEntry->GetState();
        stream << curEntry->GetZip();
        stream << curEntry->GetTelephone();
    }
}

void CStreamableDatabase::GetFrom(CStream& stream)
{
    long total;

    stream >> total;

    for (long i = 0; i < total; i++) { 
        char name[256];
        char address[256]; 
        char city[256]; 
        char state[256]; 
        char zip[256];
        char telephone[256];

        stream >> name;
        stream >> address;
        stream >> city;
        stream >> state;
        stream >> zip;
        stream >> telephone;





        TEntry *newEntry = new TEntry(name, address, city, state, zip, telephone);
        fDatabase.Insert(newEntry);

    }
}
