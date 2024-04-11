.PHONY: clean

test: hw3.h hw3.c test_hw3.c
	clang -o test -Wall hw3.c test_hw3.c -lm -lcriterion

test2: hw3.h hw3.c test2_hw3.c
	clang -o test2 -Wall hw3.c test2_hw3.c -lm -lcriterion

clean:
	rm -rf test test2 a.out
