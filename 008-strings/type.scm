


(define-module (my-foreign-module string)
  #:export (hello
	    always-true
	    always-false
	    ))

(load-extension "./libguile-type" "init_string_routines")



