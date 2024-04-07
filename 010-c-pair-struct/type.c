
/*
guile integer foreign function interface

pair of ints c struct example

*/

#include <libguile.h>
#include <string.h>
#include <stdio.h>

struct pair {
  int a;
  int b;
};

static SCM pair_type;

void init_pair_type (void)
{
  SCM name;
  SCM slots;
  scm_t_struct_finalize finalizer;
  name = scm_from_utf8_symbol ("pair");
  slots = scm_list_1 (scm_from_utf8_symbol ("data")); 
  finalizer = NULL; // not recommended to use finalizer at all ?
  pair_type = scm_make_foreign_object_type (name, slots, finalizer);
}

SCM make_pair(SCM x , SCM y){
  struct pair *pair;
  pair = (struct pair *) scm_gc_malloc (sizeof (struct pair), "pair"); 
  int a = scm_to_int (x);
  int b = scm_to_int (y);
  pair->a = a;
  pair->b = b;
  return scm_make_foreign_object_1 (pair_type, pair); 
}

SCM first_pair(SCM pair_obj){
  struct pair *pair;
  // deref 
  pair = scm_foreign_object_ref (pair_obj, 0);
  int x = pair->a;
  return scm_from_int(x);  
}

SCM second_pair(SCM pair_obj){
  struct pair *pair;
  // deref
  pair = scm_foreign_object_ref (pair_obj, 0);
  int x = pair->b;
  return scm_from_int(x);    
}

SCM add_pair(SCM pair_obj){
  struct pair *pair;
  // deref 
  pair = scm_foreign_object_ref (pair_obj, 0);
  int a = pair->a;
  int b = pair->b;
  return scm_from_int(a + b);    
}

void init_pair_routines (void)
{
  // maybe i needed to create pair type at runtime 
  init_pair_type();
    
  // scm_c_define_gsubr (const char *name, int req, int opt, int rst, fcn)
  scm_c_define_gsubr ("make-pair", 2, 0, 0, make_pair);
  scm_c_define_gsubr ("first-pair", 1, 0, 0, first_pair);
  scm_c_define_gsubr ("second-pair", 1, 0, 0, second_pair);
  scm_c_define_gsubr ("add-pair", 1, 0, 0, add_pair);  
  
}



