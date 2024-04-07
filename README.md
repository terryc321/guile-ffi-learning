
# Foreign function interface - learning guile 3.0 ffi 

test6

seems like guile 3.0.9 documentation needs a pull request 

[Good Code - section 5.3.1 A Sample Guile Extension ](https://www.gnu.org/software/guile/manual/html_node/A-Sample-Guile-Extension.html)

[Bad Code - section 6.19.2 Foreign Extensions](https://www.gnu.org/software/guile/manual/html_node/Foreign-Extensions.html)

### 001 - math bessel

to be able to call bessel j0 procedure from guile scheme

bit of a walk around park of foreign function interfacing to get this all to work

a )  need to generate the shared library libguile-bessel.so
b )  write a guile module exports j0
c )  start guile , load bessel.scm
d )  (use-modules (math bessel))
e )  finally call j0
     	 
(j0 3) =>  -0.2600519549019335

for what its worth , i have no idea what the bessel function does.

[primitive procedures] (https://www.gnu.org/software/guile/manual/html_node/Primitive-Procedures.html)

bessel.c calls this on init_math_bessel c code 
 scm_c_define_gsubr ("j0", 1, 0, 0, j0_wrapper);

scm_c_define_gsubr can be used to register c code to be used from scheme.

BUT only if the procedure j0_wrapper takes scheme values SCM(s) and returns scheme values SCM(s) .

This means anything call from scheme needs to be wrapped up in a slice of C code to do these conversions.

At heart of foreign function interface is understanding how to convert c code to scheme compatible code
and visa versa.

## 002  - simple boolean procedure

[Boolean datatype](https://www.gnu.org/software/guile/manual/html_node/Booleans.html)

scm_from_double  c code -> scheme 
scm_to_double  scheme -> c code

in c booleans are just small ints , common 0 means false. 
Anything else means true.

[Integers , Char , Big Nums](https://www.gnu.org/software/guile/manual/html_node/Integers.html)

In general conversion from c to scheme / scheme to c basic types is simply a matter of choosing given
routine from libguile

scm_from_<some-c-type>  c code -> scheme 
scm_to_<some-c-type>    scheme -> c code

Foreign function interface really concerned with c structures , c unions and c pointers .

definitely a big step forward , if we can get a handle on understanding this topic.

## 009 - foreign c image structure 

c image type with width , height and pointer to byte array

challenge is to get guile scheme to somehow load the shared library and use the library to do something.

load_extension loads foreign library and then looks for a thunk procedure no args to run first

missing was call to init_image_type

without this foreign type being declared , guile scheme simply segfaults without explanation.

# 010 - a simple pair structure of two integers

```c
struct pair {
 int a;
 int b;
 }
```


 





