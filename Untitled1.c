#include <stdio.h>
#include <cmath>
#include <TXLib.h>
int square(double a, double b, double c,
           double *x1, double *x2);
int main()
{
    printf("Введите коэффиеценты a, b, c\n");
    int prov = -2;
    double a, b, c, x1 , x2;
    a = b = c = x1 = x2 = NAN;
    scanf("%g %g %g", &a, &b, &c);
    prov = square(a, b, c, &x1, &x2);
    switch (prov)
    {
        case -1: printf("Выражение не зависит от x"); break;
        case  0: printf("Действительных корней нет"); break;
        case  1: printf("Имеется только один корень %g", x1); break;
        case  2: printf("Имеется 2 корня x1 = %g  второй корень %g", x1, x2); break;
        case  3: printf("У данного уравнения бесконечно много корней");break;

    }
    return 0;
}

int square(double a, double b, double c,
           double *x1, double *x2)
{
    float d = -1; /*Устанавливаю значение дискриминанта*/
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
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
            assert(x1 != nullptr);
            *x1 = -c/b; /*Линейное уравнение*/
            return 1;
        }
    }
    else
    {
        d = b * b - 4 * a * c;
        if (d < 0)
        {
            return 0;  /*Действительных корней нет*/
        }
        else if (d == 0)
        {
            *x1 = -b / (2 * a); /*Действительных корней нет*/
            return 1;
        }
        else
        {
            assert(x1 != nullptr);
            *x1 = (-b - sqrt(d))/(2 * a);
            assert(x2 != nullptr);
            *x2 = (-b + sqrt(d))/(2 * a);
            return 2;
        }
    }
}
\