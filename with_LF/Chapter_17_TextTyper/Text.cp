/* Chapter 17 - TextTyper */
/* Text.cp */

#include "CTextApp.h"
void main()
{
    CTextApp *app;

    app = new CTextApp;
    app->Run();
    app->Exit();
}
