#include <stdio.h>
#include <criterion/criterion.h>
#include <math.h>
#include "hw2.h"

// ======== constants

const double TOL = 0.001;
// TOL for "tolerance"

// ======== helper functions

int within(double epsilon, double a, double b)
{
  return fabs(a-b)<=epsilon;
}

// ======== tests

// -------- sph_contains

Test(hw2_sph, sph00)
{
  cr_assert(sph_contains(0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.9));
}

// -------- luminance

Test(hw2_lum, lum00)
{
  cr_assert(within(TOL,luminance(0X100),0.0722));
}

// -------- brighter

Test(hw2_brighter, brighter00)
{
  cr_assert(brighter(0X100,0));
}

// -------- dimmer

Test(hw2_dimmer, dimmer00)
{
  cr_assert(dimmer(0,0X100));
}

// -------- valid_date

Test(hw2_valid, valid00)
{
  cr_assert(valid_date(20240326));
}

// -------- yesterday

Test(hw2_yesterday, yesterday00)
{
  cr_assert(yesterday(20240326)==20240325);
}

// -------- tomorrow

Test(hw2_tomorrow, tomorrow00)
{
  cr_assert(tomorrow(20240326)==20240327);
}

// -------- earlier

Test(hw2_earlier, earlier00)
{
  cr_assert(earlier(20240201,20240301));
}

// -------- later

Test(hw2_later, later00)
{
  cr_assert(later(20240401,20240301));
}

// -------- f_integral

Test(hw2_fint, fint00)
{
  cr_assert(within(TOL,f_integral(0.0,1.1,1.0),30.0));
}

// -------- g_integral

Test(hw2_gint, gint00)
{
  cr_assert(within(TOL,g_integral(0.0,1.1,1.0),20.0));
}

// -------- count_ones

Test(hw2_ones, ones00)
{
  cr_assert(count_ones(1)==1);
}

// -------- count_zeroes

Test(hw2_zeroes, zeroes00)
{
  cr_assert(count_zeroes(1)==31);
}

// -------- bits_match

Test(hw2_match, match00)
{
  cr_assert(bits_match(123,123)==32);
}


