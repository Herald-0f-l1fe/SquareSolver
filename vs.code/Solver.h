/*!
    \file
    \brief Header for Solver
*/

#ifndef SOLVER_H
#define SOLVER_H
#include "Structures.h"
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//! A function that solves an equation if it is quadratic.
//! @param [in] coef (Structure containing coefficients of equations)
//! @param [in] &x1 (Pointer to the first root)
//! @param [in] &x2 (Pointer to the second root)
//! @return nRoot number_of_roots (Namber of roots)
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
nRoots square_solver(coefficients coef,  double *x1, double *x2);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//! A function that solves an equation if it is linear.
//! @param [in] coef (Structure containing coefficients of equations)
//! @param [in] &x1 (Pointer to the first root)
//! @param [in] &x2 (Pointer to the second root)
//! @return nRoot number_of_roots (Namber of roots)
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

nRoots linear_solver(coefficients coef, double *x1, double *x2);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//! A function that solves a quadratic equation.
//! @param [in] coef (Structure containing coefficients of equations)
//! @param [in] &x1 (Pointer to the first root)
//! @param [in] &x2 (Pointer to the second root)
//! @return nRoot number_of_roots (Namber of roots)
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
nRoots solver(coefficients coef,  double *x1, double *x2);
#endif