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

Test(hw3_reverse, reverse01)
{
  int a[] = {1};
  reverse(a,1);
  int z[] = {1};
  cr_assert(int_arr_eq(a,z,1));
}

Test(hw3_reverse, reverse02)
{
  int a[] = {1,2};
  reverse(a,2);
  int z[] = {2,1};
  cr_assert(int_arr_eq(a,z,2));
}

Test(hw3_reverse, reverse03)
{
  int a[] = {1,2,3,4,5,6,7,8,9};
  reverse(a,9);
  int z[] = {9,8,7,6,5,4,3,2,1};
  cr_assert(int_arr_eq(a,z,9));
}

// -------- sift_up

Test(hw3_sift_up, sift_up00)
{
  int a[] = {3,2,1};
  sift_up(a,2);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_sift_up, sift_up01)
{
  int a[] = {1};
  sift_up(a,0);
  int z[] = {1};
  cr_assert(int_arr_eq(a,z,1));
}

Test(hw3_sift_up, sift_up02)
{
  int a[] = {1,2};
  sift_up(a,1);
  int z[] = {1,2};
  cr_assert(int_arr_eq(a,z,2));
}

Test(hw3_sift_up, sift_up03)
{
  int a[] = {2,1};
  sift_up(a,1);
  int z[] = {1,2};
  cr_assert(int_arr_eq(a,z,2));
}

Test(hw3_sift_up, sift_up04)
{
  int a[] = {2,1,3};
  sift_up(a,1);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_sift_up, sift_up05)
{
  int a[] = {2,3,4,0};
  sift_up(a,3);
  int z[] = {0,2,4,3};
  cr_assert(int_arr_eq(a,z,4));
}

Test(hw3_sift_up, sift_up06)
{
  int a[] = {1,3,4,2};
  sift_up(a,3);
  int z[] = {1,2,4,3};
  cr_assert(int_arr_eq(a,z,4));
}

Test(hw3_sift_up, sift_up07)
{
  int a[] = {1,3,4,5,6,0};
  sift_up(a,5);
  int z[] = {0,3,1,5,6,4};
  cr_assert(int_arr_eq(a,z,6));
}

// -------- sift_down

Test(hw3_sift_down, sift_down00)
{
  int a[] = {3,2,1};
  sift_down(a,0,3);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_sift_down, sift_down01)
{
  int a[] = {1};
  sift_down(a,0,1);
  int z[] = {1};
  cr_assert(int_arr_eq(a,z,1));
}

Test(hw3_sift_down, sift_down02)
{
  int a[] = {1,2};
  sift_down(a,0,2);
  int z[] = {1,2};
  cr_assert(int_arr_eq(a,z,2));
}

Test(hw3_sift_down, sift_down03)
{
  int a[] = {1,2,3};
  sift_down(a,0,3);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_sift_down, sift_down04)
{
  int a[] = {10,2,3};
  sift_down(a,0,3);
  int z[] = {2,10,3};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_sift_down, sift_down05)
{
  int a[] = {10,2,1};
  sift_down(a,0,3);
  int z[] = {1,2,10};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_sift_down, sift_down06)
{
  int a[] = {10,2,3,4};
  sift_down(a,0,4);
  int z[] = {2,4,3,10};
  cr_assert(int_arr_eq(a,z,4));
}

Test(hw3_sift_down, sift_down07)
{
  int a[] = {10,2,1,4};
  sift_down(a,0,4);
  int z[] = {1,2,10,4};
  cr_assert(int_arr_eq(a,z,4));
}

Test(hw3_sift_down, sift_down08)
{
  int a[] = {9,1,2,3,4,5,6};
  sift_down(a,0,7);
  int z[] = {1,3,2,9,4,5,6};
  cr_assert(int_arr_eq(a,z,7));
}

Test(hw3_sift_down, sift_down09)
{
  int a[] = {9,1,3,4,2,5,6};
  sift_down(a,0,7);
  int z[] = {1,2,3,4,9,5,6};
  cr_assert(int_arr_eq(a,z,7));
}

Test(hw3_sift_down, sift_down0A)
{
  int a[] = {9,3,1,4,5,6,7};
  sift_down(a,0,7);
  int z[] = {1,3,6,4,5,9,7};
  cr_assert(int_arr_eq(a,z,7));
}

Test(hw3_sift_down, sift_down0B)
{
  int a[] = {9,3,1,4,5,8,7};
  sift_down(a,0,7);
  int z[] = {1,3,7,4,5,8,9};
  cr_assert(int_arr_eq(a,z,7));
}

