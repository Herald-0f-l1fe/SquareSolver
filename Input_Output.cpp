#include <TXLib.h>
#include <stdio.h>
#include "Input_Output.h"
#include "Supportive_func.h"
#include "Structures.h"
#include "Colors.h"

void input_coef(coefficients* coefs)
{   
    printf(ANSI_COLOR_CYAN "Enter the coefficients of the equations " ANSI_COLOR_GREEN "a" ANSI_COLOR_RESET", " ANSI_COLOR_GREEN "b" ANSI_COLOR_RESET", " ANSI_COLOR_GREEN "c" ANSI_COLOR_RESET"\n");
    printf(ANSI_COLOR_GREEN"a" ANSI_COLOR_RESET "x^2 + " ANSI_COLOR_GREEN "b" ANSI_COLOR_RESET 
        "x + " ANSI_COLOR_GREEN"c" ANSI_COLOR_RESET" = 0\n");

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
            printf(ANSI_COLOR_RED"There are no valid roots.\n" ANSI_COLOR_RESET);
            printf("Thanks for using the program.\n");
            printf("GITHUB");
            break;

        case  one_root:
            printf("There is only one root: " ANSI_COLOR_GREEN "x = %lg.\n" ANSI_COLOR_RESET, x1);
            printf("Thanks for using the program.\n");
            printf("GITHUB");
            break;

        case  two_roots:
            printf("There are two roots: the first is " ANSI_COLOR_GREEN "x1 = %lg" ANSI_COLOR_RESET ", the second is " ANSI_COLOR_GREEN "x2 = %lg.\n" ANSI_COLOR_RESET, x1, x2);
            printf("Thanks for using the program.\n");
            printf("GITHUB");

            break;

        case  inf_roots:
            printf(ANSI_COLOR_MAGENTA "This equation has infinitely many roots.\n" ANSI_COLOR_RESET);
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
