/*!
    \file
    \brief Header for Input and Output
*/
#ifndef IN_OUT
#define IN_OUT
#include "Structures.h"
//--------------------------------------------------------------------------------------
//! Accepts the structure and writes the entered coefficients into it.
//! @param [in] coefficients* coef  
//--------------------------------------------------------------------------------------
void input_coef(coefficients* coef);

//------------------------------------------------------------------
//! //! Outputs a value depending on the number of roots of the equation and their values.
//! @param [in] nRoots* roots
//! @param [in] double x1 
//! @param [in] double x2
//----------------------- -----------------------------------------
void output_solution(nRoots* roots, double x1, double x2);
#endif