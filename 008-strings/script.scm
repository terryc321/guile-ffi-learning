
(load "type.scm")

(use-modules ((my-foreign-module string) #:prefix string:))

(format #t "welcome : ~a ~%" (string:hello))

(format #t "always true : ~a ~%" (string:always-true))
(format #t "always false : ~a ~%" (string:always-false))

