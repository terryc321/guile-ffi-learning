
/*
guile integer foreign function interface

*/


#include <math.h>
#include <libguile.h>

SCM my_c_one_wrapper (SCM x, SCM y) // x <= y
{
  SCM z = scm_leq_p(x,y);
  return z;  
}

SCM my_c_two_wrapper (SCM x, SCM y) // x >= y
{
  SCM z = scm_geq_p(x,y); 
  return z;  
}

SCM my_c_three_wrapper (SCM x, SCM y) // x = y
{
  SCM z = scm_eq_p(x,y); 
  return z;  
}

SCM my_c_four_wrapper (SCM x, SCM y) // x < y
{
  SCM z = scm_less_p(x,y); 
  return z;  
}

SCM my_c_five_wrapper (SCM x, SCM y) // x > y
{
  // no scm_more_p so we compute
  // logical not ( is less or equal to ) instead.
  // logical equivalent to more than
  // use boolean NOT operation , 
  SCM z = scm_not( scm_leq_p(x,y)) ; 
  return z;  
}



void init_math_mycompares (void)
{
  scm_c_define_gsubr ("my-c-one", 2, 0, 0, my_c_one_wrapper);  
  scm_c_define_gsubr ("my-c-two", 2, 0, 0, my_c_two_wrapper); 
  scm_c_define_gsubr ("my-c-three", 2, 0, 0, my_c_three_wrapper);
  scm_c_define_gsubr ("my-c-four", 2, 0, 0, my_c_four_wrapper); 
  scm_c_define_gsubr ("my-c-five", 2, 0, 0, my_c_five_wrapper);
}

