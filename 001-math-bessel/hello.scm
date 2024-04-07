
#|

foreign function interface


|#

(use-modules ((system foreign-library) #:prefix foreign-library:))

;; we can load a foreign library - okay
;; but how do we use it ?
(define (test)
  (let ((lib (foreign-library:load-foreign-library "/usr/lib/x86_64-linux-gnu/libcairo.so.2")))
    (format #t "did we get a foregin library ? ~a ~%" (foreign-library:foreign-library? lib))
    lib))




