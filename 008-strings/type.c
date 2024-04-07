
/*
guile integer foreign function interface

*/

#include <math.h>
#include <libguile.h>

SCM c_proc_1 () // string from constant null terminated string
{
  SCM z = scm_from_utf8_string("hello my friend\0");
  return z;  
}

SCM c_proc_2 (SCM c) // always true
{
  SCM z = SCM_BOOL_T; 
  return z;  
}

SCM c_proc_3 () // always false
{
  SCM z = SCM_BOOL_F; 
  return z;  
}


void init_string_routines (void)
{
  // scm_c_define_gsubr (const char *name, int req, int opt, int rst, fcn)
  scm_c_define_gsubr ("hello", 0, 0, 0, c_proc_1);

  // silly constant boolean procedures
  scm_c_define_gsubr ("always-true", 0, 0, 0, c_proc_2);
  scm_c_define_gsubr ("always-false", 0, 0, 0, c_proc_3);
 
  
}