Test(hw3_sift_down, sift_down0C)
{
  int a[] = {9,3,1,10,11,12,13};
  sift_down(a,0,7);
  int z[] = {1,3,9,10,11,12,13};
  cr_assert(int_arr_eq(a,z,7));
}

Test(hw3_sift_down, sift_down0D)
{
  int a[] = {9,0,1,10,11,12,13};
  sift_down(a,0,7);
  int z[] = {0,9,1,10,11,12,13};
  cr_assert(int_arr_eq(a,z,7));
}

// -------- heapsort143

Test(hw3_heapsort, heapsort00)
{
  int a[] = {1,9,8,2,3};
  heapsort143(a,5);
  int z[] = {1,2,3,8,9};
  cr_assert(int_arr_eq(a,z,5));
}

Test(hw3_heapsort, heapsort01)
{
  int a[] = {1};
  heapsort143(a,1);
  int z[] = {1};
  cr_assert(int_arr_eq(a,z,1));
}

Test(hw3_heapsort, heapsort02)
{
  int a[] = {0,1};
  heapsort143(a,2);
  int z[] = {0,1};
  cr_assert(int_arr_eq(a,z,2));
}

Test(hw3_heapsort, heapsort03)
{
  int a[] = {2,1};
  heapsort143(a,2);
  int z[] = {1,2};
  cr_assert(int_arr_eq(a,z,2));
}

Test(hw3_heapsort, heapsort04)
{
  int a[] = {1,2,3};
  heapsort143(a,3);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_heapsort, heapsort05)
{
  int a[] = {1,3,2};
  heapsort143(a,3);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_heapsort, heapsort06)
{
  int a[] = {2,1,3};
  heapsort143(a,3);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_heapsort, heapsort07)
{
  int a[] = {2,3,1};
  heapsort143(a,3);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_heapsort, heapsort08)
{
  int a[] = {3,2,1};
  heapsort143(a,3);
  int z[] = {1,2,3};
  cr_assert(int_arr_eq(a,z,3));
}

Test(hw3_heapsort, heapsort09)
{
  int a[] = {1,10,2,20,3,30,4,40,5,50,6,60,7,70,8,80};
  heapsort143(a,16);
  int z[] = {1,2,3,4,5,6,7,8,10,20,30,40,50,60,70,80};
  cr_assert(int_arr_eq(a,z,16));
}

// -------- median

Test(hw3_median, median00)
{
  int a[] = {1,3,7,9,5};
  cr_assert(within(TOL,median(a,5),5));
}

Test(hw3_median, median01)
{
  int a[] = {1};
  cr_assert(within(TOL,median(a,1),1));
}

Test(hw3_median, median02)
{
  int a[] = {1,2};
  cr_assert(within(TOL,median(a,2),1.5));
}

Test(hw3_median, median03)
{
  int a[] = {2,1};
  cr_assert(within(TOL,median(a,2),1.5));
}

Test(hw3_median, median04)
{
  int a[] = {1,1,2};
  cr_assert(within(TOL,median(a,3),1));
}

Test(hw3_median, median05)
{
  int a[] = {1,2,1};
  cr_assert(within(TOL,median(a,3),1));
}

Test(hw3_median, median06)
{
  int a[] = {2,1,1};
  cr_assert(within(TOL,median(a,3),1));
}

Test(hw3_median, median07)
{
  int a[] = {2,1,1,1};
  cr_assert(within(TOL,median(a,4),1));
}

Test(hw3_median, median08)
{
  int a[] = {1,2,1,1};
  cr_assert(within(TOL,median(a,4),1));
}

Test(hw3_median, median09)
{
  int a[] = {1,1,2,1};
  cr_assert(within(TOL,median(a,4),1));
}

Test(hw3_median, median0A)
{
  int a[] = {1,1,1,2};
  cr_assert(within(TOL,median(a,4),1));
}

Test(hw3_median, median0B)
{
  int a[] = {1,0,0,0,0,0,2,2,2,2,2};
  cr_assert(within(TOL,median(a,11),1));
}

Test(hw3_median, median0C)
{
  int a[] = {0,0,0,0,0,1,2,2,2,2,2};
  cr_assert(within(TOL,median(a,11),1));
}

Test(hw3_median, median0D)
{
  int a[] = {0,0,0,0,0,2,2,2,2,2,1};
  cr_assert(within(TOL,median(a,11),1));
}

// -------- mode

Test(hw3_mode, mode00)
{
  int a[] = {1,3,7,9,7};
  cr_assert(mode(a,5)==7);
}

