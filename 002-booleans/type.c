
/*
extend guile with a bessel function

what does bessel compute anyway ? 
 */

#include <math.h>
#include <libguile.h>

SCM mynot_wrapper (SCM x)
{
  int val = scm_to_bool (x) ;
  if (val == 0){
    val = 1; // true
  }
  else {
    val = 0 ; // false
  }
  return scm_from_bool (val);
}


void init_math_mynot (void)
{
  scm_c_define_gsubr ("mynot", 1, 0, 0, mynot_wrapper);
}

