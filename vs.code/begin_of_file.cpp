#include "Begin_of_file.h"
#include "Unit_tests.h"


void begin_of_file(int argc, char* argv[], double* x1, double *x2)
{
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
            unit_test(x1, x2, file_n); 
            i++;
        }
        else if (strcmp(argv[i], "-test") == 0)
        {
            char* file_n = "quare_tests.txt";
            unit_test(x1, x2, file_n);
        }
        else if (strcmp(argv[i], "-start") == 0)
        {
            break;
        }
        else 
        {
            printf("I don't know the meaning of this flag.");
        }
    }
}
