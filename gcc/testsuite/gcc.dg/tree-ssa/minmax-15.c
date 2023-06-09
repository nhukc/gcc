/* { dg-do run } */
/* { dg-options "-O -fdump-tree-phiopt" } */

#include <stdint.h>
#include <stdbool.h>

__attribute__ ((noinline, noipa))
uint8_t three_min (uint8_t xc, uint8_t xm, uint8_t xy) {
    uint8_t  xk;
    if (xc)
      {
        if (xc < xm) {
            xk = (uint8_t) (xc < xy ? xc : xy);
        } else {
            xk = (uint8_t) (xm < xy ? xm : xy);
        }
      }

    return xk;
}

int
main (void)
{
  volatile uint8_t xy = 255;
  volatile uint8_t xm = 0;
  volatile uint8_t xc = 127;
  if (three_min (xc, xm, xy) != 0)
    __builtin_abort ();
  return 0;
}

/* There should only be two MIN_EXPR left, the 3rd one was removed. */
/* { dg-final { scan-tree-dump-times "MIN_EXPR" 2 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times "MAX_EXPR" 0 "phiopt1" } } */
