/* Chapter 21 - DatabaseTester */
/* Entry.h */




#pragma once

#include "Database.h"

class TNameAddressPhone { 
public:
    TNameAddressPhone(const char *name = NULL, const char *address = NULL,
const char *fCity = NULL, const char *fState = NULL, const char *fZip =NULL, const char *fTelephone =NULL);
    virtual -TNameAddressPhone();

    const char *GetName() const;
    const char *GetAddress() const;
    const char *GetCity() const;
    const char *GetState() const;
    const char *GetZip() const;
    const char *GetTelephone() const;

private:
    char *fName;
    char *fAddress; 
    char *fCity;
    char *fState; 
    char *fZip;
    char *fTelephone;
};

class TEntry: public MCollectible, public TNameAddressPhone { 
public:
    TEntry(const char *name = NULL, const char *address = NULL, const char *fCity = NULL, const char *fState = NULL, const char *fZip =NULL, const char *fTelephone =NULL);
    virtual int Compare(const MCollectible &item2) const; 
};



