
/*
guile integer foreign function interface

*/


#include <math.h>
#include <libguile.h>

//SCM my_c_one_wrapper (SCM x)
SCM my_c_one_wrapper () // no args taken
{
  unsigned int val = 123;
  return scm_from_unsigned_integer (val);
}

//SCM my_c_two_wrapper (SCM x) 
SCM my_c_two_wrapper () // no args taken
{
  signed int val = -123;
  return scm_from_signed_integer (val);
}

SCM my_c_three_wrapper (SCM x)  // one scheme unsigned int
{
  // no type check ?
  unsigned int val = scm_to_uint(x);
  val = val + 123; // possible overflow ?
  return scm_from_unsigned_integer (val);
}

SCM my_c_four_wrapper (SCM x) // one scheme signed int 
{
  // no type check ? 64bit int
  signed int val = scm_to_int64(x);
  val = val - 123; // possible underflow ?
  return scm_from_signed_integer (val);
}


void init_math_myints (void)
{
  scm_c_define_gsubr ("my-c-one", 0, 0, 0, my_c_one_wrapper); // c unsigned 123 -> scheme int
  scm_c_define_gsubr ("my-c-two", 0, 0, 0, my_c_two_wrapper); // c signed -123 -> scheme int

  scm_c_define_gsubr ("my-c-three", 1, 0, 0, my_c_three_wrapper); // add 123 to scheme unsigned int
  scm_c_define_gsubr ("my-c-four", 1, 0, 0, my_c_four_wrapper); // add -123 to scheme signed int

}

