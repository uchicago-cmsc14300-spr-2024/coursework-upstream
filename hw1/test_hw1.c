#include <stdio.h>
#include <criterion/criterion.h>
#include <math.h>
#include "hw1.h"

// ======== constants

const double TOL = 0.001;
// TOL for "tolerance"

// ======== helper functions

int within(double epsilon, double a, double b)
{
  return fabs(a-b)<=epsilon;
}

// ======== tests

// -------- f2k

Test(hw1_f2k, f2k00)
{
  double k = f2k(32.0);
  cr_assert(within(TOL,k,273.15));
}

Test(hw1_f2k, f2k01)
{
  double k = f2k(212.0);
  cr_assert(within(TOL,k,373.15));
}

Test(hw1_f2k, f2k02)
{
  double k = f2k(0.0);
  cr_assert(within(TOL,k,255.372));
}

Test(hw1_f2k, f2k03)
{
  double k = f2k(425.0);
  cr_assert(within(TOL,k,491.483));
}

Test(hw1_f2k, f2k04)
{
  double k = f2k(-100.0);
  cr_assert(within(TOL,k,199.817));
}

// -------- k2f

Test(hw1_k2f, k2f00)
{
  double f = k2f(0.0);
  cr_assert(within(TOL,f,-459.67));
}

Test(hw1_k2f, k2f01)
{
  double f = k2f(100.0);
  cr_assert(within(TOL,f,-279.67));
}

Test(hw1_k2f, k2f02)
{
  double f = k2f(200.0);
  cr_assert(within(TOL,f,-99.67));
}

Test(hw1_k2f, k2f03)
{
  double f = k2f(300.0);
  cr_assert(within(TOL,f,80.33));
}

// -------- pythag

Test(hw1_pythag, pythag00)
{
  cr_assert(pythag(3,4,5));
}

Test(hw1_pythag, pythag01)
{
  cr_assert(pythag(4,3,5));
}

Test(hw1_pythag, pythag02)
{
  cr_assert(!pythag(2,3,5));
}

Test(hw1_pythag, pythag03)
{
  cr_assert(!pythag(-3,4,5));
}

Test(hw1_pythag, pythag04)
{
  cr_assert(!pythag(3,-4,5));
}

Test(hw1_pythag, pythag05)
{
  cr_assert(pythag(33,44,55));
}

// -------- weekly_pay

Test(hw1_pay, pay00)
{
  cr_assert(weekly_pay(40,40)==1600);
}

Test(hw1_pay, pay01)
{
  cr_assert(weekly_pay(40,41)==1660);
}

Test(hw1_pay, pay02)
{
  cr_assert(weekly_pay(15,60)==1050);
}

Test(hw1_pay, pay03)
{
  cr_assert(weekly_pay(15,0)==0);
}

// -------- cab_fare_with_tip

Test(hw_cab, cab00)
{
  cr_assert(cab_fare_with_tip(10)==12);
}

Test(hw_cab, cab01)
{
  cr_assert(cab_fare_with_tip(61)==71);
}

Test(hw_cab, cab02)
{
  cr_assert(cab_fare_with_tip(100)==115);
}

Test(hw_cab, cab03)
{
  cr_assert(cab_fare_with_tip(101)==117);
}

// -------- digits

Test(hw_digits, digits00)
{
  cr_assert(digits(2)==1);
}

Test(hw_digits, digits01)
{
  cr_assert(digits(3)==2);
}

Test(hw_digits, digits02)
{
  cr_assert(digits(4)==3);
}

Test(hw_digits, digits03)
{
  cr_assert(digits(10)==11);
}

// -------- hemishell_volume

Test(hw_hvol, hvol00)
{
  cr_assert(within(TOL,hemishell_volume(10.0,1.0),567.58107));
}

Test(hw_hvol, hvol01)
{
  cr_assert(within(TOL,hemishell_volume(10.0,0.1),62.20562));
}

Test(hw_hvol, hvol02)
{
  cr_assert(within(TOL,hemishell_volume(100.0,1.0),62205.62894));
}

Test(hw_hvol, hvol03)
{
  cr_assert(within(TOL,hemishell_volume(4.0,0.2),19.117638));
}

// -------- hemishell_surface

Test(hw_hsurf, hsurf00)
{
  cr_assert(within(TOL,hemishell_surface(10.0,1.0),1196.9468));
}

Test(hw_hsurf, hsurf01)
{
  cr_assert(within(TOL,hemishell_surface(10.0,0.1),1250.38529));
}

Test(hw_hsurf, hsurf02)
{
  cr_assert(within(TOL,hemishell_surface(100.0,1.0),125038.5292));
}

Test(hw_hsurf, hsurf03)
{
  cr_assert(within(TOL,hemishell_surface(4.0,0.2),196.16104));
}