Test(hw3_mode, mode01)
{
  int a[] = {1};
  cr_assert(mode(a,1)==1);
}

Test(hw3_mode, mode02)
{
  int a[] = {1,2};
  int m = mode(a,2);
  cr_assert(m==1 || m==2);
}

Test(hw3_mode, mode03)
{
  int a[] = {2,1};
  int m = mode(a,2);
  cr_assert(m==1 || m==2);
}

Test(hw3_mode, mode04)
{
  int a[] = {1,1,2};
  int m = mode(a,3);
  cr_assert(m==1);
}

Test(hw3_mode, mode05)
{
  int a[] = {1,2,1};
  int m = mode(a,3);
  cr_assert(m==1);
}

Test(hw3_mode, mode06)
{
  int a[] = {2,1,1};
  int m = mode(a,3);
  cr_assert(m==1);
}

Test(hw3_mode, mode07)
{
  int a[] = {2,2,1,1};
  int m = mode(a,4);
  cr_assert(m==1 || m==2);
}

Test(hw3_mode, mode08)
{
  int a[] = {2,1,1,2};
  int m = mode(a,4);
  cr_assert(m==1 || m==2);
}

Test(hw3_mode, mode09)
{
  int a[] = {2,1,1,1};
  int m = mode(a,4);
  cr_assert(m==1);
}

Test(hw3_mode, mode0A)
{
  int a[] = {1,2,1,1};
  int m = mode(a,4);
  cr_assert(m==1);
}

Test(hw3_mode, mode0B)
{
  int a[] = {1,1,2,1};
  int m = mode(a,4);
  cr_assert(m==1);
}

Test(hw3_mode, mode0C)
{
  int a[] = {1,1,1,2};
  int m = mode(a,4);
  cr_assert(m==1);
}

Test(hw3_mode, mode0D)
{
  int a[] = {1,2,1,3,1,4,1,5,1,6,1,7,1,8,1,9};;
  int m = mode(a,16);
  cr_assert(m==1);
}

// -------- days_between_incl

Test(hw3_tween, days_between_incl00)
{
  cr_assert(days_between_incl(20240331,20240402)==3);
}

Test(hw3_tween, days_between_incl01)
{
  cr_assert(days_between_incl(20240301,20240331)==31);
}

Test(hw3_tween, days_between_incl02)
{
  cr_assert(days_between_incl(20240301,20240301)==1);
}

Test(hw3_tween, days_between_incl03)
{
  cr_assert(days_between_incl(20240301,20240302)==2);
}

Test(hw3_tween, days_between_incl04)
{
  cr_assert(days_between_incl(20240301,20240430)==61);
}

Test(hw3_tween, days_between_incl05)
{
  cr_assert(days_between_incl(20240101,20241231)==366);
}

Test(hw3_tween, days_between_incl06)
{
  cr_assert(days_between_incl(20230101,20231231)==365);
}

Test(hw3_tween, days_between_incl07)
{
  cr_assert(days_between_incl(20230101,20241231)==365+366);
}

Test(hw3_tween, days_between_incl08)
{
  cr_assert(days_between_incl(20230101,20251231)==2*365+366);
}

// -------- max_date

Test(hw3_max_date, max_date00)
{
  idate a[] = {20240101, 20241231, 20240715};
  cr_assert(max_date(a,3)==20241231);
}

Test(hw3_max_date, max_date01)
{
  idate a[] = {20240101};
  cr_assert(max_date(a,1)==20240101);
}

Test(hw3_max_date, max_date02)
{
  idate a[] = {20240101,20240101};
  cr_assert(max_date(a,2)==20240101);
}

Test(hw3_max_date, max_date03)
{
  idate a[] = {20240102,20240101};
  cr_assert(max_date(a,2)==20240102);
}

Test(hw3_max_date, max_date04)
{
  idate a[] = {20240102,20240103};
  cr_assert(max_date(a,2)==20240103);
}

Test(hw3_max_date, max_date05)
{
  idate a[] = {20241231,20250101};
  cr_assert(max_date(a,2)==20250101);
}

Test(hw3_max_date, max_date06)
{
  idate a[] = {20251231,20240101};
  cr_assert(max_date(a,2)==20251231);
}

Test(hw3_max_date, max_date07)
{
  idate a[] = {20240701,20240101,20240201,20240315};
  cr_assert(max_date(a,4)==20240701);
}

Test(hw3_max_date, max_date08)
{
  idate a[] = {20230701,20240101,20240201,20240315};
  cr_assert(max_date(a,4)==20240315);
}

