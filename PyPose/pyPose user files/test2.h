#ifndef SCOTCHBOT-2_POSES
#define SCOTCHBOT-2_POSES

#include <avr/pgmspace.h>

PROGMEM prog_uint16_t FILL5[] = {7, 218, 692, 326, 686, 327, 501, 499};
PROGMEM prog_uint16_t POUR8[] = {7, 401, 595, 426, 517, 501, 590, 513};
PROGMEM prog_uint16_t CENTER[] = {7, 512, 512, 512, 512, 512, 512, 512};
PROGMEM prog_uint16_t SIMBA5[] = {7, 261, 433, 586, 693, 320, 250, 499};
PROGMEM prog_uint16_t POUR7[] = {7, 417, 612, 406, 510, 508, 600, 657};
PROGMEM prog_uint16_t POUR6[] = {7, 420, 620, 397, 507, 511, 631, 927};
PROGMEM prog_uint16_t POUR5[] = {7, 429, 624, 395, 494, 524, 629, 645};
PROGMEM prog_uint16_t POUR4[] = {7, 414, 626, 393, 499, 520, 640, 514};
PROGMEM prog_uint16_t REST5[] = {7, 303, 724, 295, 516, 502, 732, 616};
PROGMEM prog_uint16_t MADDY1[] = {7, 512, 363, 655, 776, 238, 135, 818};
PROGMEM prog_uint16_t HOME[] = {7, 272, 353, 665, 326, 689, 533, 508};

PROGMEM transition_t FILLPOURRST1[] = {{0,0} };

#endif
