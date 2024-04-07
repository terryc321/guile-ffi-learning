
/*
extend guile with a bessel function

what does bessel compute anyway ? 
 */

#include <math.h>
#include <libguile.h>

SCM
j0_wrapper (SCM x)
{
  return scm_from_double (j0 (scm_to_double (x)));
}

void
init_math_bessel (void)
{
  scm_c_define_gsubr ("j0", 1, 0, 0, j0_wrapper);
}

