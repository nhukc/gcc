/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
**foo:
**	...
**	vcmp.u32	hi, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vmrs	(?:ip|fp|r[0-9]+), p0(?:	@.*|)
**	...
*/
mve_pred16_t
foo (uint32x4_t a, uint32_t b)
{
  return vcmphiq_n_u32 (a, b);
}


/*
**foo1:
**	...
**	vcmp.u32	hi, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vmrs	(?:ip|fp|r[0-9]+), p0(?:	@.*|)
**	...
*/
mve_pred16_t
foo1 (uint32x4_t a, uint32_t b)
{
  return vcmphiq (a, b);
}

/*
**foo2: { xfail *-*-* }
**	...
**	vcmp.u32	hi, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vmrs	(?:ip|fp|r[0-9]+), p0(?:	@.*|)
**	...
*/
mve_pred16_t
foo2 (uint32x4_t a)
{
  return vcmphiq (a, 1);
}

#ifdef __cplusplus
}
#endif

/* { dg-final { scan-assembler-not "__ARM_undef" } } */