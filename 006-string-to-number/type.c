
/*
guile integer foreign function interface

*/


#include <math.h>
#include <libguile.h>

SCM my_c_one_wrapper (SCM str, SCM radix) // str -> number
{
  SCM z = scm_string_to_number(str,radix);
  return z;  
}

SCM my_c_two_wrapper (SCM num, SCM radix) // number -> string
{
  SCM z = scm_number_to_string(num,radix);
  return z;  
}

void init_math_string_conversion (void)
{
  // scm_c_define_gsubr (const char *name, int req, int opt, int rst, fcn)
  
  // my-c-one : 1 required arg (string) , 1 optional arg (radix)
  scm_c_define_gsubr ("my-c-one", 1, 1, 0, my_c_one_wrapper);
  
  // my-c-two : 1 required arg (string) , 1 optional arg (radix)
  scm_c_define_gsubr ("my-c-two", 1, 1, 0, my_c_two_wrapper);  
}

