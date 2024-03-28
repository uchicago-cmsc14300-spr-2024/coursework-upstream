#include <stdint.h>

typedef unsigned char byte;
typedef uint32_t idate;
typedef uint32_t prgb;

// A sphere is represented by an (x,y,z) center and a radius.
// Return true if sphere1 completely contains sphere2.
// GIGO if r1 or r2 is nonpositive.
int sph_contains(double cx1, double cy1, double cz1, double r1,
		 double cx2, double cy2, double cz2, double r2);

// a prgb ("packed RGB") contains red in the highest byte, green in
// the second-highest byte, blue in third-highest byte, and 0 in the
// lowest byte. For example, the color (255,255,255) is represented as
// 11111111 11111111 11111111 00000000 as a prgb.

// The luminance (a measure of brightness) of an RGB color
// is 0.2126R + 0.7152G + 0.0722B. Higher luminance corresponds
// to more brightness.
double luminance(prgb c);

// Return true if c1 is brighter than c2 (per luminance).
int brighter(prgb c1, prgb c2);

// Return true if c1 is dimmer than c2 (per luminance).
int dimmer(prgb c1, prgb c2);

// An idate ("integer date") is a year, month, day representation of a
// date as a single integer of the form YYYYMMDD.

// By convention, January is month 1 up to December month 12.

// For example, March 26, 2024 is 20240326 as an idate.

// Verify that the date is legitimate.  For example, January the 49th
// (of any year) is not a legitimate date.
// GIGO if the date is prior to the 20th century.
int valid_date(idate t);

// Return the day immediately before the given day.
// GIGO if the date is prior to the 20th century.
// GIGO if the date is not valid.
idate yesterday(idate t);

// Return the day immediately after the given day.
// GIGO if the date is prior to the 20th century.
// GIGO if the date is not valid.
idate tomorrow(idate t);

// Return true if t1 is an earlier date than t2.
// GIGO if either date is prior to the 20th century.
// GIGO if either date is not valid.
int earlier(idate t1, idate t2);

// Return true if t1 is a later date than t2.
// GIGO if either date is prior to the 20th century.
// GIGO if either date is not valid.
int later(idate t1, idate t2);

// Let f(x)=(x^2/30)+30.
// Compute the integral as a left Riemann sum from a (left) to
//   b (right) where each rectangle has width dx.
// In the sum, only include rectangles that fit within the
//   the integral region (the right edge is allowed to be *at* b).
// GIGO if b<=a or dx<=0.
double f_integral(double a, double b, double dx);

// Let g(x)=sin(x)+20.
// Compute the integral as a left Riemann sum from a (left) to
//   b (right) where each rectangle has width dx.
// In the sum, only include rectangles that fit within the
//   the integral region (the right edge if allowed to be at b).
// GIGO if b<=a or dx<=0.
double g_integral(double a, double b, double dx);

// Count the bits set to 1 in n.
byte count_ones(uint32_t n);

// Count the bits set to 0 in n.
byte count_zeroes(uint32_t n);

// Count the number of bits that are the same, by position, in m and n.
byte bits_match(uint32_t m, uint32_t n);

