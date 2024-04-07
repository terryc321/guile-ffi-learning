
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


void init_math_myints (void)
{
  //scm_c_define_gsubr ("my-c-one", 1, 0, 0, my_c_one_wrapper); // c unsigned 123 -> scheme int
  //scm_c_define_gsubr ("my-c-two", 1, 0, 0, my_c_two_wrapper); // c signed -123 -> scheme int
  scm_c_define_gsubr ("my-c-one", 0, 0, 0, my_c_one_wrapper); // c unsigned 123 -> scheme int
  scm_c_define_gsubr ("my-c-two", 0, 0, 0, my_c_two_wrapper); // c signed -123 -> scheme int
}

