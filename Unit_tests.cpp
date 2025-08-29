#include <TXLib.h>
#include <assert.h>
#include <stdio.h>
#include "Unit_tests.h"
#include "Solver.h"
#include "Supportive_func.h"
#include "Structures.h"


int unit_test(double* x1, double* x2, const char test_file[])
{
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    test_coefficients tests[max_test_size] = {{}};
    int size_mas = max_test_size;
    int passed = 0;
    test_file_reader(tests, test_file);
    
    for (int i = 0; i < size_mas; i++)
    {
       passed += one_test(x1, x2, tests[i]);
    }
    printf("Passed tests:%d\n", passed);
    return passed;
}

int one_test(double* x1, double *x2, test_coefficients Ref)
{   
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    coefficients coef = {0, 0, 0};
    coef.a = Ref.a; coef.b = Ref.b; coef.c = Ref.c;
    nRoots root = solver(coef, x1, x2);
    nRoots rootref = Ref.roots;
    if (root != rootref)
    {
        printf ("Failed: solver(%lg, %lg, %lg) gives x1 = %lg, x2 = %lg, should be x1 = %lg, x2 = %lg\n", Ref.a, Ref.b, Ref.c, *x1, *x2, Ref.x1_ref, Ref.x2_ref);
        return 0;
    }
    else
    {
        if (root == zero_roots || root == inf_roots || root == none)
        {
            return 1;
        }

        else if ((root == one_root || root == two_roots) && ((double_compare(*x1, Ref.x1_ref) && double_compare(*x2, Ref.x2_ref))  || 
                 (double_compare(*x2, Ref.x1_ref) && double_compare(*x1, Ref.x2_ref))))
        {
            return 1;
        }

        else
        {
            printf ("Failed: solver(%lg, %lg, %lg) gives:\n  roots = %d, x1 = %lg, x2 = %lg \n should be:\n roots = %d x1 = %lg, x2 = %lg\n", Ref.a, Ref.b, Ref.c, root, *x1, *x2, rootref, Ref.x1_ref, Ref.x2_ref);
            return 0;
        }
    }
    return 0;
}

void test_file_reader(test_coefficients tests_coef[], char file_name[])
{   
    
    FILE * file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL)
    {
        printf("Something went wrong. No Such file in directory.");
    }
    else
    {   
        int i = 0;
        while(read_file(file_pointer, &tests_coef[i])){
            i++;
        }
    }
    fclose(file_pointer);
}

int read_file(FILE* fp, test_coefficients* Ref)
{
    if (fscanf(fp, "%lg %lg %lg %d %lg %lg", &(Ref->a), &(Ref->b), &(Ref->c), (int*)&(Ref->roots), &(Ref->x1_ref), &(Ref->x2_ref)) == 6)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}