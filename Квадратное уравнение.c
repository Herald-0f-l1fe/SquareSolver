#include <stdio.h>
#include <cmath>
#include <TXLib.h>
int square(double a, double b, double c,
           double *x1, double *x2);
int isnull(double *x1, double *x2);
int greh(double a, double b);
int main()
{
    printf("������� ������������ a, b, c\n");
    int prov = -2;
    double a, b, c, x1 , x2;
    a = b = c = x1 = x2 = NAN;
    scanf("%lg %lg %lg", &a, &b, &c);
    prov = square(a, b, c, &x1, &x2);
    isnull(&x1, &x2);
    switch (prov)
    {
        case -1: printf("��������� �� ������� �� x"); break;
        case  0: printf("�������������� ������ ���"); break;
        case  1: printf("������� ������ ���� ������ x = %lg", x1); break;
        case  2: printf("������� 2 ����� x1 = %lg  ������ ������ %lg", x1, x2); break;
        case  3: printf("� ������� ��������� ���������� ����� ������");break;
        default: printf("�� �������");

    }
    return 0;
}
int greh(double a, double b)
{
    const double eps = 0.0000000001;
    (fabs(a-b)<eps) ? 1: 0;
}


int isnull(double *x1, double *x2)
{
    (*x1 == 0) ? *x1 = 0: *x1 = * x1;
    (*x2 == 0) ? *x2 = 0: *x2 = *x2;
    return 0;
}
int square(double a, double b, double c,
           double *x1, double *x2)
{
    float d = -1; /*������������ �������� �������������*/
    if (greh(a, 0))
    {
        if (greh(b, 0))
        {
            if (greh(c, 0))
            {
                return 3; /*��������� ����� ������*/
            }
            else
            {
                return -1; /*������ ���, ������ ��� ��������� �� ������� �� x*/
            }
        }
        else
        {
            assert(x1 != nullptr);
            *x1 = -c/b; /*�������� ���������*/
            return 1;
        }
    }
    else
    {
        d = b * b - 4 * a * c;
        if (d < 0)
        {
            return 0;  /*�������������� ������ ���*/
        }
        else if (d == 0)
        {
            *x1 = -b / (2 * a); /*�������������� ������ ���*/
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
