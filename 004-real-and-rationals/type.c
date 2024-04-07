
/*
guile integer foreign function interface

*/


#include <math.h>
#include <libguile.h>

SCM my_c_one_wrapper (SCM x) // one floating point
{
  // no type check ?
  double val = scm_to_double(x);
  val = val + val; // overflow underflow?
  return scm_from_double (val);
}

SCM my_c_two_wrapper (SCM x) // one rational arg -- ie fraction
{
  SCM y = scm_numerator(x); // get numerator
  return y;
}


SCM my_c_three_wrapper (SCM x)  // one rational arg -- ie fraction
{
  SCM y = scm_denominator(x); // get denominator
  return y;
}

/*
SCM my_c_four_wrapper (SCM x) // one scheme signed int 
{
  // no type check ? 64bit int
  signed int val = scm_to_int64(x);
  val = val - 123; // possible underflow ?
  return scm_from_signed_integer (val);
}
*/

void init_math_myreals (void)
{
  scm_c_define_gsubr ("my-c-one", 1, 0, 0, my_c_one_wrapper); 
  scm_c_define_gsubr ("my-c-two", 1, 0, 0, my_c_two_wrapper); 
  scm_c_define_gsubr ("my-c-three", 1, 0, 0, my_c_three_wrapper); 
  
  //scm_c_define_gsubr ("my-c-four", 1, 0, 0, my_c_four_wrapper); // add -123 to scheme signed int

}

