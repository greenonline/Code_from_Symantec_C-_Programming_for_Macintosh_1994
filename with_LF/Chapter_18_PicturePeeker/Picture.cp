/* Chapter 18 - PicturePeeker */
/* Picture.cp */

// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.
#include "CPictureApp.h"
void main(){
    CPictureApp *app;
    app = new CPictureApp;
    app ->Run() ;
    app->Exit();
}