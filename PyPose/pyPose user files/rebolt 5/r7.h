#ifndef REBOLT-R5_POSES
#define REBOLT-R5_POSES

#include <avr/pgmspace.h>

PROGMEM prog_uint16_t smell-+45[] = {7, 482, 423, 596, 699, 314, 295, 425};
PROGMEM prog_uint16_t pour-110[] = {7, 733, 719, 300, 593, 422, 664, 840};
PROGMEM prog_uint16_t CENTER[] = {7, 512, 512, 512, 512, 512, 512, 512};
PROGMEM prog_uint16_t smell--45[] = {7, 475, 434, 586, 746, 267, 191, 637};
PROGMEM prog_uint16_t fill-wait[] = {7, 212, 678, 338, 503, 513, 690, 514};
PROGMEM prog_uint16_t pour-0[] = {7, 740, 710, 308, 567, 450, 666, 513};
PROGMEM prog_uint16_t SLEEP[] = {7, 807, 240, 776, 204, 813, 531, 492};
PROGMEM prog_uint16_t pour-45[] = {7, 735, 720, 300, 598, 418, 663, 639};
PROGMEM prog_uint16_t simba-temp[] = {7, 522, 418, 601, 655, 361, 248, 514};
PROGMEM prog_uint16_t pre-fill[] = {7, 204, 653, 367, 381, 635, 795, 514};
PROGMEM prog_uint16_t spinnable-fill[] = {7, 242, 491, 529, 303, 713, 708, 512};
PROGMEM prog_uint16_t spinnable-near-pour[] = {7, 730, 524, 497, 329, 686, 697, 512};
PROGMEM prog_uint16_t pour-135[] = {7, 721, 696, 322, 602, 413, 634, 983};
PROGMEM prog_uint16_t spinnable-mid[] = {7, 517, 508, 512, 311, 704, 711, 512};
PROGMEM prog_uint16_t smell-0[] = {7, 485, 403, 617, 699, 314, 135, 510};

PROGMEM transition_t rebolt-5[] = {{0,17} ,{simba-temp,5000} ,{CENTER,5000} ,{spinnable-fill,5000} ,{pre-fill,5000} ,{fill-wait,5000} ,{pre-fill,5000} ,{spinnable-fill,5000} ,{spinnable-mid,5000} ,{spinnable-near-pour,5000} ,{pour-0,5000} ,{pour-45,5000} ,{pour-110,5000} ,{pour-135,5000} ,{pour-45,5000} ,{pour-0,5000} ,{spinnable-near-pour,5000} ,{CENTER,5000} };
PROGMEM transition_t Dance[] = {{0,4} ,{CENTER,500} ,{simba-temp,500} ,{simba-temp,500} ,{CENTER,500} };
PROGMEM transition_t sleep[] = {{0,2} ,{spinnable-mid,5000} ,{SLEEP,5000} };
PROGMEM transition_t r5-plu-smell[] = {{0,20} ,{simba-temp,5000} ,{CENTER,5000} ,{spinnable-fill,5000} ,{pre-fill,5000} ,{fill-wait,5000} ,{pre-fill,5000} ,{spinnable-fill,5000} ,{spinnable-mid,5000} ,{smell-0,5000} ,{smell--45,5000} ,{smell-+45,5000} ,{spinnable-near-pour,5000} ,{pour-0,5000} ,{pour-45,5000} ,{pour-110,5000} ,{pour-135,5000} ,{pour-45,5000} ,{pour-0,5000} ,{spinnable-near-pour,5000} ,{CENTER,5000} };

#endif
