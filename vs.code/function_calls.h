#ifndef CALLS
#define CALLS

enum nRoots
{
    zero_roots,
      one_root,
     two_roots,
     inf_roots,
          none
};

struct test_coefficients
{
    double a;
    double b;
    double c;
    nRoots roots;
    double x1_ref;
    double x2_ref;
};

test_coefficients tests[] =
{
    {0,  0,  0,  inf_roots, NAN, NAN},
    {1,  2,  1,   one_root,  -1,  -1},
    {1,  3,  2,  two_roots,  -2,  -1},
    {0,  1,  1,   one_root,  -1,  -1},
    {1,  0, -4,  two_roots,  -2,   2},
    {1,  5,  0,  two_roots,  -5,   0},
    {1,  5,  6,  two_roots,  -3,  -2},
    {1,  -5, 6,  two_roots,   2,   3},
    {0,  0,  5, zero_roots, NAN, NAN},
    {5,  0,  0,   one_root,   0,   0},
    {0,  5,  0,   one_root,   0,   0}
};

struct parametrs
{
    double a;
    double b;
    double c;
};



nRoots square_solver(double a, double b, double c,
           double x1, double x2);

nRoots linear_solver(double b, double c,
            double x1, double x2);

nRoots solver(double a, double b, double c,
           double x1, double x2);

int root_is_zero(double x1, double x2);

int double_compare(double a, double b);

void input_coef(double a, double b, double c);

void buffer_cleaner();

int unit_test(double x1, doublex2);

int one_test(double x1, double x2, test_coefficients Ref);

void output_solution(nRoots roots, double x1, double x2);
#endif
