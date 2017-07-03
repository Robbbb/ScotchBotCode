#ifndef 008_POSES
#define 008_POSES

#include <avr/pgmspace.h>

PROGMEM prog_uint16_t p2[] = {7, 375, 555, 464, 471, 548, 598, 580};
PROGMEM prog_uint16_t dry[] = {7, 0, 427, 590, 900, 117, 660, 497};
PROGMEM prog_uint16_t p1[] = {7, 368, 552, 467, 474, 544, 601, 568};
PROGMEM prog_uint16_t pshake[] = {7, 342, 600, 418, 471, 547, 637, 963};
PROGMEM prog_uint16_t for[] = {7, 492, 479, 539, 495, 523, 494, 520};
PROGMEM prog_uint16_t rest[] = {7, 508, 249, 766, 352, 665, 414, 520};
PROGMEM prog_uint16_t pp3[] = {7, 403, 534, 485, 587, 431, 463, 525};
PROGMEM prog_uint16_t pp2[] = {7, 277, 525, 493, 490, 527, 561, 525};
PROGMEM prog_uint16_t pfull[] = {7, 348, 580, 438, 474, 544, 622, 879};
PROGMEM prog_uint16_t pre dry[] = {7, 352, 473, 546, 640, 376, 354, 496};
PROGMEM prog_uint16_t dry3[] = {7, 656, 404, 613, 905, 113, 613, 499};
PROGMEM prog_uint16_t prepour[] = {7, 281, 189, 826, 543, 478, 185, 523};
PROGMEM prog_uint16_t pp4[] = {7, 374, 554, 465, 472, 546, 606, 525};
PROGMEM prog_uint16_t dry2[] = {7, 348, 422, 595, 898, 118, 679, 496};
PROGMEM prog_uint16_t pre-fill[] = {7, 704, 602, 415, 587, 428, 508, 393};
PROGMEM prog_uint16_t pdrop[] = {7, 342, 547, 472, 472, 546, 588, 964};
PROGMEM prog_uint16_t smell2[] = {7, 466, 474, 545, 586, 430, 373, 440};
PROGMEM prog_uint16_t smell[] = {7, 489, 486, 533, 601, 414, 408, 586};
PROGMEM prog_uint16_t smell3[] = {7, 444, 515, 503, 503, 513, 611, 538};
PROGMEM prog_uint16_t fill[] = {7, 704, 597, 421, 575, 441, 540, 455};

PROGMEM transition_t seq1[] = {{0,16} ,{rest,500} ,{pre-fill,1500} ,{fill,1500} ,{smell,500} ,{smell2,500} ,{smell3,500} ,{prepour,500} ,{pp2,500} ,{pp3,500} ,{pp4,500} ,{pdrop,500} ,{pre dry,500} ,{dry,500} ,{dry2,500} ,{dry3,500} ,{rest,500} };

#endif
