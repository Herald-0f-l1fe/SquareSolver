#include <TXLib.h>
#include <stdio.h>
#include <cmath>
#include <cassert>
#include <float.h>
#include "Structures.h"
#include "Input_Output.h"
#include "Solver.h"
#include "Supportive_func.h"
#include "Unit_tests.h"

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