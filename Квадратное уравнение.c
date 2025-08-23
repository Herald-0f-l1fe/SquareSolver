#include <stdio.h>
#include <cmath>
#include <TXLib.h>
#include <float.h>

enum nRoots
{
    zero_roots,
    one_root,
    two_roots,
    inf_roots,
    none
};


enum nRoots square_solver(double a, double b, double c,
                          double *x1, double *x2);

enum nRoots line_solver(double b, double c, 
                        double *x1, double *x2);

enum nRoots solver(double a, double b, double c,
                   double *x1, double *x2);

int root_is_zero(double *x1, double *x2);


int double_compare(double a, double b);


void inpuut(double* a, double *b, double *c);


void outpuut(enum nRoots* roots, double* x1, double* x2);

int main()
{
    printf("Введите коэффициенты a, b, c.\n");

    nRoots roots = none;
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    inpuut(&a, &b, &c);

    roots = solver(a, b, c, &x1, &x2);

    outpuut(&roots, &x1, &x2);

    return 0;
}


int double_compare(double a, double b)
{
    const double eps = 1e-8;

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
            *x1 = -c/b;
            root_is_zero(x1, x2);
            
            return one_root;
        }
}

void inpuut(double* a, double *b, double *c)
{
    while(scanf("%lg %lg %lg", a, b, c)!=3)
    {   while(getchar() != '\n');//очитска буффера
        printf("Попробуйте ещё раз, пожалуйста.\n");
    }
}
void outpuut(enum nRoots* roots, double* x1, double* x2)
{
    switch (*roots)
    {

        case  zero_roots:
            printf("Действительных корней нет.\n");
            printf("Спасибо за использование.\n");
            break;

        case  one_root:
            printf("Имеется только один корень: x = %lg.\n", *x1);
            printf("Спасибо за использование.\n");
            break;

        case  two_roots:
            printf("Имеется 2 корня: x1 = %lg, второй корень %lg.\n", *x1, *x2);
            printf("Спасибо за использование.\n");
            break;

        case  inf_roots:
            printf("У данного уравнения бесконечно много корней.\n");
            printf("Спасибо за использование.\n");
            break;

        default:
            printf("Что-то пошло не так.\n");
            printf("Спасибо за использование.\n");

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
