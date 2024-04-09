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

Test(hw2_sph, sph01)
{
  cr_assert(sph_contains(0.0,0.0,0.0,1.0,0.1,0.0,0.0,0.5));
}

Test(hw2_sph, sph02)
{
  cr_assert(sph_contains(0.0,0.0,0.0,1.0,0.0,0.1,0.0,0.5));
}

Test(hw2_sph, sph03)
{
  cr_assert(sph_contains(0.0,0.0,0.0,1.0,0.0,0.0,0.1,0.5));
}

Test(hw2_sph, sph04)
{
  cr_assert(!sph_contains(0.0,0.0,0.0,1.0,0.9,0.9,0.9,0.5));
}

Test(hw2_sph, sph05)
{
  cr_assert(!sph_contains(0.0,0.0,0.0,1.0,0.9,0.9,0.9,0.2));
}

Test(hw2_sph, sph06)
{
  cr_assert(!sph_contains(0.0,0.0,0.0,1.0,1.01,0.0,0.0,0.1));
}

Test(hw2_sph, sph07)
{
  cr_assert(!sph_contains(0.0,0.0,0.0,1.0,0.0,1.01,0.0,0.1));
}

Test(hw2_sph, sph08)
{
  cr_assert(!sph_contains(0.0,0.0,0.0,1.0,0.0,0.0,1.01,0.1));
}

Test(hw2_sph, sph09)
{
  cr_assert(sph_contains(1,2,3,2,1,2,3,1));
}

// -------- luminance

Test(hw2_lum, lum00)
{
  cr_assert(within(TOL,luminance(0X00000100),0.0722));
}

Test(hw2_lum, lum01)
{
  cr_assert(within(TOL,luminance(0X00010000),0.7152));
}

Test(hw2_lum, lum02)
{
  cr_assert(within(TOL,luminance(0X01000000),0.2126));
}

Test(hw2_lum, lum03)
{
  cr_assert(within(TOL,luminance(0X0A0B0C00),10.8596));
}

Test(hw2_lum, lum04)
{
  cr_assert(within(TOL,luminance(0X100A0000),10.5536));
}

Test(hw2_lum, lum05)
{
  cr_assert(within(TOL,luminance(0X10000A00),4.1236));
}

Test(hw2_lum, lum06)
{
  cr_assert(within(TOL,luminance(0X00100A00),12.1652));
}

Test(hw2_lum, lum07)
{
  cr_assert(within(TOL,luminance(0XFFFFFF00),255));
}

// -------- brighter

Test(hw2_brighter, brighter00)
{
  cr_assert(brighter(0X00000100,0X00000000));
}

Test(hw2_brighter, brighter01)
{
  cr_assert(brighter(0X00010000,0X01000000));
}

Test(hw2_brighter, brighter02)
{
  cr_assert(brighter(0X00010000,0X00000100));
}

Test(hw2_brighter, brighter03)
{
  cr_assert(brighter(0X00020000,0X00010000));
}

Test(hw2_brighter, brighter04)
{
  cr_assert(!brighter(0X00020000,0X00020000));
}

Test(hw2_brighter, brighter05)
{
  cr_assert(!brighter(0X00020000,0X00030000));
}

Test(hw2_brighter, brighter06)
{
  cr_assert(!brighter(0X01020300,0XFFFFFF00));
}

// -------- dimmer

Test(hw2_dimmer, dimmer00)
{
  cr_assert(dimmer(0X00000000,0X00000100));
}

Test(hw2_dimmer, dimmer01)
{
  cr_assert(!dimmer(0X00010000,0X01000000));
}

Test(hw2_dimmer, dimmer02)
{
  cr_assert(!dimmer(0X00010000,0X00000100));
}

Test(hw2_dimmer, dimmer03)
{
  cr_assert(!dimmer(0X00020000,0X00010000));
}

Test(hw2_dimmer, dimmer04)
{
  cr_assert(!dimmer(0X00020000,0X00020000));
}

Test(hw2_dimmer, dimmer05)
{
  cr_assert(dimmer(0X00020000,0X00030000));
}

Test(hw2_dimmer, dimmer06)
{
  cr_assert(dimmer(0X01020300,0XFFFFFF00));
}

// -------- valid_date

Test(hw2_valid, valid00)
{
  cr_assert(valid_date(20240326));
}

Test(hw2_valid, valid01)
{
  cr_assert(valid_date(20240229));
}

Test(hw2_valid, valid02)
{
  cr_assert(valid_date(20240131));
}

Test(hw2_valid, valid03)
{
  cr_assert(!valid_date(20240031));
}

Test(hw2_valid, valid04)
{
  cr_assert(!valid_date(20240100));
}

