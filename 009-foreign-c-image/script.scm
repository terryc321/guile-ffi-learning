
(load "type.scm")

(use-modules ((mine image) #:prefix image:))


(define img-1 (image:make-image "bob" 10 10))
(format #t "image created ~a ~%" img-1)

(image:clear-image img-1)
(format #t "image cleared ~a ~%" img-1)




