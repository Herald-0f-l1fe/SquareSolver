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

int root_is_zero(double *x1, double *x2);

int double_compare(double a, double b);

void root_sort(double* x1, double* x2);

nRoots square_solver(coefficients coef,  double *x1, double *x2);

nRoots linear_solver(coefficients coef, double *x1, double *x2);

nRoots solver(coefficients coef,  double *x1, double *x2);