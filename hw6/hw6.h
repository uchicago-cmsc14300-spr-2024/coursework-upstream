#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

// SOS phase1
// remove leading and trailing spaces
// produce a new heap string
// ex: " Help  us!  " -> "Help  us!"
char *trim(char *s);

// SOS phase2
// construct an ASCII version of SOS message
// - keep all digits
// - keep uppercase letters, replacing BIOSZ for 81052
// - raise lowercase letters and also swap for digits
// - keep spaces
// - discard everything else
// produce a new heap string
// ex: "Help  us!" --> "HELP  U5"
char *sos_translate(char *s);

// SOS phase3
// eliminate double spaces
// produce a new heap string
// ex: "HELP  U5" --> "HELP U5"
char *squeeze_spaces(char *s);

// SOS phase4
// append two trailing spaces
// produce a new heap string
// ex: "HELP U5" --> "HELP U5  "
char *sos_terminate(char *s);

// SOS phase5
// convert string to an array of SOS indexes
// the SOS characters are not packed in this phase
// ex: "HELP U5  " ->
//     [16] [13] [19] [22] [31] [26] [5] [31] [31]
uint8_t *ascii_to_sos(char *s);

// SOS phase6
// pack SOS chars next to one another, 5 bytes each
// ex: [16] [13] [19] [22] [31] [26] [5] [31] [31]
//     (see [*] below for details)
// set "outlen" to the length of the resulting array
uint8_t *sos_pack(uint8_t *sos_indices, int len, int *outlen);

// all together now...
// perform phases 1-6 above
// set "outlen" to the length of the resulting array
uint8_t *sos_encode(char *message, int *outlen);


// [*] phase6 example

//     H     E     L     P           U     5
//    16    13    19    22    31    26     5    31    31
// 10000 01101 10011 10110 11111 11010 00101 11111 11111

// this packs into six bytes as follows:
// (dots among the bits show character boundaries)

// hex  binary
// 0X83 10000.011
// 0X67 01.10011.1
// 0X6F 0110.1111
// 0XE8 1.11010.00
// 0XBF 101.11111.
// 0XF8 11111.000 (note: last byte padded with trailing zeros)
