


(define-module (my-foreign-module character)
  #:export (to-upper
	    to-lower
	    ))

(load-extension "./libguile-type" "init_character_routines")



