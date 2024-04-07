
/*
guile integer foreign function interface

https://www.gnu.org/software/guile/manual/html_node/Defining-Foreign-Object-Types.html

eight bit grayscale image data example
*/

#include <libguile.h>
#include <string.h>
#include <stdio.h>


struct image {
  int width, height;
  char *pixels;

  /* The name of this image */
  SCM name;

  /* A function to call when this image is
     modified, e.g., to update the screen,
     or SCM_BOOL_F if no action necessary */
  SCM update_func;
};


/* define image_type */
static SCM image_type;

/* tells scheme how image_type is constructed - like a record of the names of slots */
void init_image_type (void)
{
  SCM name, slots;
  scm_t_struct_finalize finalizer;

  name = scm_from_utf8_symbol ("image");
  slots = scm_list_1 (scm_from_utf8_symbol ("data"));
  finalizer = NULL;

  image_type = scm_make_foreign_object_type (name, slots, finalizer);
}


/* scheme routine to make an image - our own foreign data type */
SCM make_image (SCM name, SCM s_width, SCM s_height)
{
  struct image *image;
  int width = scm_to_int (s_width);
  int height = scm_to_int (s_height);

  /* Allocate the `struct image'.  Because we
     use scm_gc_malloc, this memory block will
     be automatically reclaimed when it becomes
     inaccessible, and its members will be traced
     by the garbage collector.  */
  image = (struct image *) scm_gc_malloc (sizeof (struct image), "image");
  printf("allocated space for image size of %ld bytes \n" ,sizeof (struct image));
  
  image->width = width;
  image->height = height;

  /* Allocating the pixels with
     scm_gc_malloc_pointerless means that the
     pixels data is collectable by GC, but
     that GC shouldn't spend time tracing its
     contents for nested pointers because there
     aren't any.  */
  image->pixels =  scm_gc_malloc_pointerless (width * height, "image pixels");

  image->name = name;
  image->update_func = SCM_BOOL_F; // update_func = scheme false

  /* Now wrap the struct image* in a new foreign
     object, and return that object.  */
  return scm_make_foreign_object_1 (image_type, image);
}



/* zero out the image memory */
SCM clear_image (SCM image_obj)
{
  int area;
  struct image *image;

  scm_assert_foreign_object_type (image_type, image_obj);

  image = scm_foreign_object_ref (image_obj, 0);
  area = image->width * image->height;
  memset (image->pixels, 0, area);

  /* Invoke the image's update function.  */
  if (scm_is_true (image->update_func))
    scm_call_0 (image->update_func);

  return SCM_UNSPECIFIED;
}




void init_image_routines (void)
{

  // try doing this first see if it works
  init_image_type();
  
  // scm_c_define_gsubr (const char *name, int req, int opt, int rst, fcn)
  scm_c_define_gsubr ("make-image", 3, 0, 0, make_image);
  scm_c_define_gsubr ("clear-image", 1, 0, 0, clear_image);
  
}


