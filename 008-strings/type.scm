


(define-module (my-foreign-module image)
  #:export (make-image
	    clear-image
	    ))

(load-extension "./libguile-type" "init_image_routines")



