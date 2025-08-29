/*!
    \file
    \brief Begin_of_file
*/

#ifndef BEGIN_OF_FILE
#define BEGIN_OF_FILE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// @param [in] argc (The number of arguments passed to the command line.)
/// @param [in] argv (An array of strings that stores commands entered at the command line.)
/// @param [in] x1 (First root of the equation for tests.)
/// @param [in] x2 (Second root of the equation for tests.)
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void parse_command_line_args(int argc, char* argv[], double* x1, double* x2);

#endif