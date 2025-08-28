#include <TXLib.h>
#include <stdio.h>
#include <cmath>
#include <cassert>
#include <float.h>
#include "function_calls.h"

//-------------------------------------------------------------
//СЃРґРµР»Р°С‚СЊ С„Р°Р№Р»
//РїРѕРґРµР»РёС‚СЊ РЅР° С„Р°Р№Р»С‹
//
int main()
{
    nRoots roots = none;
    double x1 = 0, x2 = 0;
    unit_test(&x1, &x2);
    //x1 = NAN; x2 = NAN; РЅРµРѕР±СЏР·Р°С‚РµР»СЊРЅРѕ

    //input_coef(&coef);

    //roots = solver(coef,  &x1, &x2);

    //output_solution(&roots, x1, x2);

    return 0;
}

//-------------------------------------------------------------

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

nRoots square_solver(coefficients coefs, 
    double* x1, double* x2)
{
    double diskr = -1; /*РЈСЃС‚Р°РЅР°РІР»РёРІР°СЋ Р·РЅР°С‡РµРЅРёРµ РґРёСЃРєСЂРёРјРёРЅР°РЅС‚Р°*/
    diskr = coefs.b * coefs.b - 4 * coefs.a * coefs.c;
    FILE * f = fopen("TXLib_(((.txt", "w");
    fprintf(f, "%lg", diskr);
    fclose(f);
    if (diskr < 0)
    {
        return zero_roots;  /*Р”РµР№СЃС‚РІРёС‚РµР»СЊРЅС‹С… РєРѕСЂРЅРµР№ РЅРµС‚*/
    }

    else if (double_compare(diskr, 0))
    {
        *x1 = -coefs.b / (2 * coefs.a);
        *x2 = *x1;

        root_is_zero(x1, x2);
        return one_root;
    }

    else
    {
        double sqrt_d = sqrt(diskr);

        *x1 = (-coefs.b - sqrt_d)/(2 * coefs.a);
        *x2 = (-coefs.b + sqrt_d)/(2 * coefs.a);

        root_is_zero(x1, x2);
        return two_roots;
    }
}

nRoots linear_solver(coefficients coefs, double *x1, double *x2)
{   
    if (double_compare(coefs.b, 0))
        {
            if (double_compare(coefs.c, 0))
            {
                return inf_roots; /*Р‘РµСЃРєРѕРЅРµРЅРѕ РјРЅРѕРіРѕ РєРѕСЂРЅРµР№*/
            }

            else
            {
                return zero_roots; /*РљРѕСЂРЅРµР№ РЅРµС‚, РїРѕС‚РѕРјСѓ С‡С‚Рѕ РІС‹СЂР°Р¶РµРЅРёРµ РЅРµ Р·Р°РІРёСЃРёС‚ РѕС‚ x*/
            }
        }

        else
        {
            *x1 = -coefs.c/coefs.b;
            *x2 = *x1;

            root_is_zero(x1, x2);
            return one_root;
        }
}

/*void input_coef(coefficients* coefs)
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
            break;

        case  one_root:
            printf("There is only one root: x = %lg.\n", x1);
            printf("Thanks for using the program.\n");
            break;

        case  two_roots:
            printf("There are two roots: the first is x1 = %lg, the second is %lg.\n", x1, x2);
            printf("Thanks for using the program.\n");
            break;

        case  inf_roots:
            printf("This equation has infinitely many roots.\n");
            printf("Thanks for using the program.\n");
            break;

        case none:
            printf("Something went wrong.\n");
            printf("Thanks for using the program.\n");
            break;
        default:
            printf("Something went wrong.\n");
            printf("Thanks for using the program.\n");

    }
}
*/
nRoots solver(coefficients coefs, double *x1, double *x2)
{
    nRoots roots;

    if (double_compare(coefs.a, 0))
    {
        roots = linear_solver(coef, x1, x2);
    }
    else
    {
        roots = square_solver(coef, x1, x2);
    }
    if (*x1>*x2)
    {
        root_sort(x1, x2);
    }
    return roots;
}

int one_test(double* x1, double *x2, test_coefficients Ref)
{   
    coef.a = Ref.a; coef.b = Ref.b; coef.c = Ref.c;
    nRoots root = solver(coef, x1, x2);
    nRoots rootref = Ref.roots;
    if (root != rootref)
    {
        printf ("Failed: solver(%lg, %lg, %lg) gives x1 = %lg, x2 = %lg, should be x1 = %lg, x2 = %lg\n", Ref.a, Ref.b, Ref.c, *x1, *x2, Ref.x1_ref, Ref.x2_ref);
        return 0;
    }
    else
    {
        if (root == zero_roots || root == inf_roots || root == none)
        {
            return 1;
        }

        else if ((root == one_root || root == two_roots) && double_compare(*x1, Ref.x1_ref) && double_compare(*x2, Ref.x2_ref))
        {
            return 1;
        }

        else
        {
            printf ("Failed: solver(%lg, %lg, %lg) gives:\n  roots = %d, x1 = %lg, x2 = %lg \n should be:\n roots = %d x1 = %lg, x2 = %lg\n", Ref.a, Ref.b, Ref.c, root, *x1, *x2, rootref, Ref.x1_ref, Ref.x2_ref);
            return 0;
        }
    }
    return 0;
}

int unit_test(double* x1, double* x2)
{
    size_t size_mas = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;
    
    for (size_t i = 0; i < size_mas; i++)
    {
       passed += one_test(x1, x2, tests[i]);
    }
    printf("Passed tests: %d.\n", passed);
    return passed;
}

/*void buffer_cleaner()
{
    while(getchar() != '\n');
    printf("Please try again.\n");
}
*/
void root_sort(double* x1, double* x2)
{
    *x1 += *x2;
    *x2 = *x1 - *x2;
    *x1 = *x1 - *x2;
}
