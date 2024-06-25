/* Chapter 21 - DatabaseTester */
/* Database.h */


#pragma once

class MCollectible { 
public:
    enum {kitem1Equalitem2 = 0, kitem1LessThanitem2 -1, kitem1GreaterThanitem2 = 1};
    MCollectible();
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

    MCollectible *fValue; TNode *fLeft;
    TNode *fRight;
    TNode *fUp;
    friend class erator;
};

class TDatabase { 
public:
    TDatabase () ;
    virtual -TDatabase();

    void Insert(MCollectible* dataElement);
    MCollectible *Find(const MCollectible& key) const;

private:
    TNode *fRoot;
    friend class erator; 
};

class erator { 
public:
    erator(const TDatabase &database);
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
};
