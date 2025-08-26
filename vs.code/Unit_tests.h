#ifndef UNIT_TESTS
#define UNIT_TESTS
const int max_test_size = 300;


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

struct coefficients
{
    double a ;
    double b ;
    double c ;
};

test_coefficients tests[max_test_size] = {{}};

void test_file_reader(test_coefficients tests[]);

int read_file(_iobuf* fp, test_coefficients* Ref);

int one_test(double *x1, double *x2, test_coefficients Ref);

int unit_test(double* x1, double*x2);

nRoots square_solver(coefficients coef,  double *x1, double *x2);

nRoots linear_solver(coefficients coef, double *x1, double *x2);

nRoots solver(coefficients coef,  double *x1, double *x2);

int double_compare(double a, double b);
#endif