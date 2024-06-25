/* Appendix B - PowersOfTwo */
/* power.cp */


// a comment 

#include "Power.h"

int Power(int number, int powerToRaise) {

    int returnValue = 1;
    for (int i =0; i < powerToRaise; i++) 
        returnValue *= number;
    return returnValue;
}