#ifndef SOLVER
#define SOLVER
#include <TXLib.h>
#include <math.h>
#include "Solver.h" 
nRoots square_solver(coefficients coefs, 
    double* x1, double* x2)
{
    double diskr = -1;
    diskr = coefs.b * coefs.b - 4 * coefs.a * coefs.c;
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

nRoots solver(coefficients coefs, double *x1, double *x2)
{
    nRoots roots = none;

    if (double_compare(coefs.a, 0))
    {
        roots = linear_solver(coefs, x1, x2);
    }
    else
    {
        roots = square_solver(coefs, x1, x2);
    }
    if (*x1>*x2)
    {
        root_sort(x1, x2);
    }
    return roots;
}
#endif