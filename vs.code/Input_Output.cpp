#include <TXLib.h>
#include <stdio.h>
#include "Input_Output.h"
void input_coef(coefficients* coefs)
{   
    printf("Enter the coefficients of the equations a, b, c\n");

    while(scanf("%lg %lg %lg", &coefs->a, &coefs->b, &coefs->c)!=3)
    {
        buffer_cleaner();
    }
}

void output_solution(nRoots* roots, double x1, double x2)
{
    switch (*roots)
    {

        case  zero_roots:
            printf("There are no valid roots.\n");
            printf("Thanks for using the program.\n");
            printf("GITHUB");
            break;

        case  one_root:
            printf("There is only one root: x = %lg.\n", x1);
            printf("Thanks for using the program.\n");
            printf("GITHUB");
            break;

        case  two_roots:
            printf("There are two roots: the first is x1 = %lg, the second is %lg.\n", x1, x2);
            printf("Thanks for using the program.\n");
            printf("GITHUB");

            break;

        case  inf_roots:
            printf("This equation has infinitely many roots.\n");
            printf("Thanks for using the program.\n");
            printf("GITHUB");
            break;

        case none:
            printf("Something went wrong.\n");
            printf("Thanks for using the program.\n");
            printf("GITHUB");

            break;
        default:
            printf("Something went wrong.\n");
            printf("Thanks for using the program.\n");
            printf("GITHUB");
    }
}
