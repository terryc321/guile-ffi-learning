
/*
guile integer foreign function interface

ascii character in c is an int

utf-8 ? 

*/



#include <math.h>
#include <libguile.h>

SCM c_proc_1 (SCM c) // up case the letter
{
  SCM z = scm_char_upcase(c);
  return z;  
}

SCM c_proc_2 (SCM c) // lowercase the letter
{
  SCM z = scm_char_downcase(c); 
  return z;  
}

void init_character_routines (void)
{
  // scm_c_define_gsubr (const char *name, int req, int opt, int rst, fcn)
  
  // my-c-one : 1 required arg 
  scm_c_define_gsubr ("to-upper", 1, 0, 0, c_proc_1);
  
  // my-c-two : 1 required arg 
  scm_c_define_gsubr ("to-lower", 1, 0, 0, c_proc_2);
  
}