Test(hw3_max_date, max_date09)
{
  idate a[] = {20230701,20240101,20250201,20240315};
  cr_assert(max_date(a,4)==20250201);
}

Test(hw3_max_date, max_date0A)
{
  idate a[] = {20230701,20260101,20250201,20240315};
  cr_assert(max_date(a,4)==20260101);
}

// -------- min_date

Test(hw3_min_date, min_date00)
{
  idate a[] = {20240101, 20241231, 20240715};
  cr_assert(min_date(a,3)==20240101);
}

Test(hw3_min_date, min_date01)
{
  idate a[] = {20240101};
  cr_assert(min_date(a,1)==20240101);
}

Test(hw3_min_date, min_date02)
{
  idate a[] = {20240101,20240101};
  cr_assert(min_date(a,2)==20240101);
}

Test(hw3_min_date, min_date03)
{
  idate a[] = {20240102,20240101};
  cr_assert(min_date(a,2)==20240101);
}

Test(hw3_min_date, min_date04)
{
  idate a[] = {20240102,20240103};
  cr_assert(min_date(a,2)==20240102);
}

Test(hw3_min_date, min_date05)
{
  idate a[] = {20241231,20250101};
  cr_assert(min_date(a,2)==20241231);
}

Test(hw3_min_date, min_date06)
{
  idate a[] = {20251231,20240101};
  cr_assert(min_date(a,2)==20240101);
}

Test(hw3_min_date, min_date07)
{
  idate a[] = {20240701,20240101,20240201,20240315};
  cr_assert(min_date(a,4)==20240101);
}

Test(hw3_min_date, min_date08)
{
  idate a[] = {20230701,20240101,20240201,20240315};
  cr_assert(min_date(a,4)==20230701);
}

Test(hw3_min_date, min_date09)
{
  idate a[] = {20230701,20240101,20250201,20240315};
  cr_assert(min_date(a,4)==20230701);
}

Test(hw3_min_date, min_date0A)
{
  idate a[] = {20230701,20260101,20250201,20240315};
  cr_assert(min_date(a,4)==20230701);
}

// -------- day_span

Test(hw3_day_span, day_span00)
{
  idate a[] = {20240101, 20240120, 20240112};
  cr_assert(day_span(a,3)==20);
}

Test(hw3_day_span, day_span01)
{
  idate a[] = {20231231, 20230101, 20230707};
  cr_assert(day_span(a,3)==365);
}

Test(hw3_day_span, day_span02)
{
  idate a[] = {20241231, 20240101, 20240707};
  cr_assert(day_span(a,3)==366);
}

Test(hw3_day_span, day_span03)
{
  idate a[] = {20230101, 20231231, 20230707};
  cr_assert(day_span(a,3)==365);
}

Test(hw3_day_span, day_span04)
{
  idate a[] = {20240101, 20241231, 20240707};
  cr_assert(day_span(a,3)==366);
}

Test(hw3_day_span, day_span05)
{
  idate a[] = {20240707,20240707,20240707,20240707};
  cr_assert(day_span(a,4)==1);
}

Test(hw3_day_span, day_span06)
{
  idate a[] = {20240707,20240707,20240708,20240707};
  cr_assert(day_span(a,4)==2);
}

Test(hw3_day_span, day_span07)
{
  idate a[] = {20231231,20240101};
  cr_assert(day_span(a,2)==2);
}

// -------- all_dates

Test(hw3_all_dates, all_dates00)
{
  idate *a = all_dates(20240101,20240104);
  idate b[] = {20240101, 20240102, 20240103, 20240104};
  cr_assert(idate_arr_eq(a,b,4));
}

Test(hw3_all_dates, all_dates01)
{
  idate *a = all_dates(20231230,20240103);
  idate b[] = {20231230, 20231231, 20240101, 20240102, 20240103};
  cr_assert(idate_arr_eq(a,b,5));
}

Test(hw3_all_dates, all_dates02)
{
  idate *a = all_dates(20230228,20230301);
  idate b[] = {20230228,20230301};
  cr_assert(idate_arr_eq(a,b,2));
}

Test(hw3_all_dates, all_dates03)
{
  idate *a = all_dates(20240228,20240301);
  idate b[] = {20240228,20240229,20240301};
  cr_assert(idate_arr_eq(a,b,3));
}

Test(hw3_all_dates, all_dates04)
{
  idate *a = all_dates(20240629,20240702);
  idate b[] = {20240629,20240630,20240701,20240702};
  cr_assert(idate_arr_eq(a,b,4));
}

