#include <TXLib.h>
#include <stdio.h>
#include "Supportive_func.h"
#include "Structures.h"
int double_compare(double a, double b)
{   if (isnan(a) || isnan(b)) 
        return 0;
    else
    {
        const double eps = 1e-10;
        return fabs(a-b) < eps;
    }
}


int root_is_zero(double *x1, double *x2)
{
    if (double_compare(*x1, 0))
    {
        *x1 = 0;
    }

    if (double_compare(*x2, 0))
    {
        *x2 = 0;
    }

    return 0;
}

void root_sort(double* x1, double* x2)
{
    *x1 += *x2;
    *x2 = *x1 - *x2;
    *x1 = *x1 - *x2;
}

void buffer_cleaner()
{
    while(getchar() != '\n');
    printf("Please try again.\n");
}
