#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <criterion/criterion.h>
#include "hw6.h"

// ======== tests

// -------- trim

Test(hw6_trim, trim00)
{
  char *msg = " Help  us!  ";
  char *t = trim(msg);
  cr_assert(!strcmp(t,"Help  us!"));
  free(t);
}

// -------- sos_translate

Test(hw6_sos_translate, sos_translate00)
{
  char *msg = "Help  us!";
  char *t = sos_translate(msg);
  cr_assert(!strcmp(t,"HELP  U5"));
  free(t);
}

// -------- squeeze_spaces

Test(hw6_squeeze_spaces, squeeze_spaces00)
{
  char *msg = "HELP  U5";
  char *t = squeeze_spaces(msg);
  cr_assert(!strcmp(t,"HELP U5"));
  free(t);
}

// -------- sos_terminate

Test(hw6_sos_terminate, sos_terminate00)
{
  char *msg = "HELP U5";
  char *t = sos_terminate(msg);
  cr_assert(!strcmp(t,"HELP U5  "));
  free(t);
}

// -------- ascii_to_sos

Test(hw6_ascii_to_sos, ascii_to_sos00)
{
  char *msg = "HELP U5  ";
  uint8_t *s = ascii_to_sos(msg);
  uint8_t expected[9] = {16,13,19,22,31,26,5,31,31};
  for (int i=0; i<9; i++)
    cr_assert(s[i]==expected[i]);
  free(s);
}

// -------- sos_pack

Test(hw6_sos_pack, sos_pack00)
{
  uint8_t message[9] = {16,13,19,22,31,26,5,31,31};
  int n;
  uint8_t *packed = sos_pack(message,9,&n);
  uint8_t expected[] = {0X83,0X67,0X6F,0XE8,0XBF,0XF8};
  cr_assert(n==6);
  for (int i=0; i<6; i++) {
    cr_assert(packed[i]==expected[i]);
  }
  free(packed);
}

// -------- sos_encode

Test(hw6_encode, encode00)
{
  char *msg = " Help  us!  ";
  int n;
  uint8_t *sos = sos_encode(msg,&n);
  uint8_t expected[] = {0X83,0X67,0X6F,0XE8,0XBF,0XF8};
  cr_assert(n==6);
  for (int i=0; i<6; i++) {
    cr_assert(sos[i]==expected[i]);
  }
  free(sos);
}
