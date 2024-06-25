/* Chapter 21 - DatabaseTester */
/* Database.cp */


// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.

#include "Database.h"

MCollectible::MCollectible() {
}

MCollectible::-MCollectible()
{ }

int MCollectible::Compare(const MCollectible &item2) const
{

if (this < &item2)
return kitem1LessThanitem2;
else if (this > &item2)
return kitem1GreaterThanitem2;
else
return kitem1Equalitem2;
}

TDatabase::TDatabase()
{
    fRoot = NULL;
}
TDatabase::-TDatabase()
{
    delete fRoot;
}


void TDatabase::Insert(MCollectible* dataElement) {

if (fRoot == NULL)
fRoot = new TNode(dataElement);
else fRoot->Insert(dataElement);
}

MCollectible *TDatabase::Find(const MCollectible& key) const {
if (fRoot == NULL) return NULL;
else
return fRoot->Find(key);
}

TNode::TNode(MCollectible *value, TNode *up) {
fRight =fLeft =NULL; fUp = up;
fValue =value;
}

TNode: :-TNode() {
delete fRight; delete fLeft; delete fValue;
}

MCollectible *TNode::GetValue() const {
return fValue;
}

MCollectible *TNode::Find(const MCollectible&key) const {
const TNode *node = this; while (node I= NULL) {





int compareResult = node->GetValue()->Compare(key);
i f (compareResult == MCollectible::kitem1Equalitem2) return node->GetValue();
else if (compareResult <= MCollectible::kitem1LessThanitem2) node node->fRight;
else
node node->fLeft;
}
return NULL;
void TNode::Insert(MCollectible *value) {
TNode **node = &this; II after loop: holds address within previous node II which points to current node
TNode *up = NULL; II after loop: pointer to previous node do {
int compareResult = (*node)->GetValue()·>Compare(*value); up = *node; II points at the current node
if (compareResult == MCollectible::kitem1Equalitem2) {
delete value; return;
}
else if (compareResult <= MCollectible::kitem1LessThanitem2)
else
node= &(*node)->fRight;
// advance to next node
// advance to next node
node= &(*node)->fLeft; 
    } while (*node !=NULL);
    *node= new TNode(value, up);
}

const TNode *TNode::LeftMost() const {
    const TNode *n = this;
    while (n->fLeft I= NULL)
        n = n->fLeft;





 return n; 
}

const TNode *TNode::RightMost() const
{
    const TNode *n = this;
    while (n->fRight I= NULL) 
        n = n->fRight;
    return n;
}

TIterator::TIterator(const TDatabase &database): fDatabase(database)
{
fCurrent = NULL;
}

TNode *TIterator::GetRoot()
{
}
return fDatabase.fRoot;

void TIterator::MoveForward() {
    if (fCurrent == NULL)
        MoveToBeginning();
    // if we have a right-hand side, the next node is the left-most of our RHS) 
    else if (fCurrent->fRight I= NULL)
        fCurrent = fCurrent->fRight->LeftMost();
    else if (fCurrent->fUp ==NULL) // if we don't have a RHS, and don't have an up, we'redone
        fCurrent = NULL;
    else {
        // the next is our first ancestor who we are on the left-hand-side of
        const TNode *last;
        do {
            last = fCurrent;
            fCurrent = last->fUp;
        } while (fCurrent I= NULL && fCurrent->fRight == last) ;
    }
}



void TIterator::MoveBackward() {
    if (fCurrent == NULL) MoveToEnd();
// if we have a left-hand side, the next node is the right-most of our LHS 
    else if (fCurrent->fLeft != NULL)
        fCurrent = fCurrent->fLeft->RightMost();
    else if (fCurrent->fUp ==NULL) // if we don't have a L.HS, and don't have an up, we're done
        fCurrent = NULL; 
    else {

// the next is our first ancestor who we are on the right-hand-side of 
        const TNode *last;
        do {
            last = fCurrent;
            fCurrent = last->fUp;
        } while (fCurrent != NULL && fCurrent->fLeft==last);
    }
}

int TIterator::NoMore() {
return fCurrent == NULL;
}

int TIterator::AtBeginning()
{

return fCurrent !=NULL && GetRoot()->LeftMost() ==fCurrent;
}

int TIterator::AtEnd() {
return fCurrent !=NULL && GetRoot()->RightMost() == fCurrent;
}

MCollectible *TIterator::Getcurrent()
{
    if (fCurrent == NULL) 
        return NULL;
    else
        return fCurrent->GetValue();
}

void TIterator::MoveToBeginning() {
    if (GetRoot()  == NULL)
        fCurrent= NULL;

else 
fCurrent=GetRoot()·>LeftMost();

}

void TIterator::MoveToEnd() {
    if (GetRoot() ==NULL)
fCurrent= NULL;
    else
fCurrent = GetRoot()·>RightMost();


}