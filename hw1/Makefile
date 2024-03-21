.PHONY: clean

test: hw1.h hw1.c test_hw1.c
	clang -Wall -o test hw1.c test_hw1.c -lcriterion -lm

clean:
	rm -rf test
