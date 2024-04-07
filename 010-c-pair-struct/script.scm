
(load "type.scm")

(use-modules ((my-module pair) #:prefix pair:))

(define p1 (pair:make-pair 2 3))
(format #t "made a pair ~a ~%" p1)

(define p1-a (pair:first-pair p1))
(format #t "first of pair p1 is ~a ~%" p1-a)

(define p1-b (pair:second-pair p1))
(format #t "second of pair p1 is ~a ~%" p1-b)

(define p1-sum (pair:add-pair p1))
(format #t "sum of first + second of pair p1 is ~a ~%" p1-sum)

(define one-million 1000000)

(define store '())

(define (force-space-leak n)
  (let ((p1 (pair:make-pair (random 10) (random 10))))
    (cond
     ((zero? (modulo n (* one-million one-million)))
      (format #t "[~a] pair ~a => ~a : ~a : ++ ~a  ~%"
	      n
	      p1
	      (pair:first-pair p1)
	      (pair:second-pair p1)
	      (pair:add-pair p1))))
    (set! store (cons p1 store))
    (force-space-leak (+ n 1))))


(define (test n)
  (let ((p1 (pair:make-pair (random 10) (random 10))))
    (cond
     ((zero? (modulo n 100))
      (format #t "[~a] pair ~a => ~a : ~a : ++ ~a  ~%"
	      n
	      p1
	      (pair:first-pair p1)
	      (pair:second-pair p1)
	      (pair:add-pair p1))))
    (test (+ n 1))))

#|

> (test 0)

htop reports stable 1.8 percent memory consumption .

;; compare to behaviour with a definite space leak
> (force-space-leak 0)

force-space-leak causes memory exhaustion in a minute or two .

|#



