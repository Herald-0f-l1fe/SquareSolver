#ifndef CALLS
#define CALLS
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

struct roots
{
    double x1 = 0;
    double x2 = 0;
};


nRoots square_solver(coefficients coef,  double *x1, double *x2);

nRoots linear_solver(coefficients coef, double *x1, double *x2);

nRoots solver(coefficients coef,  double *x1, double *x2);

int root_is_zero(double *x1, double *x2);

int double_compare(double a, double b);


void input_coef(coefficients* coef);

void buffer_cleaner();

void output_solution(nRoots* roots, double x1, double x2);

int unit_test(double* x1, double*x2);

int one_test(double *x1, double *x2, test_coefficients Ref);

void root_sort(double* x1, double* x2);


#endif
