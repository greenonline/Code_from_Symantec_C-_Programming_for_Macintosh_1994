/* Chapter 21 - DatabaseTester */
/* Entry.cp */



// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved. 

#include "Entry.h"
#include <string.h>

static char *CopyOfString(const char *s) 
{
    if (s == NULL)
        s = "";
    char *copy;

    copy = new char[strlen(s)+1];
    ::strcpy(copy, s);
    return copy;
}


TNameAddressPhone::TNameAddressPhone(const char *name, const char *address, const char *city, const char *state, const char *zip, const char *telephone)
{
    fName = fAddress = fCity = fState = fZip = fTelephone = NULL;

    fName = CopyOfString(name);
    fAddress = CopyOfString(address);
    fCity = CopyOfString(city);
    fState = CopyOfString(state);
    fZip = CopyOfString(zip);
    fTelephone = CopyOfString(telephone);
}

TNameAddressPhone::~TNameAddressPhone() 
{
    delete [] fName; 
    delete [] fAddress; 
    delete [] fCity; 
    delete [] fState; 
    delete [] fZip; 
    delete [] fTelephone;
}

const char *TNameAddressPhone::GetName() const
{
    return fName;
}

const char *TNameAddressPhone::GetAddress() const 
{
    return fAddress;
}

const char *TNameAddressPhone::GetCity() const
{
    return fCity;
}

const char *TNameAddressPhone::GetState() const
{
    return fState;
}

const char *TNameAddressPhone::GetZip() const
{
    return fZip;
}

const char *TNameAddressPhone::GetTelephone() const 
{
    return fTelephone;
}

TEntry::TEntry(const char *name, const char *address, const char *city, const char *state, const char *zip, const char *telephone) : TNameAddressPhone(name, address, city, state, zip, telephone)
{
}

int TEntry::Compare(const MCollectible &item2) const {

    int compareResult = ::strcmp(GetName(), ((TEntry &) item2).GetName() );

    if (compareResult < 0)
        return kItem1LessThanItem2;
    else if (compareResult > 0)
        return kItem1GreaterThanItem2;
    else
        return kItem1EqualItem2;
}


