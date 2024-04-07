
/*
guile integer foreign function interface

https://www.gnu.org/software/guile/manual/html_node/Defining-Foreign-Object-Types.html

eight bit grayscale image data example
*/

#include <libguile.h>
#include <string.h>
#include <stdio.h>


struct pair {
  int a;
  int b;
  //  SCM name;
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
  // scm_make_foreign_object_1 (pair_type, pair);  // ?? dont think we have slots 
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
  // deref header 
  pair = scm_foreign_object_ref (pair_obj, 0);
  int x = pair->b;
  return scm_from_int(x);    
}

SCM add_pair(SCM pair_obj){
  struct pair *pair;
  // deref header 
  pair = scm_foreign_object_ref (pair_obj, 0);
  int a = pair->a;
  int b = pair->b;
  return scm_from_int(a + b);    
}


/* // scheme routine to make an image - our own foreign data type  */
/* SCM make_image (SCM name, SCM s_width, SCM s_height) */
/* { */
/*   struct image *image; */
/*   int width = scm_to_int (s_width); */
/*   int height = scm_to_int (s_height); */

/*    /\* Allocate the `struct image'.  Because we *\/ */
/*    /\*   use scm_gc_malloc, this memory block will *\/ */
/*    /\*   be automatically reclaimed when it becomes *\/ */
/*    /\*   inaccessible, and its members will be traced *\/ */
/*    /\*   by the garbage collector.   *\/ */
/*   image = (struct image *) scm_gc_malloc (sizeof (struct image), "image"); */
/*   printf("allocated space for image size of %ld bytes \n" ,sizeof (struct image)); */
  
/*   image->width = width; */
/*   image->height = height; */

/*   /\* Allocating the pixels with */
/*      scm_gc_malloc_pointerless means that the */
/*      pixels data is collectable by GC, but */
/*      that GC shouldn't spend time tracing its */
/*      contents for nested pointers because there */
/*      aren't any.  *\/ */
/*   image->pixels =  scm_gc_malloc_pointerless (width * height, "image pixels"); */

/*   image->name = name; */
/*   image->update_func = SCM_BOOL_F; // update_func = scheme false */

/*   /\* Now wrap the struct image* in a new foreign */
/*      object, and return that object.  *\/ */
/*   return scm_make_foreign_object_1 (image_type, image); */
/* } */



/* /\* zero out the image memory *\/ */
/* SCM clear_image (SCM image_obj) */
/* { */
/*   int area; */
/*   struct image *image; */

/*   scm_assert_foreign_object_type (image_type, image_obj); */

/*   image = scm_foreign_object_ref (image_obj, 0); */
/*   area = image->width * image->height; */
/*   memset (image->pixels, 0, area); */

/*   /\* Invoke the image's update function.  *\/ */
/*   if (scm_is_true (image->update_func)) */
/*     scm_call_0 (image->update_func); */

/*   return SCM_UNSPECIFIED; */
/* } */



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



