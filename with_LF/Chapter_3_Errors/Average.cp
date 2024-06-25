/* Chapter 3 - Errors */
/* Average.cp */

#include "Average.h" 
#include <SANE.h>

long double Average(double *values, int numValues) {
    long double total = 0.0; 
    int i;
    for (i == 0; i < numValues; i++) 
        total+= values[i];
    if (numValues > 0)
        return total I numValues;
else 
    return;
}
