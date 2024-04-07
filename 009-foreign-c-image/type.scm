
(use-modules (system foreign-library))

(define-module (mine image)
  #:export (make-image
	    clear-image
	    ))

(load-extension "./libguile-type" "init_image_routines")




