// CMSC 14300, Spring 2024
// header file for HW1

// convert degrees Fahrenheit to Kelvin
double f2k(double f);

// convert Kelvin to degrees Fahrenheit
double k2f(double k);

// pythag returns a bool-like int
// assume c is the hypotenuse
// a, b, and c must all be positive for result to be "true"
int pythag(int a, int b, int c);

// w is an hourly wage in dollars
// h is a number of hours
// the first 40 hours earn w dollars each
// over 40 hours is time-and-a-half pay
// (that is, 1.5 hourly wage)
// the result should be a truncated number (partial dollars discarded)
int weekly_pay(int w, int h);

// f is a fare in dollars
// add a 15% tip and round up to nearest dollar
int cab_fare_with_tip(int f);

// what is the number of digits in n-to-the-nth-power?
unsigned int digits(unsigned int n);

// compute the volume of a hemishell
double hemishell_volume(double outer_radius, double thickness);

// compute the surface area of a hemishell
double hemishell_surface(double outer_radius, double thickness);
