/* { dg-do compile } */
/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-options "-O2" } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-final { check-function-bodies "**" "" "" } } */

/*
** test:
**...
**	vstrht.16	q[0-9]+, \[(?:ip|fp|r[0-9]+)\]
**...
**	vstrht.16	q[0-9]+, \[(?:ip|fp|r[0-9]+)\]
**...
*/

#define TYPE int16x8_t
#define INTRINSIC vstrhq_s16
#define INTRINSIC_P vstrhq_p_s16

#include "pr108177.x"
