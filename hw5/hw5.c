#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hw5.h"

// ======== utilities ========

// some of these have mock implementations for phase1
// replace mock implementations with real ones

int_list *il_cons(int f, int_list *r);
void il_free(int_list *ns);
void il_show(int_list *ns);

char_list *cl_cons(char f, char_list *r);
void cl_free(char_list *cs);
void cl_show(char_list *cs);

str_list *sl_cons(char *f, str_list *r);
void sl_free(str_list *ss) {return; /* mock */}
void sl_show(str_list *ss);

point_list *pl_cons(point f, point_list *r) {return NULL; /* mock */}
void pl_free(point_list *ps) {return; /* mock */}
void pl_show(point_list *ps);

// ======== operations ========

char *concat(char *s1, char *s2)
{
  exit(1);
}

double integral(double(*f)(double), double a, double b, double dx)
{
  exit(1);
}

char_list *caps(char *s)
{
  exit(1);
}

char *bitstring(unsigned char b)
{
  exit(1);
}

double polygon_perim(point_list *polygon)
{
  exit(1);
}

lineq linreg(point_list *dataset)
{
  exit(1);
}

unsigned int total_length(str_list *strings)
{
  exit(1);
}

str_list *split(char sep, char *s)
{
  exit(1);
}

char *join(char j, str_list *strings)
{
  exit(1);
}

