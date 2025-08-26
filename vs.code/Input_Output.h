enum nRoots
{
    zero_roots,
      one_root,
     two_roots,
     inf_roots,
          none
};
struct coefficients
{
    double a ;
    double b ;
    double c ;
};

void input_coef(coefficients* coef);

void buffer_cleaner();

void output_solution(nRoots* roots, double x1, double x2);