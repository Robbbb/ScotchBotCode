#ifndef SCOTCHBOT-2_POSES
#define SCOTCHBOT-2_POSES

#include <avr/pgmspace.h>

PROGMEM prog_uint16_t FILL5[] = {7, 227, 721, 298, 646, 369, 606, 508};
PROGMEM prog_uint16_t Fill6[] = {7, 247, 649, 371, 463, 555, 712, 510};
PROGMEM prog_uint16_t POUR8[] = {7, 401, 595, 426, 517, 501, 590, 513};
PROGMEM prog_uint16_t CENTER[] = {7, 512, 512, 512, 512, 512, 512, 512};
PROGMEM prog_uint16_t Fill3[] = {7, 231, 592, 429, 477, 542, 520, 510};
PROGMEM prog_uint16_t SIMBA5[] = {7, 511, 416, 605, 728, 288, 205, 499};
PROGMEM prog_uint16_t Simba6[] = {7, 512, 414, 605, 726, 288, 265, 614};
PROGMEM prog_uint16_t POUR7[] = {7, 685, 647, 372, 469, 549, 713, 657};
PROGMEM prog_uint16_t POUR6[] = {7, 703, 682, 336, 481, 539, 722, 927};
PROGMEM prog_uint16_t POUR5[] = {7, 706, 646, 372, 451, 567, 706, 645};
PROGMEM prog_uint16_t POUR4[] = {7, 414, 626, 393, 499, 520, 640, 514};
PROGMEM prog_uint16_t SLEEP[] = {7, 816, 204, 812, 204, 813, 515, 512};
PROGMEM prog_uint16_t prepour5[] = {7, 724, 508, 511, 628, 387, 418, 512};
PROGMEM prog_uint16_t Simba 7[] = {7, 499, 356, 661, 667, 346, 193, 614};

PROGMEM transition_t FILLPOURRST1[] = {{0,13} ,{CENTER,500} ,{Fill3,1100} ,{FILL5,1100} ,{Fill6,1100} ,{SIMBA5,1100} ,{Simba6,1100} ,{Simba 7,1100} ,{prepour5,1100} ,{POUR4,1100} ,{POUR5,1100} ,{POUR6,1100} ,{prepour5,1100} ,{SIMBA5,1100} };

#endif
