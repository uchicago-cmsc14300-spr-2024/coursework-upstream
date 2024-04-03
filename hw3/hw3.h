#include <stdint.h>

typedef unsigned char byte;
typedef uint32_t idate;
typedef uint32_t prgb;

// In general, it is *allowed* to sort an array in a function in order
// to compute something about that array.

// reverse array in place
// GIGO if arr is NULL or if len is incorrect
void reverse(int *arr, int len);

// sift up min-heap operation
// GIGO if arr is NULL or pos is outside the array
void sift_up(int *arr, int pos);

// sift down min-heap operation
// GIGO if arr is NULL, if pos is outside the array, or len is incorrect
void sift_down(int *arr, int pos, int len);

// in-place heapsort
// named heapsort143 because the name "heapsort" is taken
// perform in-place heapsort using sift operations
void heapsort143(int *arr, int len);

// find median
// if there are two medians, compute their average
// GIGO if arr is NULL or len is incorrect
double median(int *arr, int len);

// find mode of array
// if there is a tie, return any mode
// GIGO if arr is NULL or len is incorrect
int mode(int *arr, int len);

// compute days in given span, inclusive
// return 0 if date1 falls after date2
int days_between_incl(idate date1, idate date2);

// return latest date in array
// GIGO if dates is NULL or len is incorrect
idate max_date(idate *dates, int len);

// return earliest date in array
// GIGO if dates is NULL or len is incorrect
idate min_date(idate *dates, int len);

// count number of days between min and max in array
// (input array not assumed in any particular order)
// GIGO if dates is NULL or len is incorrect
int day_span(idate *dates, int len);

// build array of dates from start to end inclusive
// return NULL if start date is after end date
idate *all_dates(idate start_incl, idate end_incl);

// compute the integer-mean red component of array of colors
// GIGO if colors is NULL or len is incorrect
byte mean_red(prgb *colors, int len);

// build new array that is a connected to b
// GIGO if a or b is NULL or either length incorrect
int *connect(int *a, int alen, int *b, int blen);

// build new array that contains all doubles, truncated
// GIGO if a is NULL or len is incorrect
int *truncate(double *a, int len);

// build array of the first n primes
// return NULL if n<1
int *primes(int n);

// filter all the nonprimes in array, report size in "count"
// if no nonprimes, return NULL
// GIGO if a is NULL or len is incorrect
int *nonprimes(int *a, int len, int *count);
