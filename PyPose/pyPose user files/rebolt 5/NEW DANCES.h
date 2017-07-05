#ifndef REBOLT-R5_POSES
#define REBOLT-R5_POSES

#include <avr/pgmspace.h>

PROGMEM prog_uint16_t smell_Plus_45[] = {7, 482, 423, 596, 699, 314, 295, 425};
PROGMEM prog_uint16_t dance_4[] = {7, 389, 762, 253, 828, 188, 777, 1023};
PROGMEM prog_uint16_t fill_wait[] = {7, 212, 678, 338, 503, 513, 690, 514};
PROGMEM prog_uint16_t dance_2[] = {7, 493, 596, 423, 743, 272, 726, 502};
PROGMEM prog_uint16_t dance_1[] = {7, 356, 333, 684, 462, 556, 203, 501};
PROGMEM prog_uint16_t dance_0[] = {7, 625, 383, 635, 353, 663, 663, 501};
PROGMEM prog_uint16_t spinnable_fill[] = {7, 242, 491, 529, 303, 713, 708, 512};
PROGMEM prog_uint16_t CENTER[] = {7, 512, 512, 512, 512, 512, 512, 512};
PROGMEM prog_uint16_t spinnable_mid[] = {7, 517, 508, 512, 311, 704, 711, 512};
PROGMEM prog_uint16_t dance_3[] = {7, 709, 782, 234, 905, 113, 725, 0};
PROGMEM prog_uint16_t smell_0[] = {7, 485, 403, 617, 699, 314, 135, 510};
PROGMEM prog_uint16_t pour_110[] = {7, 733, 719, 300, 593, 422, 664, 840};
PROGMEM prog_uint16_t pour_135[] = {7, 721, 696, 322, 602, 413, 634, 983};
PROGMEM prog_uint16_t smell_Minus45[] = {7, 475, 434, 586, 746, 267, 191, 637};
PROGMEM prog_uint16_t simba_temp[] = {7, 522, 418, 601, 655, 361, 248, 514};
PROGMEM prog_uint16_t spinnable_near_pour[] = {7, 730, 524, 497, 329, 686, 697, 512};
PROGMEM prog_uint16_t pre_fill[] = {7, 204, 653, 367, 381, 635, 795, 514};
PROGMEM prog_uint16_t pour_0[] = {7, 740, 710, 308, 567, 450, 666, 513};
PROGMEM prog_uint16_t SLEEP[] = {7, 807, 240, 776, 204, 813, 531, 492};
PROGMEM prog_uint16_t pour_45[] = {7, 735, 720, 300, 598, 418, 663, 639};
PROGMEM prog_uint16_t dance_b_2[] = {7, 595, 362, 656, 353, 664, 621, 514};
PROGMEM prog_uint16_t dance_b_3[] = {7, 428, 415, 605, 560, 457, 305, 514};
PROGMEM prog_uint16_t dance_b_0[] = {7, 505, 201, 818, 205, 810, 390, 503};
PROGMEM prog_uint16_t dance_b_1[] = {7, 439, 201, 818, 314, 700, 301, 514};
PROGMEM prog_uint16_t dance_b_4[] = {7, 620, 508, 511, 906, 113, 212, 514};
PROGMEM prog_uint16_t dance_b_5[] = {7, 457, 489, 531, 896, 122, 135, 514};

PROGMEM transition_t r5-plu-smell[] = {{0,20} ,{simba-temp,5000} ,{CENTER,5000} ,{spinnable-fill,5000} ,{pre-fill,5000} ,{fill-wait,5000} ,{pre-fill,5000} ,{spinnable-fill,5000} ,{spinnable-mid,5000} ,{smell-0,5000} ,{smell--45,5000} ,{smell-+45,5000} ,{spinnable-near-pour,5000} ,{pour-0,5000} ,{pour-45,5000} ,{pour-110,5000} ,{pour-135,5000} ,{pour-45,5000} ,{pour-0,5000} ,{spinnable-near-pour,5000} ,{CENTER,5000} };
PROGMEM transition_t Dance[] = {{0,4} ,{CENTER,5000} ,{simba-temp,5000} ,{simba-temp,5000} ,{CENTER,5000} };
PROGMEM transition_t dance_b[] = {{0,11} ,{dance_b_0,1555} ,{dance_b_1,1555} ,{dance_b_2,1555} ,{dance_b_3,1555} ,{dance_b_4,1555} ,{dance_b_5,1555} ,{dance_b_4,1555} ,{dance_b_3,1555} ,{dance_b_2,1555} ,{dance_b_1,1555} ,{dance_b_0,1555} };
PROGMEM transition_t dance_a[] = {{0,6} ,{dance_2,1500} ,{dance_0,1500} ,{dance_1,3500} ,{dance_3,3500} ,{dance_0,3500} ,{dance_4,3500} };
PROGMEM transition_t rebolt-5[] = {{0,17} ,{simba-temp,5000} ,{CENTER,5000} ,{spinnable-fill,5000} ,{pre-fill,5000} ,{fill-wait,5000} ,{pre-fill,5000} ,{spinnable-fill,5000} ,{spinnable-mid,5000} ,{spinnable-near-pour,5000} ,{pour-0,5000} ,{pour-45,5000} ,{pour-110,5000} ,{pour-135,5000} ,{pour-45,5000} ,{pour-0,5000} ,{spinnable-near-pour,5000} ,{CENTER,5000} };
PROGMEM transition_t sleep[] = {{0,2} ,{spinnable-mid,5000} ,{SLEEP,5000} };

#endif
