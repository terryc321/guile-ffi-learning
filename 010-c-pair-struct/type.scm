
(use-modules (system foreign-library))

(define-module (my-module pair)
  #:export (make-pair
	    first-pair
	    second-pair
	    add-pair
	    ))

(load-extension "./libguile-type" "init_pair_routines")




