#ifndef POSES
#define POSES

#include <avr/pgmspace.h>

const PROGMEM uint16_t smell_PLUS45[] = {7, 482, 423, 596, 699, 314, 295, 425};
const PROGMEM uint16_t pour_110[] = {7, 733, 719, 300, 593, 422, 664, 840};
const PROGMEM uint16_t CENTER[] = {7, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t smell_45[] = {7, 475, 434, 586, 746, 267, 191, 637};
const PROGMEM uint16_t fill_wait[] = {7, 212, 678, 338, 503, 513, 690, 514};
const PROGMEM uint16_t pour_0[] = {7, 740, 710, 308, 567, 450, 666, 513};
const PROGMEM uint16_t SLEEP[] = {7, 807, 240, 776, 204, 813, 531, 492};
const PROGMEM uint16_t pour_45[] = {7, 735, 720, 300, 598, 418, 663, 639};
const PROGMEM uint16_t simba_temp[] = {7, 522, 418, 601, 655, 361, 248, 514};
const PROGMEM uint16_t pre_fill[] = {7, 204, 653, 367, 381, 635, 795, 514};
const PROGMEM uint16_t spinnable_fill[] = {7, 242, 491, 529, 303, 713, 708, 512};
const PROGMEM uint16_t spinnable_near_pour[] = {7, 730, 524, 497, 329, 686, 697, 512};
const PROGMEM uint16_t pour_135[] = {7, 721, 696, 322, 602, 413, 634, 983};
const PROGMEM uint16_t spinnable_mid[] = {7, 517, 508, 512, 311, 704, 711, 512};
const PROGMEM uint16_t smell_0[] = {7, 485, 403, 617, 699, 314, 135, 510};

const transition_t rebolt_5[]    = {{0,17} ,{simba_temp,5000} ,{CENTER,5000} ,{spinnable_fill,5000} ,{pre_fill,5000} ,{fill_wait,5000} ,{pre_fill,5000} ,{spinnable_fill,5000} ,{spinnable_mid,5000} ,{spinnable_near_pour,5000} ,{pour_0,5000} ,{pour_45,5000} ,{pour_110,5000} ,{pour_135,5000} ,{pour_45,5000} ,{pour_0,5000} ,{spinnable_near_pour,5000} ,{CENTER,5000} };
const transition_t Dance[]       = {{0,4} ,{CENTER,500} ,{simba_temp,500} ,{simba_temp,500} ,{CENTER,500} };
const transition_t sleep[]       = {{0,2} ,{spinnable_mid,5000} ,{SLEEP,5000} };
const transition_t r5_plu_smell[]= {{0,20} ,{simba_temp,5000} ,{CENTER,5000} ,{spinnable_fill,5000} ,{pre_fill,5000} ,{fill_wait,5000} ,{pre_fill,5000} ,{spinnable_fill,5000} ,{spinnable_mid,5000} ,{smell_0,5000} ,{smell_45,5000} ,{smell_PLUS45,5000} ,{spinnable_near_pour,5000} ,{pour_0,5000} ,{pour_45,5000} ,{pour_110,5000} ,{pour_135,5000} ,{pour_45,5000} ,{pour_0,5000} ,{spinnable_near_pour,5000} ,{CENTER,5000} };

#endif