Test(hw2_valid, valid05)
{
  cr_assert(!valid_date(20240132));
}

Test(hw2_valid, valid06)
{
  cr_assert(valid_date(20240331));
}

Test(hw2_valid, valid07)
{
  cr_assert(valid_date(20240430));
}

Test(hw2_valid, valid08)
{
  cr_assert(!valid_date(20240431));
}

Test(hw2_valid, valid09)
{
  cr_assert(!valid_date(20241331));
}

Test(hw2_valid, valid0A)
{
  cr_assert(!valid_date(20240000));
}

// -------- yesterday

Test(hw2_yesterday, yesterday00)
{
  cr_assert(yesterday(20240326)==20240325);
}

Test(hw2_yesterday, yesterday01)
{
  cr_assert(yesterday(20240101)==20231231);
}

Test(hw2_yesterday, yesterday02)
{
  cr_assert(yesterday(20240201)==20240131);
}

Test(hw2_yesterday, yesterday03)
{
  cr_assert(yesterday(20240301)==20240229);
}

Test(hw2_yesterday, yesterday04)
{
  cr_assert(yesterday(20250301)==20250228);
}

Test(hw2_yesterday, yesterday05)
{
  cr_assert(yesterday(20240401)==20240331);
}

Test(hw2_yesterday, yesterday06)
{
  cr_assert(yesterday(20240501)==20240430);
}

Test(hw2_yesterday, yesterday07)
{
  cr_assert(yesterday(20240601)==20240531);
}

Test(hw2_yesterday, yesterday08)
{
  cr_assert(yesterday(20240701)==20240630);
}

Test(hw2_yesterday, yesterday09)
{
  cr_assert(yesterday(20240801)==20240731);
}

Test(hw2_yesterday, yesterday0A)
{
  cr_assert(yesterday(20240901)==20240831);
}

Test(hw2_yesterday, yesterday0B)
{
  cr_assert(yesterday(20241001)==20240930);
}

Test(hw2_yesterday, yesterday0C)
{
  cr_assert(yesterday(20241101)==20241031);
}

Test(hw2_yesterday, yesterday0D)
{
  cr_assert(yesterday(20241201)==20241130);
}

Test(hw2_yesterday, yesterday0E)
{
  cr_assert(yesterday(20000301)==20000229);
}

Test(hw2_yesterday, yesterday0F)
{
  cr_assert(yesterday(21000301)==21000228);
}

// -------- tomorrow

Test(hw2_tomorrow, tomorrow00)
{
  cr_assert(tomorrow(20240326)==20240327);
}

Test(hw2_tomorrow, tomorrow01)
{
  cr_assert(tomorrow(20231231)==20240101);
}

Test(hw2_tomorrow, tomorrow02)
{
  cr_assert(tomorrow(20240131)==20240201);
}

Test(hw2_tomorrow, tomorrow03)
{
  cr_assert(tomorrow(20240228)==20240229);
}

Test(hw2_tomorrow, tomorrow04)
{
  cr_assert(tomorrow(20240229)==20240301);
}

Test(hw2_tomorrow, tomorrow05)
{
  cr_assert(tomorrow(20250228)==20250301);
}

Test(hw2_tomorrow, tomorrow06)
{
  cr_assert(tomorrow(20240331)==20240401);
}

Test(hw2_tomorrow, tomorrow07)
{
  cr_assert(tomorrow(20240430)==20240501);
}

Test(hw2_tomorrow, tomorrow08)
{
  cr_assert(tomorrow(20240531)==20240601);
}

Test(hw2_tomorrow, tomorrow09)
{
  cr_assert(tomorrow(20240630)==20240701);
}

Test(hw2_tomorrow, tomorrow0A)
{
  cr_assert(tomorrow(20240731)==20240801);
}

Test(hw2_tomorrow, tomorrow0B)
{
  cr_assert(tomorrow(20240831)==20240901);
}

Test(hw2_tomorrow, tomorrow0C)
{
  cr_assert(tomorrow(20240930)==20241001);
}

Test(hw2_tomorrow, tomorrow0D)
{
  cr_assert(tomorrow(20241031)==20241101);
}

Test(hw2_tomorrow, tomorrow0E)
{
  cr_assert(tomorrow(20241130)==20241201);
}

Test(hw2_tomorrow, tomorrow0F)
{
  cr_assert(tomorrow(20250228)==20250301);
}

// -------- earlier

Test(hw2_earlier, earlier00)
{
  cr_assert(earlier(20240201,20240301));
}

Test(hw2_earlier, earlier01)
{
  cr_assert(earlier(20230201,20240301));
}

Test(hw2_earlier, earlier02)
{
  cr_assert(earlier(20230231,20240101));
}

