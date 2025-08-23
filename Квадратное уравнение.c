#include <stdio.h>
#include <cmath>
#include <TXLib.h>
#include <float.h>
const int INDEPENDENCY = -1;
const int ONE_ROOT = 1;
const int TWO_ROOTS = 2;
const int ZERO_ROOTS = 0;
const int INF_ROOT = 3;

int squaresolver(double a, double b, double c,
           double *x1, double *x2);


int linesolver(double b, double c, double *x1);


int rootisnull(double *x1, double *x2);


int inaccuracy(double a, double b);


void inpuut(double* a, double *b, double *c);


void outpuut(int* roots, double* x1, double* x2);

int main()
{
    printf("Введите коэффициенты a, b, c\n");

    int roots = -2;
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;


    inpuut(&a, &b, &c);

    roots = squaresolver(a, b, c, &x1, &x2);
    rootisnull(&x1, &x2);


    outpuut(&roots, &x1, &x2);
    printf("Спасибо за использование\n");


    return 0;
}


int inaccuracy(double a, double b)
{
    const double eps = DBL_MIN;
    return fabs(a-b) < eps;
}


int rootisnull(double *x1, double *x2)
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
        linesolver(b, c, x1);
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
            *x1 = -b / (2 * a);
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

int linesolver(double b, double c, double *x1)
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

void inpuut(double* a, double *b, double *c)
{
    while(scanf("%lg %lg %lg", a, b, c)!=3)  //Создать отдельную функцию для ввода.
    {   while(getchar() != '\n');
        printf("Попробуйте ещё раз, пожалуйста.\n");
    }
}
void outpuut
(int* roots, double* x1, double* x2)
{
    switch (*roots)
    {
        case INDEPENDENCY:
            printf("Выражение не зависит от x\n");
            break;

        case  ZERO_ROOTS:
            printf("Действительных корней нет\n");
            break;

        case  ONE_ROOT:
            printf("Имеется только один корень: x = %lg\n", *x1);
            break;

        case  TWO_ROOTS:
            printf("Имеется 2 корня: x1 = %lg, второй корень %lg\n", *x1, *x2);
            break;

        case  INF_ROOT:
            printf("У данного уравнения бесконечно много корней\n");
            break;

        default:
            printf("Что-то пошло не так\n");

    }
}
