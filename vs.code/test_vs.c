//#include <TXLib.h>
#include <stdio.h>
#include <cmath>
#include <cassert>
#include <float.h>
#include "function_calls.h"

//-------------------------------------------------------------

int main()
{
    nRoots roots = none;
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    unit_test(&x1, &x2);
    //x1 = NAN; x2 = NAN; РЅРµРѕР±СЏР·Р°С‚РµР»СЊРЅРѕ
    input_coef(&a, &b, &c);

    roots = solver(a, b, c, &x1, &x2);

    output_solution(&roots, x1, x2);

    return 0;
}

//-------------------------------------------------------------

int double_compare(double a, double b)
{
    const double eps = 1e-10;

    return fabs(a-b) < eps;
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


nRoots square_solver(double a, double b, double c,
           double *x1, double *x2)
{
    double diskr = -1; /*РЈСЃС‚Р°РЅР°РІР»РёРІР°СЋ Р·РЅР°С‡РµРЅРёРµ РґРёСЃРєСЂРёРјРёРЅР°РЅС‚Р°*/
    diskr = b * b - 4 * a * c;

    if (diskr < 0)
    {
        return zero_roots;  /*Р”РµР№СЃС‚РІРёС‚РµР»СЊРЅС‹С… РєРѕСЂРЅРµР№ РЅРµС‚*/
    }

    else if (double_compare(diskr, 0))
    {
        *x1 = -b / (2 * a);
        *x2 = *x1;

        root_is_zero(x1, x2);
        return one_root;
    }

    else
    {
        double sqrt_d = sqrt(diskr);

        *x1 = (-b - sqrt_d)/(2 * a);
        *x2 = (-b + sqrt_d)/(2 * a);

        root_is_zero(x1, x2);
        return two_roots;
    }
}

nRoots linear_solver(double b, double c, double *x1, double *x2)
{
    if (double_compare(b, 0))
        {
            if (double_compare(c, 0))
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
            *x1 = -c/b;
            *x2 = *x1;

            root_is_zero(x1, x2);
            return one_root;
        }
}

void input_coef(double* a, double *b, double *c)
{
    printf("Enter the coefficients of the equations a, b, c\n");

    while(scanf("%lg %lg %lg", a, b, c)!=3)  //РЎРѕР·РґР°С‚СЊ РѕС‚РґРµР»СЊРЅСѓСЋ С„СѓРЅРєС†РёСЋ РґР»СЏ РІРІРѕРґР°.
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

nRoots solver(double a, double b, double c,
           double *x1, double *x2)
{
    nRoots roots;

    if (double_compare(a, 0))
    {
        roots = linear_solver(b, c, x1, x2);
    }
    else
    {
        roots = square_solver(a, b, c, x1, x2);
    }
    return roots;
}

int one_test(double* x1, double *x2, test_coefficients Ref)
{
    nRoots root = solver(Ref.a, Ref.b, Ref.c, x1, x2);
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
}

int unit_test(double* x1, double* x2)
{
    int size_mas = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    for (int i = 0; i < size_mas; i++)
    {
       passed += one_test(x1, x2, tests[i]);
    }
    printf("%d\n", passed);
    return passed;
}

void buffer_cleaner()
{
    while(getchar() != '\n');
    printf("Please try again.\n");
}
