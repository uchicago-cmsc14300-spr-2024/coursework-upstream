#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <time.h>
#include "hw7.h"

// ------ HW6 operations

char *trim(char *s)
{
  exit(1);
}

char *sos_translate(char *s)
{
  exit(1);
}

char *squeeze_spaces(char *s)
{
  exit(1);
}

char *sos_terminate(char *s)
{
  exit(1);
}

uint8_t *ascii_to_sos(char *s)
{
  exit(1);
}

uint8_t *sos_pack(uint8_t *is, int len, int *outlen)
{
  exit(1);
}
	    
uint8_t *sos_encode(char *message, int *outlen)
{
  exit(1);
}

// ------ HW7 operations

packet_list* sos_packetize(uint8_t* payload, int len) {
  exit(1);
}

packet_list* filter_packets(packet_list* packets, message_id id) {
  exit(1);
}

packet_list* sort_packets(packet_list* packets) {
  exit(1);
}

uint8_t* sos_unpack(packet pkt) {
  exit(1);
}

char* sos_to_ascii(uint8_t* sos, int len) {
  exit(1);
}

char* sos_decode(packet_list* packets) {
  exit(1);
}
