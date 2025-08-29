/*!
    \file
    \brief Header for Unit tests
*/

#ifndef UNIT_TESTS
#define UNIT_TESTS
#include <stdio.h>
#include "Structures.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//! This function reads a file with tests.
//! @param [in] test_coefficients tests[] (array of structures into which data for tests will be entered.)
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
void test_file_reader(test_coefficients tests[], char file_name[]);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//! This function reads a string and writes the data to a structure for testing.
//! @param [in] _iobuf* fp (Pointer to a location in a file)
//! @param [in] test_coefficients* Ref (The structure into which the read test data is written.)
//! @param [out] test_coefficients Ref (Structure filled with data for the test)             
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int read_file(FILE* fp, test_coefficients* Ref);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//! This function performs one test and returns if something goes wrong.
//! @param [in] double *x1 (Point to the first root of the equation to change it.)
//! @param [in] double* x2 (Point to the second root of the equation to change it.)
//! @param [in] test_coefficients Ref (Structure filled with reference values.)
//! @return Conditions under which the program behaves incorrectly.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int one_test(double *x1, double *x2, test_coefficients Ref);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Function that checks all tests.
//! @param [in] double *x1 (Point to the first root of the equation to change it.)
//! @param [in] double* x2 (Point to the second root of the equation to change it.)
//! @return Number of passed tests.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int unit_test(double* x1, double*x2, const char test_file[]);

#endif