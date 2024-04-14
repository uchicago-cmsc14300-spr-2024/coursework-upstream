#include <stdio.h>
#include <criterion/criterion.h>
#include <math.h>
#include "hw4.h"

// ======== tests

// Please note: the _free_ functions don't have tests, since freeing
// is not subject to unit testing (as there is no easy way to tell if
// it succeeded).

// -------- format_date

Test(hw4_format, format00)
{
  char *s = format_date(20240101);
  cr_assert(1);
  free(s);
}

// -------- point_new

Test(hw4_point_new, point_new00)
{
  struct point *p = point_new(0,0);
  cr_assert(1);
  free(p);
}

// -------- point_tos

Test(hw4_point_tos, point_tos00)
{
  struct point *p = point_new(0,0);
  char *s = point_tos(p);
  cr_assert(1);
  free(s);
  free(p);
}

// -------- push_x

Test(hw4_push_x, push_x00)
{
  struct point *p = point_new(0,0);
  struct point *q = push_x(p,0.1);
  cr_assert(1);
  free(q);
  free(p);
}

// -------- push_y

Test(hw4_push_y, push_y00)
{
  struct point *p = point_new(0,0);
  struct point *q = push_y(p,0.1);
  cr_assert(1);
  free(q);
  free(p);
}

// -------- towards_origin

Test(hw4_towards, towards00)
{
  struct point *p = point_new(0,0);
  struct point *q = towards_origin(p);
  free(q);
  free(p);
  cr_assert(1);
}

// -------- distance

Test(hw4_distance, distance00)
{
  struct point *p = point_new(0,0);
  double d = distance(p,p);
  cr_assert(1);
  free(p);
}

// -------- same_quadrant

Test(hw4_same_quad, same_quad00)
{
  struct point *p = point_new(0,0);
  int q = same_quadrant(p,p);
  cr_assert(1);
  free(p);
}

// -------- ida_read

Test(hw4_ida_read, ida_read00)
{
  idate a[] = {20240101};
  struct idate_array arr = {a,1};
  idate d = ida_read(&arr,0);
  cr_assert(1);
}

// -------- ida_write

Test(hw4_ida_write, ida_write00)
{
  idate a[] = {20240101};
  struct idate_array arr = {a,1};
  ida_write(&arr,0,20240102);
  cr_assert(1);
}

// -------- ida_build

Test(hw4_ida_build, ida_build00)
{
  struct idate_array *a = ida_build(20240101,1);
  cr_assert(1);
  ida_free(a);
}

// -------- img_solid

Test(hw4_img_solid, img_solid00)
{
  struct image *img = img_solid(2,3,0);
  cr_assert(1);
  img_free(img);
}

// -------- mean_luminance

Test(hw4_mean_luminance, mean_luminance00)
{
  struct image *img = img_solid(2,3,0);
  double lum = mean_luminance(img);
  cr_assert(1);
  img_free(img);
}
