.PHONY: clean

# phase1 is the autograder that will run on submission
# it checks presence of functions, not correctness
phase1: hw4.h hw4.c phase1.c
	clang -o phase1 -Wall hw4.c phase1.c -lm -lcriterion

# test is for the tests you write in test_hw4.c
test: hw4.h hw4.c test_hw4.c
	clang -o test -Wall hw4.c test_hw4.c -lm -lcriterion

# test2 is for the as-yet-unpublished phase 2 autograder
test2: hw4.h hw4.c test2_hw4.c
	clang -o test2 -Wall hw4.c test2_hw4.c -lm -lcriterion

clean:
	rm -rf phase1 test test2 a.out
