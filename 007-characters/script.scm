
(load "type.scm")

(use-modules ((my-foreign-module character) #:prefix char:))

char:to-upper

char:to-lower

(let* ((x #\a)
       (y (char:to-upper x)))
  (format #t "upper case ~a is ~a ~%" x y))

(let* ((x #\A)
       (y (char:to-lower x)))
  (format #t "lower case of ~a is ~a ~%" x y))


