#pragma once

#include "quantum.h"

/*                             _     _     _      _     _     _    _
 *                            |__\  |_\   | \ |  | \   |_\   |_   |_\
 *                            |     |  \  |  \|  |__7  |  \  |__  |  \
 *    .....................................                          .....................................
 *    :     :     :     :     :     :     :                          :     :     :     :     :     :     :
 *    '''''''''''''''''''''''''''''''''''''                          ''''''''''''''''''''''''''''''''''''
 * ,-----------.  ,-----------------------.                          ,-----------------------.  ,-----------.
 * |     |     |  |     |     |     |     |                          |     |     |     |     |  |     |     |
 * |-----------|  |-----------------------|                          |-----------------------|  |-----------|
 * |     |     |  |     |     |     |     |                          |     |     |     |     |  |     |     |
 * |-----------|  |-----------------------|                          |-----------------------|  |-----------|
 * |     |     |  |     |     |     |     |    <<=  =>>  <<=  =>     |     |     |     |     |  |     |     |
 * |-----------|  |-----------------------------------.  .-----------------------------------|  |-----------|
 * |     |     |  |     |     |     |     |     |     |        |     |     |     |     |     |  |     |     |
 * '-----------'  '-----------------------------------'  '-----'-----------------------------'  '-----------'
 *          ,------------------------------.                         ,-----------------------------.
 *          |     |     |     |     |     |                          |     |     |     |     |     |
 *          '-----------------------------'                          '-----------------------------'
 *                :     :     :     :                                      :     :     :     :
 *                '''''''''''''''''''                                      '''''''''''''''''''
 */

#define LAYOUT( \
L4,  L8,L12,L24,L28,L32,                  R4, R8,R12,R24,R28,R32,\
\
L13,L14, L1, L2, L3,L25,                  R1, R2, R3,R25,R13,R14,\
L17,L18, L5, L6, L7,L26,                  R5, R6, R7,R26,R17,R18,\
L33,L34, L9,L10,L11,L27,LCC,LCW, RCC,RCW, R9,R10,R11,R27,R33,R34,\
L37,L38,L21,L22,L23,L29,L30,LEP, REP,R30,R21,R22,R23,R29,R37,R38,\
    L15,L16,L19,L20,L35,                 R15,R16,R19,R20,R35,\
\
        L36,L39,L40,                         R36,R39,R40) { \
\
{ L1, L2, L3, L4,LEP,  L21,L22,L23,  L24,LCC}, \
{ L5, L6, L7, L8,KC_NO,L25,L26,L27,  L28,LCW,}, \
{ L9,L10,L11,L12,KC_NO,L29,L30,KC_NO,L32,KC_NO,}, \
{L13,L14,L15,L16,KC_NO,L33,L34,L35,  L36,KC_NO,}, \
{L17,L18,L19,L20,KC_NO,L37,L38,L39,  L40,KC_NO,}, \
{ R1, R2, R3, R4,REP,  R21,R22,R23,  R24,RCC,}, \
{ R5, R6, R7, R8,KC_NO,R25,R26,R27,  R28,RCW,}, \
{ R9,R10,R11,R12,KC_NO,R29,R30,KC_NO,R32,KC_NO,}, \
{R13,R14,R15,R16,KC_NO,R33,R34,R35,  R36,KC_NO,}, \
{R17,R18,R19,R20,KC_NO,R37,R38,R39,  R40,KC_NO,} \
}
