.PHONY: clean

# phase1 is the autograder that will run on submission
# it checks presence of functions, not correctness
phase1: hw5.h hw5.c phase1.c
	clang -o phase1 -Wall hw5.c phase1.c -lm -lcriterion

# test is for the tests you write in test_hw5.c
test: hw5.h hw5.c test_hw5.c
	clang -o test -Wall hw5.c test_hw5.c -lm -lcriterion

# test2 is for the as-yet-unpublished phase2 autograder
test2: hw5.h hw5.c test2_hw5.c
	clang -o test2 -Wall hw5.c test2_hw5.c -lm -lcriterion

clean:
	rm -rf phase1 test test2 a.out
