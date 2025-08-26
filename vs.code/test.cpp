#include <TXLib.h>
#include <stdio.h>
#include <cmath>
#include <cassert>
#include <float.h>
#include "function_calls.h"

//-------------------------------------------------------------
//СЃРґРµР»Р°С‚СЊ С„Р°Р№Р»
//РїРѕРґРµР»РёС‚СЊ РЅР° С„Р°Р№Р»С‹
//

int main()
{   
    nRoots roots = none;
    double x1 = 0, x2 = 0;
    unit_test(&x1, &x2);

    coefficients coef = {0, 0, 0};

    input_coef(&coef);

    roots = solver(coef,  &x1, &x2);

    output_solution(&roots, x1, x2);

    return 0;
}


