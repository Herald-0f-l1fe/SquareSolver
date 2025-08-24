#include <stdio.h>
#include <cmath>
//#include <TXLib.h>
#include <cassert>
#include <float.h>
enum nRoots
{
    zero_roots,
    one_root,
    two_roots,
    inf_roots,
    none
};
struct test_koefficients
{
    double a;
    double b;
    double c;
    enum nRoots roots;
    double x1_ref;
    double x2_ref;
};
struct test_koefficients tests[] =
    {
    {0, 0, 0, inf_roots, NAN, NAN}, 
    {1, 2, 1, one_root, -1, -1},
    {1, 3, 2, two_roots, -2, -1},
    {0, 1, 1, one_root, -1, -1},
    {1, 0, -4, two_roots, -2,  2},
    {1, 5, 0, two_roots, -5, 0},
    {1, 5, 6, two_roots, -3, -2},
    {1, -5, 6, two_roots, 2, 3},
    {0, 0, 5, zero_roots, NAN, NAN},
    {5, 0, 0, one_root, 0, 0}
    };

enum nRoots square_solver(double a, double b, double c,
           double *x1, double *x2);

enum nRoots line_solver(double b, double c, double *x1, double *x2);

enum nRoots solver(double a, double b, double c,
           double *x1, double *x2);

int root_is_zero(double *x1, double *x2);


int double_compare(double a, double b);


void inpuut(double* a, double *b, double *c);

int unit_test(struct test_koefficients tests[], double* x1, double*x2);

int one_test(double a, double b, double c, double *x1, double *x2, enum nRoots roots, double x1ref, double x2ref);

void outpuut(enum nRoots* roots, double* x1, double* x2);

int main()
{
    printf("Enter the coefficients of the equations a, b, c\n");

    nRoots roots = none;
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int passed_tests = unit_test(tests, &x1, &x2);
    printf("%d\n", passed_tests);
    x1 = NAN;
    x2 = NAN;
    inpuut(&a, &b, &c);

    roots = solver(a, b, c, &x1, &x2);


    outpuut(&roots, &x1, &x2);

    return 0;
}


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


enum nRoots square_solver(double a, double b, double c,
           double *x1, double *x2)
{
    double diskr = -1; /*Устанавливаю значение дискриминанта*/
    diskr = b * b - 4 * a * c;
    if (diskr < 0)
    {
        return zero_roots;  /*Действительных корней нет*/
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

enum nRoots line_solver(double b, double c, double *x1, double *x2)
{
    if (double_compare(b, 0))
        {
            if (double_compare(c, 0))
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
            assert(x1 != NULL);
            *x1 = -c/b;
            *x2 = *x1;
            root_is_zero(x1, x2);
            return one_root;
        }
}

void inpuut(double* a, double *b, double *c)
{
    while(scanf("%lg %lg %lg", a, b, c)!=3)  //Создать отдельную функцию для ввода.
    {   while(getchar() != '\n');
        printf("Please try again.\n");
    }
}
void outpuut(enum nRoots* roots, double* x1, double* x2)
{
    switch (*roots)
    {

        case  zero_roots:
            printf("There are no valid roots.\n");
            printf("Thanks for using the program.\n");
            break;

        case  one_root:
            printf("There is only one root: x = %lg.\n", *x1);
            printf("Thanks for using the program.\n");
            break;

        case  two_roots:
            printf("There are two roots: the first is x1 = %lg, the second is %lg.\n", *x1, *x2);
            printf("Thanks for using the program.\n");
            break;

        case  inf_roots:
            printf("This equation has infinitely many roots.\n");
            printf("Thanks for using the program.\n");
            break;

        case none:
            printf("Something went wrong.\n");
            printf("Thanks for using the program.\n");

        default:
            printf("Something went wrong.\n");
            printf("Thanks for using the program.\n");

    }
}

enum nRoots solver(double a, double b, double c,
           double *x1, double *x2)
{
    enum nRoots roots;

    if (double_compare(a, 0))
    {
        roots = line_solver(b, c, x1, x2);
    }
    else
    {
        roots = square_solver(a, b, c, x1, x2);
    }
    return roots;
}

int one_test(double a, double b, double c, double* x1, double *x2, enum nRoots rootref, double x1ref, double x2ref)
{
    enum nRoots root = solver(a, b, c, x1, x2);
    if (root != rootref)
    {
        printf ("Failed: solver(%lg, %lg, %lg) gives x1 = %lg, x2 = %lg, should be x1 = %lg, x2 = %lg\n", a, b, c, *x1, *x2, x1ref, x2ref);
        return 0;
    }
    else
    {
        if (root == zero_roots || root == inf_roots || root == none)
        {
            return 1;
        }
        else if ((root == one_root || root == two_roots) && double_compare(*x1, x1ref) && double_compare(*x2, x2ref))
        {
            return 1;
        }
        else {
            printf ("Failed: solver(%lg, %lg, %lg) gives:\n roots = %d, x1 = %lg, x2 = %lg \n should be:\n roots = %lg x1 = %lg, x2 = %lg\n", a, b, c, root, *x1, *x2, rootref, x1ref, x2ref);
            return 0;
        }
    }
}

int unit_test(struct test_koefficients tests[], double* x1, double* x2)
{
    int size_mas = sizeof(tests) / sizeof(tests[0]);
    printf("%d %d", sizeof(tests), sizeof(tests[0]));
    int passed = 0;
    for (int i = 0; i < size_mas; i++)
    {

       passed += one_test(tests[i].a, tests[i].b, tests[i].c, x1, x2, tests[i].roots, tests[i].x1_ref, tests[i].x2_ref);
    }
    return passed;
}
