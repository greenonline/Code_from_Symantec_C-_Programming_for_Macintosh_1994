/* Chapter 3 - Errors */
/* Main.cp */


#include <stdio.h> 
//#include "Factorial.h" // Erratum from code listing in Appendix
#include "Reverse.h" 
#include "Average.h"

main ()
{
    int i;
    char s[] = "Neil Rhodes";
    char palindrome[] = "Madam, I'm Adam";
    double values[] ={3.1, 4.1, 5.9, 15.6, 16.3, 15.7};

    printf("Reverse(\"%s\") = ", s); 
    Reverse (s) ;
    printf("\"%s\"\n", s);

    printf("Reverse(\"%s\") = ", palindrome); 
    Reverse(palindrome);
    printf("\'%s\"\n", palindrome);

    printf("Average() =%1f\n", Average(values, sizeof(values) / sizeof(values[0]))); 

    //return 0;  // Erratum from code listing in Appendix
}