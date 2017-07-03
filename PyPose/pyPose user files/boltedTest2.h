#ifndef SCOTCHBOT-2_POSES
#define SCOTCHBOT-2_POSES

#include <avr/pgmspace.h>

PROGMEM prog_uint16_t FILL5[] = {7, 227, 721, 298, 646, 369, 606, 508};
PROGMEM prog_uint16_t Fill6[] = {7, 247, 649, 371, 463, 555, 712, 510};
PROGMEM prog_uint16_t POUR8[] = {7, 687, 646, 371, 469, 549, 711, 515};
PROGMEM prog_uint16_t CENTER[] = {7, 512, 512, 512, 512, 512, 512, 512};
PROGMEM prog_uint16_t Fill3[] = {7, 231, 592, 429, 477, 542, 520, 510};
PROGMEM prog_uint16_t SIMBA5[] = {7, 510, 414, 605, 726, 288, 203, 499};
PROGMEM prog_uint16_t Simba6[] = {7, 512, 414, 605, 726, 288, 265, 614};
PROGMEM prog_uint16_t POUR7[] = {7, 685, 647, 372, 469, 549, 713, 924};
PROGMEM prog_uint16_t POUR6[] = {7, 698, 653, 366, 469, 548, 726, 583};
PROGMEM prog_uint16_t POUR5[] = {7, 706, 646, 372, 451, 567, 706, 645};
PROGMEM prog_uint16_t SLEEP[] = {7, 687, 200, 818, 204, 812, 444, 936};
PROGMEM prog_uint16_t prepour5[] = {7, 724, 508, 511, 628, 387, 418, 512};
PROGMEM prog_uint16_t Simba 7[] = {7, 499, 356, 661, 667, 346, 193, 614};

PROGMEM transition_t FILLPOURRST1[] = {{0,12} ,{CENTER,5000} ,{Fill3,5000} ,{FILL5,5000} ,{Fill6,5000} ,{SIMBA5,5000} ,{Simba6,5000} ,{Simba 7,5000} ,{prepour5,5000} ,{POUR5,5000} ,{POUR6,5000} ,{prepour5,5000} ,{SIMBA5,5000} };

#endif
