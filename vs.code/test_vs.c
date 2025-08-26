#include <TXLib.h>
#include <stdio.h>
#include <cmath>
#include <cassert>
#include <float.h>
#include "function_calls.h"

//-------------------------------------------------------------
//сделать файл
//поделить на файлы
//
int main()
{
    nRoots roots = none;
    double x1 = 0, x2 = 0;
    test_file_reader(tests);
    unit_test(&x1, &x2);

    input_coef(&coef);

    roots = solver(coef,  &x1, &x2);

    output_solution(&roots, x1, x2);

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

void test_file_reader(test_coefficients tests_coef[])
{
    FILE * file_pointer = fopen("quare_tests.txt", "r");
    if (file_pointer == NULL)
    {
        printf("Something went wrong.");
        exit(1);
    }
    else
    {   
        int i = 0;
        //сделать чтобы считывалось 
        while(read_file(file_pointer, &tests_coef[i])){
            i++;
        }

    }
    fclose(file_pointer);
    //struct FILE *
}

int read_file(_iobuf* fp, test_coefficients* Ref)
{
    nRoots root = none; 
    double testing[] = {NAN, NAN, NAN, NAN, NAN};
    if (fscanf(fp, "%lg %lg %lg %d %lg %lg", &testing[0], &testing[1], &testing[2], (int*)&root, &testing[3], &testing[4]) == 6)
    {
        Ref->a = testing[0]; Ref->b = testing[1]; Ref->c = testing[2]; Ref->roots = root, Ref->x1_ref = testing[3], Ref->x2_ref = testing[4];
        return 1;
    }
    else
    {
        return 0;
    }  
}

nRoots square_solver(coefficients coefs, 
    double* x1, double* x2)
{
    double diskr = -1; /*Устанавливаю значение дискриминанта*/
    diskr = coefs.b * coefs.b - 4 * coefs.a * coefs.c;
        if (diskr < 0)
        {
            return zero_roots;  /*Действительных корней нет*/
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
                return inf_roots; /*Бесконено много корней*/
            }

            else
            {
                return zero_roots; /*Корней нет, потому что выражение не зависит от x*/
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

        else if ((root == one_root || root == two_roots) && ((double_compare(*x1, Ref.x1_ref) && double_compare(*x2, Ref.x2_ref))  || 
                 (double_compare(*x2, Ref.x1_ref) && double_compare(*x1, Ref.x2_ref))))
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
    size_t size_mas = 50;
    int passed = 0;
    
    for (size_t i = 0; i < size_mas; i++)
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

void root_sort(double* x1, double* x2)
{
    *x1 += *x2;
    *x2 = *x1 - *x2;
    *x1 = *x1 - *x2;
}
