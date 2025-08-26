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


enum nRoots square_solver(double a, double b, double c,
           double *x1, double *x2);

enum nRoots line_solver(double b, double c, double *x1, double *x2);

enum nRoots solver(double a, double b, double c,
           double *x1, double *x2);

int root_is_zero(double *x1, double *x2);


int double_compare(double a, double b);


void inpuut(double* a, double *b, double *c);


void outpuut(enum nRoots* roots, double* x1, double* x2);

int main()
{
    printf("Enter the coefficients of the equations a, b, c\n");

    nRoots roots = none;
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

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
    double diskr = -1; /*РЈСЃС‚Р°РЅР°РІР»РёРІР°СЋ Р·РЅР°С‡РµРЅРёРµ РґРёСЃРєСЂРёРјРёРЅР°РЅС‚Р°*/
    diskr = b * b - 4 * a * c;
    if (diskr < 0)
    {
        return zero_roots;  /*Р”РµР№СЃС‚РІРёС‚РµР»СЊРЅС‹С… РєРѕСЂРЅРµР№ РЅРµС‚*/
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
                return inf_roots; /*Р‘РµСЃРєРѕРЅРµРЅРѕ РјРЅРѕРіРѕ РєРѕСЂРЅРµР№*/
            }
            else
            {
                return zero_roots; /*РљРѕСЂРЅРµР№ РЅРµС‚, РїРѕС‚РѕРјСѓ С‡С‚Рѕ РІС‹СЂР°Р¶РµРЅРёРµ РЅРµ Р·Р°РІРёСЃРёС‚ РѕС‚ x*/
            }
        }
        else
        {
            assert(x1 != NULL);
            *x1 = -c/b; /*Р›РёРЅРµР№РЅРѕРµ СѓСЂР°РІРЅРµРЅРёРµ*/
            root_is_zero(x1, x2);
            return one_root;
        }
}

void inpuut(double* a, double *b, double *c)
{
    while(scanf("%lg %lg %lg", a, b, c)!=3)  //РЎРѕР·РґР°С‚СЊ РѕС‚РґРµР»СЊРЅСѓСЋ С„СѓРЅРєС†РёСЋ РґР»СЏ РІРІРѕРґР°.
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

int one_test(double a, double b, double c, double *x1, double *x2, enum nRoots roots, double x1ref, double x2ref, )
{;
    enum nRoots root = solver(a, b, c, &x1, &x2);
    if (root == roots && double_compare(*x1, x1ref) && double_compare(*x2, x2ref))

}