Test(hw3_all_dates, all_dates05)
{
  idate *a = all_dates(20240629,20240629);
  idate b[] = {20240629};
  cr_assert(idate_arr_eq(a,b,1));
}

// -------- mean_red

Test(hw3_mean_red, mean_red00)
{
  prgb a[] = {0X01000000, 0X03000000};
  cr_assert(mean_red(a,2)==2);
}

Test(hw3_mean_red, mean_red01)
{
  prgb a[] = {0X01FF0000, 0X0300FF00};
  cr_assert(mean_red(a,2)==2);
}

Test(hw3_mean_red, mean_red02)
{
  prgb a[] = {0X01FF0000, 0X0300FF00, 0X02F0F000};
  cr_assert(mean_red(a,3)==2);
}

Test(hw3_mean_red, mean_red03)
{
  prgb a[] = {0XBFF0EE00, 0XBFABCA00, 0XBF008700, 0XBF987600};
  cr_assert(mean_red(a,4)==0XBF);
}

Test(hw3_mean_red, mean_red04)
{
  prgb a[] = {0XCD000000};
  cr_assert(mean_red(a,1)==0XCD);
}

Test(hw3_mean_red, mean_red05)
{
  prgb a[] = {0X01000000,0X02000000};
  cr_assert(mean_red(a,2)==1);
}

// -------- connect_int_arrays

Test(hw3_connect_int_arrays, connect_int_arrays00)
{
  int a[] = {1,2};
  int b[] = {3,4,5};
  int *c = connect_int_arrays(a,2,b,3);
  int d[] = {1,2,3,4,5};
  cr_assert(int_arr_eq(c,d,5));  
}

Test(hw3_connect_int_arrays, connect_int_arrays01)
{
  int a[] = {2};
  int b[] = {3,4,5};
  int *c = connect_int_arrays(a,1,b,3);
  int d[] = {2,3,4,5};
  cr_assert(int_arr_eq(c,d,4));  
}

Test(hw3_connect_int_arrays, connect_int_arrays02)
{
  int a[] = {2};
  int b[] = {5};
  int *c = connect_int_arrays(a,1,b,1);
  int d[] = {2,5};
  cr_assert(int_arr_eq(c,d,2));  
}

Test(hw3_connect_int_arrays, connect_int_arrays03)
{
  int a[] = {1,2};
  int b[] = {2,1};
  int *c = connect_int_arrays(a,2,b,2);
  int d[] = {1,2,2,1};
  cr_assert(int_arr_eq(c,d,4));  
}

// -------- truncate

Test(hw3_truncate, truncate00)
{
  double a[] = {1.1,2.9,3.6};
  int b[] = {1,2,3};
  int *c = truncate(a,3);
  cr_assert(int_arr_eq(b,c,3));
}

Test(hw3_truncate, truncate01)
{
  double a[] = {1.1};
  int b[] = {1};
  int *c = truncate(a,1);
  cr_assert(int_arr_eq(b,c,1));
}

Test(hw3_truncate, truncate02)
{
  double a[] = {1.1,1.2,1.3,1.9};
  int b[] = {1,1,1,1};
  int *c = truncate(a,4);
  cr_assert(int_arr_eq(b,c,4));
}

Test(hw3_truncate, truncate03)
{
  double a[] = {3.3,2.2,4.4};
  int b[] = {3,2,4};
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

Test(hw3_primes, primes01)
{
  int *p = primes(1);
  int a[] = {2};
  cr_assert(int_arr_eq(p,a,1));
}

Test(hw3_primes, primes02)
{
  int *p = primes(15);
  int a[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  cr_assert(int_arr_eq(p,a,15));
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

Test(hw3_nonprimes, nonprimes01)
{
  int a[] = {10,20,30,40,50};
  int count=0;
  int *n = nonprimes(a,5,&count);
  int b[] = {10,20,30,40,50};
  cr_assert(count==5 && int_arr_eq(n,b,5));
}

Test(hw3_nonprimes, nonprimes02)
{
  int a[] = {2,10,2,20,2,30,2,40,2,50};
  int count=0;
  int *n = nonprimes(a,10,&count);
  int b[] = {10,20,30,40,50};
  cr_assert(count==5 && int_arr_eq(n,b,5));
}

Test(hw3_nonprimes, nonprimes03)
{
  int a[] = {2,2,2,2,2};
  int count=0;
  int *n = nonprimes(a,5,&count);
  cr_assert(n==NULL);
}
