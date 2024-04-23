#include <stdio.h>
#include <criterion/criterion.h>
#include <math.h>
#include "hw5.h"

// ======== tests

// -------- concat

Test(hw5_concat, concat00)
{
  concat("","");
  cr_assert(1);
}

// -------- integral

double identity(double x) {return x;}

Test(hw5_integral, integral00)
{
  integral(&identity,0,1,0.1);
  cr_assert(1);
}

// -------- caps

Test(hw5_caps, caps00)
{
  caps("");
  cr_assert(1);
}

// -------- bitstring

Test(hw5_bitstring, bistring00)
{
  bitstring(0);
  cr_assert(1);
}

// -------- polygon_perim

Test(hw5_polygon_perim, polygon_perim00)
{
  point p = {0,0};
  point_list *ps = pl_cons(p, pl_cons(p, pl_cons(p, NULL)));
  polygon_perim(ps);
  cr_assert(1);
}

// -------- linreg

Test(hw5_linreg, linreg00)
{
  point p = {0,0};
  point_list *ps = pl_cons(p, pl_cons(p, pl_cons(p, NULL)));
  linreg(ps);
  cr_assert(1);
  pl_free(ps);
}

// -------- total_length

Test(hw5_total_length, total_length00)
{
  total_length(NULL);
  cr_assert(1);
}

// -------- split

Test(hw5_split, split00)
{
  split('.',"");
  cr_assert(1);
}

// -------- join

Test(hw5_join, join00)
{
  join('.',NULL);
  cr_assert(1);
}

