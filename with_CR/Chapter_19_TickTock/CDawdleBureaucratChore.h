/* Chapter 19 - TickTock *//* CDawdleBureaucratChore.h */#pragma once#include <CChore.h> #include <CBureaucrat.h>class CDawdleBureaucratChore: public CChore { public:    CDawdleBureaucratChore(CBureaucrat *theBureaucrat);    virtual void Perform(long *maxSleep);private:     CBureaucrat *fBureaucratToDawdle;};