Test(hw2_earlier, earlier03)
{
  cr_assert(!earlier(20240201,20200301));
}

Test(hw2_earlier, earlier04)
{
  cr_assert(!earlier(20240401,20240301));
}

// -------- later

Test(hw2_later, later00)
{
  cr_assert(later(20240401,20240301));
}

Test(hw2_later, later01)
{
  cr_assert(!later(20230201,20240301));
}

Test(hw2_later, later02)
{
  cr_assert(!later(20230231,20240101));
}

Test(hw2_later, later03)
{
  cr_assert(later(20240201,20200301));
}

Test(hw2_later, later04)
{
  cr_assert(later(20240401,20240301));
}

// -------- f_integral

Test(hw2_fint, fint00)
{
  cr_assert(within(TOL,f_integral(0.0,1.1,1.0),30.0));
}

Test(hw2_fint, fint01)
{
  cr_assert(within(TOL,f_integral(0.0,0.6,0.5),15.0));
}

Test(hw2_fint, fint02)
{
  cr_assert(within(TOL,f_integral(0.0,0.15,0.1),3.0));
}

Test(hw2_fint, fint03)
{
  cr_assert(within(TOL,f_integral(0.0,1.0,0.17),25.504913));
}

Test(hw2_fint, fint04)
{
  cr_assert(within(TOL,f_integral(0.0,1.0,0.19),28.506859));
}

Test(hw2_fint, fint05)
{
  cr_assert(within(TOL,f_integral(0.0,1.0,0.1),30.0095));
}

Test(hw2_fint, fint06)
{
  cr_assert(within(TOL,f_integral(0.0,11.0,0.01),344.768728));
}

Test(hw2_fint, fint07)
{
  cr_assert(within(TOL,f_integral(-1,1,0.1),60.02233));
}

// -------- g_integral

Test(hw2_gint, gint00)
{
  cr_assert(within(TOL,g_integral(0.0,1.1,1.0),20.0));
}

Test(hw2_gint, gint01)
{
  cr_assert(within(TOL,g_integral(0.0,0.6,0.5),10.0));
}

Test(hw2_gint, gint02)
{
  cr_assert(within(TOL,g_integral(0.0,0.15,0.1),2.0));
}

Test(hw2_gint, gint03)
{
  cr_assert(within(TOL,g_integral(0.0,1.0,0.17),17.275338));
}

Test(hw2_gint, gint04)
{
  cr_assert(within(TOL,g_integral(0.0,1.0,0.19),19.339783));
}

Test(hw2_gint, gint05)
{
  cr_assert(within(TOL,g_integral(0.0,1.0,0.1),20.417240));
}

Test(hw2_gint, gint06)
{
  cr_assert(within(TOL,g_integral(0.0,11.0,0.01),221.000565));
}

Test(hw2_gint, gint07)
{
  cr_assert(within(TOL,g_integral(-1,1,0.1),39.915852));
}

// -------- count_ones

Test(hw2_ones, ones00)
{
  cr_assert(count_ones(1)==1);
}

Test(hw2_ones, ones01)
{
  cr_assert(count_ones(255)==8);
}

Test(hw2_ones, ones02)
{
  cr_assert(count_ones(0X01010101)==4);
}

Test(hw2_ones, ones03)
{
  cr_assert(count_ones(0X0103070F)==10);
}

Test(hw2_ones, ones04)
{
  cr_assert(count_ones(0XFFFFFFFF)==32);
}

// -------- count_zeroes

Test(hw2_zeroes, zeroes00)
{
  cr_assert(count_zeroes(1)==31);
}

Test(hw2_zeroes, zeroes01)
{
  cr_assert(count_zeroes(255)==24);
}

Test(hw2_zeroes, zeroes02)
{
  cr_assert(count_zeroes(0X01010101)==28);
}

Test(hw2_zeroes, zeroes03)
{
  cr_assert(count_zeroes(0X0103070F)==22);
}

Test(hw2_zeroes, zeroes04)
{
  cr_assert(count_zeroes(0XFFFFFFFF)==0);
}

// -------- bits_match

Test(hw2_match, match00)
{
  cr_assert(bits_match(123,123)==32);
}

Test(hw2_match, match01)
{
  cr_assert(bits_match(1,3)==31);
}

Test(hw2_match, match02)
{
  cr_assert(bits_match(0XFFFFFF00,0XFFFFFFFF)==24);
}

Test(hw2_match, match03)
{
  cr_assert(bits_match(0XFFFF0000,0XFFFFFFFF)==16);
}

Test(hw2_match, match04)
{
  cr_assert(bits_match(0XFFFFFFFF,0X00000000)==0);
}
