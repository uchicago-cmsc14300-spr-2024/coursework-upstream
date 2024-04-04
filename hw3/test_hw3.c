#include <stdio.h>
#include <criterion/criterion.h>
#include <math.h>
#include "hw3.h"

// ======== constants

const double TOL = 0.001;
// TOL for "tolerance"

// ======== helper functions

int within(double epsilon, double a, double b)
{
  return fabs(a-b)<=epsilon;
}

int int_arr_eq(int *a, int *b, int len)
{
  for (int i=0; i<len; i++)
    if (a[i]!=b[i])
      return 0;
  return 1;
}

int idate_arr_eq(idate *a, idate *b, int len)
{
  for (int i=0; i<len; i++)
    if (a[i]!=b[i])
      return 0;
  return 1;
}

// ======== tests

// -------- reverse

Test(hw3_reverse, reverse00)
{
  int a[] = {1,2,3};
  reverse(a,3);
  int z[] = {3,2,1};
  cr_assert(int_arr_eq(a,z,3));
}

// -------- sift_up

Test(hw3_sift_up, sift_up00)
{
  int a[] = {3,2,1};
  sift_up(a,2);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

// -------- sift_down

Test(hw3_sift_down, sift_down00)
{
  int a[] = {3,2,1};
  sift_down(a,0,3);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

// -------- heapsort143

Test(hw3_heapsort, heapsort00)
{
  int a[] = {1,9,8,2,3};
  heapsort143(a,5);
  int z[] = {1,2,3,8,9};
  cr_assert(int_arr_eq(a,z,5));
}

// -------- median

Test(hw3_median, median00)
{
  int a[] = {1,3,7,9,5};
  cr_assert(within(TOL,median(a,5),5));
}

// -------- mode

Test(hw3_mode, mode00)
{
  int a[] = {1,3,7,9,7};
  cr_assert(mode(a,5)==7);
}

// -------- days_between_incl

Test(hw3_tween, days_between_incl00)
{
  cr_assert(days_between_incl(20240331,20240402)==3);
}

// -------- max_date

Test(hw3_max_date, max_date00)
{
  idate a[] = {20240101, 20241231, 20240715};
  cr_assert(max_date(a,3)==20241231);
}

// -------- min_date

Test(hw3_min_date, min_date00)
{
  idate a[] = {20240101, 20241231, 20240715};
  cr_assert(min_date(a,3)==20240101);
}

// -------- day_span

Test(hw3_day_span, day_span00)
{
  idate a[] = {20240101, 20240120, 20240112};
  cr_assert(day_span(a,3)==20);
}

// -------- all_dates
Test(hw3_all_dates, all_dates00)
{
  idate *a = all_dates(20240101,20240104);
  idate b[] = {20240101, 20240102, 20240103, 20240104};
  cr_assert(idate_arr_eq(a,b,4));
}

// -------- mean_red

Test(hw3_mean_red, mean_red00)
{
  prgb a[] = {0X01000000, 0X03000000};
  cr_assert(mean_red(a,2)==2);
}

// -------- connect_int_arrays

Test(hw3_connect, connect00)
{
  int a[] = {1,2};
  int b[] = {3,4,5};
  int *c = connect_int_arrays(a,2,b,3);
  int d[] = {1,2,3,4,5};
  cr_assert(int_arr_eq(c,d,5));  
}

// -------- truncate

Test(hw3_truncate, truncate00)
{
  double a[] = {1.1,2.9,3.6};
  int b[] = {1,2,3};
  int *c = truncate(a,3);
  cr_assert(int_arr_eq(b,c,3));
}

// -------- primes

Test(hw3_primes, primes00)
{
  int *p = primes(3);
  int a[] = {2,3,5};
  cr_assert(int_arr_eq(p,a,3));
}

// -------- nonprimes

Test(hw3_nonprimes, nonprimes00)
{
  int a[] = {10,11,2,3,4};
  int count=0;
  int *n = nonprimes(a,5,&count);
  int b[] = {10,4};
  cr_assert(count==2 && int_arr_eq(n,b,2));
}
