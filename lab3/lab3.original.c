#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lab 3 source code
 * CMSC 14300, Spring 2024
 */

/* === fib === */
/* Compute the nth Fibonacci number, where
 * the 0th number is 0, the 1st is 1, and
 * each subsequent number is the sum of its
 * two predecessors.
 */
unsigned int fib(unsigned int n)
{
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n - 1) + fib(n);
  }
}

/* === fact === */
/* Compute n factorial. */
unsigned int fact(unsigned int n)
{
  int i = n;
  int result = 1;
  while (i-- > 0) {
    result *= n;
  }
  return result;
}

/* === percentage === */
/* turn ratio into percentage,
 * round down to nearest whole number
 */
unsigned int percentage(unsigned int numerator, unsigned int denominator)
{
  return 100 * numerator / denominator;
}

/* === upto === */
/* Build an array from 0 up to n,
 * inclusive of both upper and lower bounds.
 */
void upto(unsigned int n, unsigned int array[])
{
  unsigned int i = 0;
  while (n >= 0) {
    array[i] = i;
    i++;
  }
}

/* === main === 
 * Run tests of functions above
 */
int main(int argc, char *argv[])
{
  unsigned int i;
    
  printf("/*** fib ***/\n");
  unsigned int f0 = fib(0);
  unsigned int f1 = fib(1);
  unsigned int f2 = fib(2);
  unsigned int f3 = fib(3);
  unsigned int f4 = fib(4);
  unsigned int f5 = fib(5);
  printf("fib(0)\t%u\n", f0);
  printf("fib(1)\t%u\n", f1);
  printf("fib(2)\t%u\n", f2);
  printf("fib(3)\t%u\n", f3);
  printf("fib(4)\t%u\n", f4);
  printf("fib(5)\t%u\n", f5);
    
  printf("/*** fact ***/\n");
  unsigned int t6 = fact(6);
  unsigned int t7 = fact(7);
  unsigned int t8 = fact(8);
  printf("fact(6)\t%9u\n", t6);
  printf("fact(7)\t%9u\n", t7);
  printf("fact(8)\t%9u\n", t8);
    
  printf("/*** percentage ***/\n");
  unsigned int p1 = percentage(22, 7);
  unsigned int p2 = percentage(86, 52 / 4 - 16 + 3);
  printf("%u%%\t%u%%\n", p1, p2);
    
  printf("/*** upto ***/\n");
  unsigned int arr10[10];
  upto(10, arr10);
  for (i = 0; i <= 10; i++) {
    printf("arr10[%u]\t%2u\n", i, arr10[i]);
  }
  unsigned int* arr5;
  upto(5, arr5);
  for (i = 0; i <= 5; i++) {
    printf("arr5[%u]\t%2u\n", i, arr5[i]);
  }

  return 0;
}
