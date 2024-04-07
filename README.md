
# Foreign function interface - learning guile 3.0 ffi 

seems like guile 3.0.9 documentation needs a pull request 

[Good Code - section 5.3.1 A Sample Guile Extension ](https://www.gnu.org/software/guile/manual/html_node/A-Sample-Guile-Extension.html)

[Bad Code - section 6.19.2 Foreign Extensions] https://www.gnu.org/software/guile/manual/html_node/Foreign-Extensions.html

## 001 - math bessel

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

[Boolean datatype] (https://www.gnu.org/software/guile/manual/html_node/Booleans.html)


negation is a simple boolean procedure





to make a SCM value
scm_from_double  c code -> scheme 
scm_to_double  scheme -> c code

scm_c_define_gsubr
j0 is the name of procedure
1 means takes 1 argument
0 means no optional args
0 means no 


in c boolean is just 0 false and anything else positive or negative is true ?
if thats what want it to mean
0 or 1

