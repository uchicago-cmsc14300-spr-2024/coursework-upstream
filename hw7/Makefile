.PHONY: clean

# test is for test_hw7.c
test: hw7.h hw7.c test_hw7.c
	clang -o test -Wall hw7.c test_hw7.c -lm -lcriterion

# test2 is for the as-yet-unpublished phase2 autograder
test2: hw7.h hw7.c test2_hw7.c
	clang -o test2 -Wall hw7.c test2_hw7.c -lm -lcriterion

clean:
	rm -rf phase1 test test2 a.out
