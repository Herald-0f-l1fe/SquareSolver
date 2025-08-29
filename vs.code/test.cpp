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
//РѕР±СЂР°Р±РѕС‚РєР° arg_c arg_v С‡РµСЂРµР· С„Р»Р°РіРё -s, -f, -h, -t. 
int main(int argc, char* argv[])
{    
    double x1 = 0, x2 = 0; 
    begin_of_file(argc, argv, &x1, &x2);
    /*
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-help") == 0)
        {
            printf("If you want to run the program, type: -s\n");
            printf("If you want to test the program on data from a file, enter: -f \"filename\" \n");
        }
        else if (strcmp(argv[i], "-file") == 0)
        {
            char* file_n = argv[i+1];
            unit_test(&x1, &x2, file_n); 
            i++;
        }
        else if (strcmp(argv[i], "-test") == 0)
        {
            char* file_n = "quare_tests.txt";
            unit_test(&x1, &x2, file_n);
        }
        else if (strcmp(argv[i], "-start") == 0)
        {
            break;
        }
        else 
        {
            printf("I don't know the meaning of this flag.");
        }
    }*/
    /*while ((rez = getopt(argc, argv, "hsf:")) != -1)
    {
        switch (rez)
        {
            case 'h':
                printf("If you want to run the program, type: -s\n");
                printf("If you want to test the program on data from a file, enter: -f \"filename\" \n");
                break;
            case 's':
                printf("The program has started.");
                break;
            case 'f':
            {
                char* file_n = optarg;
                unit_test(&x1, &x2, file_n);
            }
                optind++;
                break;
            default:
                printf("I don't know the meaning of this flag.");
                break;
        }
    }*/ 
    nRoots roots = none;

    coefficients coef = {0, 0, 0};

    input_coef(&coef);

    roots = solver(coef,  &x1, &x2);

    output_solution(&roots, x1, x2);

    return 0;
}
