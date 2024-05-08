.PHONY: clean

test: hw6.h hw6.c test_hw6.c
	clang -o test -Wall hw6.c test_hw6.c -lm -lcriterion

# test2 is for the as-yet-unpublished phase2 autograder
test2: hw6.h hw6.c test2_hw6.c
	clang -o test2 -Wall hw6.c test2_hw6.c -lm -lcriterion

clean:
	rm -rf phase1 test test2 a.out
