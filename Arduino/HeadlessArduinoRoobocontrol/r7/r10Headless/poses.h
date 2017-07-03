#ifndef REBOLT_R5_POSES
#define REBOLT_R5_POSES
#define VELOCITY 2500
#define SLOW_VELOCITY 5000

#include <avr/pgmspace.h>

PROGMEM prog_uint16_t smell_PLUS45[] = {7, 482, 423, 596, 699, 314, 295, 425};
PROGMEM prog_uint16_t pour_110[] = {7, 733, 719, 300, 593, 422, 664, 840};
PROGMEM prog_uint16_t CENTER[] = {7, 512, 512, 512, 512, 512, 512, 512};
PROGMEM prog_uint16_t smell_45[] = {7, 475, 434, 586, 746, 267, 191, 637};
PROGMEM prog_uint16_t fill_wait[] = {7, 212, 678, 338, 503, 513, 690, 514};
PROGMEM prog_uint16_t pour_0[] = {7, 740, 710, 308, 567, 450, 666, 513};
PROGMEM prog_uint16_t SLEEP[] = {7, 807, 240, 776, 204, 813, 531, 492};
PROGMEM prog_uint16_t pour_45[] = {7, 735, 720, 300, 598, 418, 663, 639};
PROGMEM prog_uint16_t simba_temp[] = {7, 522, 418, 601, 655, 361, 248, 514};
PROGMEM prog_uint16_t pre_fill[] = {7, 204, 653, 367, 381, 635, 795, 514};
PROGMEM prog_uint16_t spinnable_fill[] = {7, 242, 491, 529, 303, 713, 708, 512};
PROGMEM prog_uint16_t spinnable_near_pour[] = {7, 730, 524, 497, 329, 686, 697, 512};
PROGMEM prog_uint16_t pour_135[] = {7, 721, 696, 322, 602, 413, 634, 983};
PROGMEM prog_uint16_t spinnable_mid[] = {7, 517, 508, 512, 311, 704, 711, 512};
PROGMEM prog_uint16_t smell_0[] = {7, 485, 403, 617, 699, 314, 135, 510};

// PROGMEM transition_t rebolt_5[] = {{0,17} ,{simba_temp,VELOCITY} ,{CENTER,VELOCITY} ,{spinnable_fill,SLOW_VELOCITY} ,{pre_fill,SLOW_VELOCITY} ,{fill_wait,VELOCITY} ,{pre_fill,VELOCITY} ,{spinnable_fill,VELOCITY} ,{spinnable_mid,VELOCITY} ,{spinnable_near_pour,VELOCITY} ,{pour_0,VELOCITY} ,{pour_45,VELOCITY} ,{pour_110,VELOCITY} ,{pour_135,VELOCITY} ,{pour_45,VELOCITY} ,{pour_0,VELOCITY} ,{spinnable_near_pour,VELOCITY} ,{CENTER,VELOCITY} };
PROGMEM transition_t Dance[] = {{0,4} ,{CENTER,500} ,{simba_temp,500} ,{simba_temp,500} ,{CENTER,500} };
PROGMEM transition_t sleep[] = {{0,2} ,{spinnable_mid,SLOW_VELOCITY} ,{SLEEP,VELOCITY} };
//PROGMEM transition_t r5_plu_smell[] = {{0,20} ,{simba_temp,VELOCITY} ,{CENTER,VELOCITY} ,{spinnable_fill,VELOCITY} ,{pre_fill,VELOCITY} ,{fill_wait,VELOCITY} ,{pre_fill,VELOCITY} ,{spinnable_fill,VELOCITY} ,{spinnable_mid,VELOCITY} ,{smell_0,VELOCITY} ,{smell_45,VELOCITY} ,{smell_PLUS45,VELOCITY} ,{spinnable_near_pour,VELOCITY} ,{pour_0,VELOCITY} ,{pour_45,VELOCITY} ,{pour_110,VELOCITY} ,{pour_135,VELOCITY} ,{pour_45,VELOCITY} ,{pour_0,VELOCITY} ,{spinnable_near_pour,VELOCITY} ,{CENTER,VELOCITY} };

PROGMEM transition_t toFill[] = {{0,5}  ,{CENTER,VELOCITY} ,{simba_temp,VELOCITY},{spinnable_fill,SLOW_VELOCITY} ,{pre_fill,SLOW_VELOCITY} ,{fill_wait,SLOW_VELOCITY} };
PROGMEM transition_t toPour[] = {{0,15},{fill_wait,SLOW_VELOCITY},{pre_fill,SLOW_VELOCITY},{spinnable_fill,SLOW_VELOCITY},{spinnable_mid,SLOW_VELOCITY},{smell_0,SLOW_VELOCITY},{smell_45,VELOCITY},{smell_PLUS45,VELOCITY},{spinnable_near_pour,VELOCITY},{pour_0,VELOCITY},{pour_45,VELOCITY},{pour_110,VELOCITY},{pour_135,VELOCITY},{pour_45,VELOCITY},{pour_0,VELOCITY},{spinnable_near_pour,VELOCITY},{CENTER,VELOCITY}};

#endif

