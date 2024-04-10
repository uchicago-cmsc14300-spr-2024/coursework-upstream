#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "hw4.h"

char *format_date(idate d)
{
  exit(1);
}

struct point *point_new(double x, double y)
{
  exit(1);
}

char *point_tos(struct point *p)
{
  exit(1);  
}

struct point *push_x(struct point *p, double dx)
{
  exit(1);
}

struct point *push_y(struct point *p, double dy)
{
  exit(1);
}

struct point *towards_origin(struct point *p)
{
  exit(1);
}

double distance(struct point *p, struct point *q)
{
  exit(1);
}

int same_quadrant(struct point *p, struct point *q)
{
  exit(1);
}

idate ida_read(struct idate_array *a, int i)
{
  exit(1);
}

void ida_write(struct idate_array *a, int i, idate d)
{
  exit(1);
}

struct idate_array *ida_build(idate start, unsigned int len)
{
  exit(1);
}
			     
void ida_free(struct idate_array *a)
{
  exit(1);
}

struct image *img_solid(unsigned int w, unsigned int h, prgb c)
{
  exit(1);
}

void img_free(struct image *img)
{
  exit(1);
}

double mean_luminance(struct image *img)
{
  exit(1);
}
