/* Chapter 21 - AddressBook */
/* Database.h */


#pragma once

class MCollectible { 
public:

    enum {kItem1EqualItem2 = 0, kItemm1LessThanItem2 =-1, kItem1GreaterThanItem2 =1};
    MCollectible () ;
    virtual -MCollectible();

    virtual int Compare(const MCollectible &item2) const; 
};

class TNode { 
public:
    TNode(MCollectible *value, TNode *up = NULL);
    -TNode();

    void Insert(MCollectible *value);

     MCollectible *Find(const MCollectible &key) const;

private:
    const TNode *LeftMost() const; 
    const TNode *RightMost() const;

    MCollectible *GetValue() const;

    MCollectible *fValue; 
    TNode *fLeft;
    TNode *fRight;
    TNode *fUp;
    friend class Titerator; 
};

class TDatabase { 
public:
    TDatabase();
    virtual -TDatabase();

    void Insert(MCollectible* dataElement);
    MCollectible *Find(const MCollectible& key) const;

private:
    TNode *fRoot;
    friend class Titerator; };
};

class Titerator { 
public:
    Titerator(const TDatabase &database);

    void MoveForward();
    void MoveBackward();
    int NoMore();
    int AtEnd();
    int AtBeginning();
    void MoveToBeginning();
    void MoveToEnd();
    MCollectible *GetCurrent();

protected:
    TNode *GetRoot();

private:
    const TDatabase &fDatabase;
    const TNode *fCurrent;
}