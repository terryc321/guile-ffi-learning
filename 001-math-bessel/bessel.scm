
#|

once figured out foreign function interface
loaded library
created stub c code to call actual j0 bessel function and convert back and forth to scheme code
we should load this
and j0 should be available to test
in guile

guile module defines module
|#

(define-module (math bessel)
  #:export (j0))

;; problem here is that guile will never find the shared library created by running build.sh
;;(load-extension "libguile-bessel" "init_math_bessel")
(load-extension "./libguile-bessel" "init_math_bessel")

;; can load this file
;;
;; > (use-modules (math bessel))
;; > (j0 3)
;; $1 = -0.2600519549019335


