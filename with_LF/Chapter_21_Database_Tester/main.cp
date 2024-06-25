/* Chapter 21 - DatabaseTester */
/* main.cp */




// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.
#include "Database.h" 
#include "Entry.h" 
#include <iostream.h> 
#include <stdio.h>

void FindAndPrint(const TDatabase &theDatabase, char *name) {
    TEntry *entry= (TEntry *) theDatabase.Find(TEntry(name)); 
    if (entry l= NULL)
        cout « "Name: " « entry->GetName() << "Address: " « entry->GetAddress() << '\n';
}

void PrintDatabase(const TDatabase &theDatabase) {
    printf("Database\n:");
    Titerator iter(theDatabase);
    for (iter.MoveToEnd(); liter.NoMore(); iter.MoveBackward()) {
        TEntry *entry= (TEntry *) iter.GetCurrent();
        if (entry)
            cout << entry->GetName() << '\n' << entry->GetAddress() << '\n' << entry->GetCity() « ", " « entry->Getstate() « " " « entry->GetZip() « '\n' « entry->GetTelephone() << '\n';

    } 
}

void main()
{
    TDatabase theDatabase;

    theDatabase.Insert (new TEntry ("Rhodes, Neil", "1328 Clock Avenue", "Redlands", 'CA", "92374", "(909) 798-5792'));
    theDatabase.Insert (new TEntry ("McKeehan, Julie", "1328 Clock Avenue", "Redlands', "CA', "92374', "(909) 798-5792'));
    theDatabase.Insert (new TEntry("Rhodes, Alexander", "1328 Clock Avenue", "Redlands", "CA', "92374', "(909) 798-5792'));
    theDatabase.Insert(new TEntry("Rhodes, Nicholas", "1328 Clock Avenue",



"Redlands", "CA", "92374", "(909) 798-5792")); 
    theDatabase.Insert(new TEntry("Rhodes, Mary", "1234 Main St.",
"Fullerton", "CA", "92635", "(714) 555-1212")); 
    theDatabase.Insert(new TEntry("Rhodes, Fen•, "123 Park Avenue",
"Long Beach", "CA", "02138", "(310) 798-5792"));
    theDatabase.Insert(new TEntry("La Galy, Carolyn", "123 Longridge Avenue",
"Santa Monica", "CA", "92374", "(818) 555-1212")); 
    PrintDatabase(theDatabase);

    FindAndPrint(theDatabase, "Rhodes, Neil");
    FindAndPrint(theDatabase, "McKeehan, Julie");
    FindAndPrint(theDatabase, "Rhodes, Alexander");
    FindAndPrint(theDatabase, "Rhodes, Nicholas"); 
    FindAndPrint(theDatabase, "Rhodes, Fen");
    FindAndPrint(theDatabase, "Rhodes, Mary");
    FindAndPrint(theDatabase, "La Galy, Carolyn");


}