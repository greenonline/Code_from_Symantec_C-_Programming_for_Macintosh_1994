/* Chapter 2 - Multiple files */
/* Factorial.cp */

#include "Factorial.h"
unsigned long Factorial(unsigned long n)
{
unsigned long result= 1; 
unsigned long i;
for (i = 2; i <= n; i++) 
    result *= i;
return result;
}