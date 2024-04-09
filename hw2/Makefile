.PHONY: clean

test: hw2.h hw2.c test_hw2.c
	clang -Wall -o test hw2.c test_hw2.c -lm -lcriterion

test2: hw2.h hw2.c test2_hw2.c
	clang -Wall -o test2 hw2.c test2_hw2.c -lm -lcriterion

clean:
	rm -rf a.out test test2

