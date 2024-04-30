.PHONY: clean

seq: lab7.h lab7.c grayseq.c
	clang -Wall -o grayseq lab7.c grayseq.c -pthread

par: lab7.h lab7.c graypar.c
	clang -Wall -o graypar lab7.c graypar.c -pthread

clean:
	rm -rf a.out grayseq graypar

