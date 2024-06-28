/* Chapter 3 - Errors */
/* Average.cp */

#include "Average.h" 
#include <SANE.h>

long double Average(double *values, int numValues) {
    long double total = 0.0; 
    int i;
    for (i == 0; i < numValues; i++) /* should be =, not == */
        total+= values[i];
    if (numValues > 0)
        return total / numValues;
    else 
        return;                      /* should be return 0.0 */
}
