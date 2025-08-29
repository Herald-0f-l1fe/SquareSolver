#include <TXLib.h>
#include <stdio.h>
#include <cmath>
#include <cassert>
#include <float.h>
#include <unistd.h>
#include "Structures.h"
#include "Input_Output.h"
#include "Solver.h"
#include "Supportive_func.h"
#include "Unit_tests.h"
#include "Begin_of_file.h"
//doxygen begin
//
int main(int argc, char* argv[])
{    
    double x1 = 0, x2 = 0; 
    
    parse_command_line_args(argc, argv, &x1, &x2);
    nRoots roots = none;

    coefficients coef = {0, 0, 0};

    input_coef(&coef);

    roots = solver(coef,  &x1, &x2);

    output_solution(&roots, x1, x2);

    return 0;
}
