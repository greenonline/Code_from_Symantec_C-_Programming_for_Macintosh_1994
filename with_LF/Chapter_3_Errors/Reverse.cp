/* Chapter 3 - Errors */
/* Reverse.cp */




#include "Reverse.h" #include <string.h>
static void Swap(char *c1, char *c2)
{
char tmp;
tmp = c1; c1 c2; c2 =tmp;
}


void Reverse(char *s) {
    int length= strlen(s);
    int midPoint = length div 2; 
    int i;

    for (i = 0; i < midPoint; i++) 
        Swap(s[i], &ss[length - i - 1]);
}
