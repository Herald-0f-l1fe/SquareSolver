#include <stdio.h>
#include <cmath>
#include <TXLib.h>
#include <float.h>
int squaresolver(double a, double b, double c,
           double *x1, double *x2);


int rootisnull(double *x1, double *x2);


int inaccuracy(double a, double b);


int main()
{
    printf("Введите коэффициенты a, b, c\n");
    int prov = -2;
    double a, b, c  , x1 , x2;
    a = b = c = x1 = x2 = NAN;

    while(scanf("%lg %lg %lg", &a, &b, &c)!=3)
    {
        printf("Попробуйте ещё раз, пожалуйста\n");
        scanf("%lg %lg %lg", &a, &b, &c);
    }
    prov = squaresolver(a, b, c, &x1, &x2);
    rootisnull(&x1, &x2);
    switch (prov)
    {
        case -1: printf("Выражение не зависит от x"); break;
        case  0: printf("Действительных корней нет"); break;
        case  1: printf("Имеется только один корень x = %lg", x1); break;
        case  2: printf("Имеется 2 корня x1 = %lg  второй корень %lg", x1, x2); break;
        case  3: printf("У данного уравнения бесконечно много корней");break;
        default: printf("Ты молодец");

    }
    return 0;
}


int inaccuracy(double a, double b)
{
    const double eps = DBL_MIN;
    return fabs(a-b) < eps;
}


int rootisnull(double *x1, double *x2)   // TODO: Поменять название
{
    (inaccuracy(*x1, 0)) ? *x1 = 0: *x1 = * x1;
    (inaccuracy(*x2, 0)) ? *x2 = 0: *x2 = *x2;
    return 0;
}


int squaresolver(double a, double b, double c,
           double *x1, double *x2)
{
    double diskr = -1; /*Устанавливаю значение дискриминанта*/
    if (inaccuracy(a, 0))
    {
        if (inaccuracy(b, 0))
        {
            if (inaccuracy(c, 0))
            {
                return 3; /*Бесконено много корней*/
            }
            else
            {
                return -1; /*Корней нет, потому что выражение не зависит от x*/
            }
        }
        else
        {
            assert(x1 != NULL);
            *x1 = -c/b; /*Линейное уравнение*/
            return 1;
        }
    }
    else
    {
        diskr = b * b - 4 * a * c;
        if (diskr<0)
        {
            return 0;  /*Действительных корней нет*/
        }
        else if (inaccuracy(diskr, 0))
        {
            *x1 = -b / (2 * a); /*Действительных корней нет*/
            return 1;
        }
        else
        {
            double sqrt_d;
            sqrt_d = sqrt(diskr);
            assert(x1 != NULL);
            *x1 = (-b - sqrt_d)/(2 * a);
            assert(x2 != NULL);
            *x2 = (-b + sqrt_d)/(2 * a);
            return 2;
        }
    }
}
