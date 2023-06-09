/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** sub_s32_m_tied1:
**	sub	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (sub_s32_m_tied1, svint32_t,
		z0 = svsub_s32_m (p0, z0, z1),
		z0 = svsub_m (p0, z0, z1))

/*
** sub_s32_m_tied2:
**	mov	(z[0-9]+)\.d, z0\.d
**	movprfx	z0, z1
**	sub	z0\.s, p0/m, z0\.s, \1\.s
**	ret
*/
TEST_UNIFORM_Z (sub_s32_m_tied2, svint32_t,
		z0 = svsub_s32_m (p0, z1, z0),
		z0 = svsub_m (p0, z1, z0))

/*
** sub_s32_m_untied:
**	movprfx	z0, z1
**	sub	z0\.s, p0/m, z0\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (sub_s32_m_untied, svint32_t,
		z0 = svsub_s32_m (p0, z1, z2),
		z0 = svsub_m (p0, z1, z2))

/*
** sub_w0_s32_m_tied1:
**	mov	(z[0-9]+\.s), w0
**	sub	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZX (sub_w0_s32_m_tied1, svint32_t, int32_t,
		 z0 = svsub_n_s32_m (p0, z0, x0),
		 z0 = svsub_m (p0, z0, x0))

/*
** sub_w0_s32_m_untied:
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0, z1
**	sub	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZX (sub_w0_s32_m_untied, svint32_t, int32_t,
		 z0 = svsub_n_s32_m (p0, z1, x0),
		 z0 = svsub_m (p0, z1, x0))

/*
** sub_1_s32_m_tied1:
**	mov	(z[0-9]+)\.b, #-1
**	add	z0\.s, p0/m, z0\.s, \1\.s
**	ret
*/
TEST_UNIFORM_Z (sub_1_s32_m_tied1, svint32_t,
		z0 = svsub_n_s32_m (p0, z0, 1),
		z0 = svsub_m (p0, z0, 1))

/*
** sub_1_s32_m_untied:
**	mov	(z[0-9]+)\.b, #-1
**	movprfx	z0, z1
**	add	z0\.s, p0/m, z0\.s, \1\.s
**	ret
*/
TEST_UNIFORM_Z (sub_1_s32_m_untied, svint32_t,
		z0 = svsub_n_s32_m (p0, z1, 1),
		z0 = svsub_m (p0, z1, 1))

/*
** sub_m2_s32_m:
**	mov	(z[0-9]+\.s), #2
**	add	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (sub_m2_s32_m, svint32_t,
		z0 = svsub_n_s32_m (p0, z0, -2),
		z0 = svsub_m (p0, z0, -2))

/*
** sub_s32_z_tied1:
**	movprfx	z0\.s, p0/z, z0\.s
**	sub	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (sub_s32_z_tied1, svint32_t,
		z0 = svsub_s32_z (p0, z0, z1),
		z0 = svsub_z (p0, z0, z1))

/*
** sub_s32_z_tied2:
**	movprfx	z0\.s, p0/z, z0\.s
**	subr	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (sub_s32_z_tied2, svint32_t,
		z0 = svsub_s32_z (p0, z1, z0),
		z0 = svsub_z (p0, z1, z0))

/*
** sub_s32_z_untied:
** (
**	movprfx	z0\.s, p0/z, z1\.s
**	sub	z0\.s, p0/m, z0\.s, z2\.s
** |
**	movprfx	z0\.s, p0/z, z2\.s
**	subr	z0\.s, p0/m, z0\.s, z1\.s
** )
**	ret
*/
TEST_UNIFORM_Z (sub_s32_z_untied, svint32_t,
		z0 = svsub_s32_z (p0, z1, z2),
		z0 = svsub_z (p0, z1, z2))

/*
** sub_w0_s32_z_tied1:
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0\.s, p0/z, z0\.s
**	sub	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZX (sub_w0_s32_z_tied1, svint32_t, int32_t,
		 z0 = svsub_n_s32_z (p0, z0, x0),
		 z0 = svsub_z (p0, z0, x0))

/*
** sub_w0_s32_z_untied:
**	mov	(z[0-9]+\.s), w0
** (
**	movprfx	z0\.s, p0/z, z1\.s
**	sub	z0\.s, p0/m, z0\.s, \1
** |
**	movprfx	z0\.s, p0/z, \1
**	subr	z0\.s, p0/m, z0\.s, z1\.s
** )
**	ret
*/
TEST_UNIFORM_ZX (sub_w0_s32_z_untied, svint32_t, int32_t,
		 z0 = svsub_n_s32_z (p0, z1, x0),
		 z0 = svsub_z (p0, z1, x0))

/*
** sub_1_s32_z_tied1:
**	mov	(z[0-9]+)\.b, #-1
**	movprfx	z0\.s, p0/z, z0\.s
**	add	z0\.s, p0/m, z0\.s, \1\.s
**	ret
*/
TEST_UNIFORM_Z (sub_1_s32_z_tied1, svint32_t,
		z0 = svsub_n_s32_z (p0, z0, 1),
		z0 = svsub_z (p0, z0, 1))

/*
** sub_1_s32_z_untied:
**	mov	(z[0-9]+)\.b, #-1
** (
**	movprfx	z0\.s, p0/z, z1\.s
**	add	z0\.s, p0/m, z0\.s, \1\.s
** |
**	movprfx	z0\.s, p0/z, \1\.s
**	add	z0\.s, p0/m, z0\.s, z1\.s
** )
**	ret
*/
TEST_UNIFORM_Z (sub_1_s32_z_untied, svint32_t,
		z0 = svsub_n_s32_z (p0, z1, 1),
		z0 = svsub_z (p0, z1, 1))

/*
** sub_s32_x_tied1:
**	sub	z0\.s, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (sub_s32_x_tied1, svint32_t,
		z0 = svsub_s32_x (p0, z0, z1),
		z0 = svsub_x (p0, z0, z1))

/*
** sub_s32_x_tied2:
**	sub	z0\.s, z1\.s, z0\.s
**	ret
*/
TEST_UNIFORM_Z (sub_s32_x_tied2, svint32_t,
		z0 = svsub_s32_x (p0, z1, z0),
		z0 = svsub_x (p0, z1, z0))

/*
** sub_s32_x_untied:
**	sub	z0\.s, z1\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (sub_s32_x_untied, svint32_t,
		z0 = svsub_s32_x (p0, z1, z2),
		z0 = svsub_x (p0, z1, z2))

/*
** sub_w0_s32_x_tied1:
**	mov	(z[0-9]+\.s), w0
**	sub	z0\.s, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZX (sub_w0_s32_x_tied1, svint32_t, int32_t,
		 z0 = svsub_n_s32_x (p0, z0, x0),
		 z0 = svsub_x (p0, z0, x0))

/*
** sub_w0_s32_x_untied:
**	mov	(z[0-9]+\.s), w0
**	sub	z0\.s, z1\.s, \1
**	ret
*/
TEST_UNIFORM_ZX (sub_w0_s32_x_untied, svint32_t, int32_t,
		 z0 = svsub_n_s32_x (p0, z1, x0),
		 z0 = svsub_x (p0, z1, x0))

/*
** sub_1_s32_x_tied1:
**	sub	z0\.s, z0\.s, #1
**	ret
*/
TEST_UNIFORM_Z (sub_1_s32_x_tied1, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, 1),
		z0 = svsub_x (p0, z0, 1))

/*
** sub_1_s32_x_untied:
**	movprfx	z0, z1
**	sub	z0\.s, z0\.s, #1
**	ret
*/
TEST_UNIFORM_Z (sub_1_s32_x_untied, svint32_t,
		z0 = svsub_n_s32_x (p0, z1, 1),
		z0 = svsub_x (p0, z1, 1))

/*
** sub_127_s32_x:
**	sub	z0\.s, z0\.s, #127
**	ret
*/
TEST_UNIFORM_Z (sub_127_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, 127),
		z0 = svsub_x (p0, z0, 127))

/*
** sub_128_s32_x:
**	sub	z0\.s, z0\.s, #128
**	ret
*/
TEST_UNIFORM_Z (sub_128_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, 128),
		z0 = svsub_x (p0, z0, 128))

/*
** sub_255_s32_x:
**	sub	z0\.s, z0\.s, #255
**	ret
*/
TEST_UNIFORM_Z (sub_255_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, 255),
		z0 = svsub_x (p0, z0, 255))

/*
** sub_256_s32_x:
**	sub	z0\.s, z0\.s, #256
**	ret
*/
TEST_UNIFORM_Z (sub_256_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, 256),
		z0 = svsub_x (p0, z0, 256))

/*
** sub_511_s32_x:
**	mov	(z[0-9]+\.s), #-511
**	add	z0\.s, (z0\.s, \1|\1, z0\.s)
**	ret
*/
TEST_UNIFORM_Z (sub_511_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, 511),
		z0 = svsub_x (p0, z0, 511))

/*
** sub_512_s32_x:
**	sub	z0\.s, z0\.s, #512
**	ret
*/
TEST_UNIFORM_Z (sub_512_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, 512),
		z0 = svsub_x (p0, z0, 512))

/*
** sub_65280_s32_x:
**	sub	z0\.s, z0\.s, #65280
**	ret
*/
TEST_UNIFORM_Z (sub_65280_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, 0xff00),
		z0 = svsub_x (p0, z0, 0xff00))

/*
** sub_65535_s32_x:
**	mov	(z[0-9]+\.s), #-65535
**	add	z0\.s, (z0\.s, \1|\1, z0\.s)
**	ret
*/
TEST_UNIFORM_Z (sub_65535_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, 65535),
		z0 = svsub_x (p0, z0, 65535))

/*
** sub_65536_s32_x:
**	mov	(z[0-9]+\.s), #-65536
**	add	z0\.s, (z0\.s, \1|\1, z0\.s)
**	ret
*/
TEST_UNIFORM_Z (sub_65536_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, 65536),
		z0 = svsub_x (p0, z0, 65536))

/*
** sub_m1_s32_x:
**	add	z0\.s, z0\.s, #1
**	ret
*/
TEST_UNIFORM_Z (sub_m1_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -1),
		z0 = svsub_x (p0, z0, -1))

/*
** sub_m127_s32_x:
**	add	z0\.s, z0\.s, #127
**	ret
*/
TEST_UNIFORM_Z (sub_m127_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -127),
		z0 = svsub_x (p0, z0, -127))

/*
** sub_m128_s32_x:
**	add	z0\.s, z0\.s, #128
**	ret
*/
TEST_UNIFORM_Z (sub_m128_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -128),
		z0 = svsub_x (p0, z0, -128))

/*
** sub_m255_s32_x:
**	add	z0\.s, z0\.s, #255
**	ret
*/
TEST_UNIFORM_Z (sub_m255_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -255),
		z0 = svsub_x (p0, z0, -255))

/*
** sub_m256_s32_x:
**	add	z0\.s, z0\.s, #256
**	ret
*/
TEST_UNIFORM_Z (sub_m256_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -256),
		z0 = svsub_x (p0, z0, -256))

/*
** sub_m511_s32_x:
**	mov	(z[0-9]+\.s), #511
**	add	z0\.s, (z0\.s, \1|\1, z0\.s)
**	ret
*/
TEST_UNIFORM_Z (sub_m511_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -511),
		z0 = svsub_x (p0, z0, -511))

/*
** sub_m512_s32_x:
**	add	z0\.s, z0\.s, #512
**	ret
*/
TEST_UNIFORM_Z (sub_m512_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -512),
		z0 = svsub_x (p0, z0, -512))

/*
** sub_m32768_s32_x:
**	add	z0\.s, z0\.s, #32768
**	ret
*/
TEST_UNIFORM_Z (sub_m32768_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -0x8000),
		z0 = svsub_x (p0, z0, -0x8000))

/*
** sub_m65280_s32_x:
**	add	z0\.s, z0\.s, #65280
**	ret
*/
TEST_UNIFORM_Z (sub_m65280_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -0xff00),
		z0 = svsub_x (p0, z0, -0xff00))

/*
** sub_m65535_s32_x:
**	mov	(z[0-9]+\.s), #65535
**	add	z0\.s, (z0\.s, \1|\1, z0\.s)
**	ret
*/
TEST_UNIFORM_Z (sub_m65535_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -65535),
		z0 = svsub_x (p0, z0, -65535))

/*
** sub_m65536_s32_x:
**	mov	(z[0-9]+\.s), #65536
**	add	z0\.s, (z0\.s, \1|\1, z0\.s)
**	ret
*/
TEST_UNIFORM_Z (sub_m65536_s32_x, svint32_t,
		z0 = svsub_n_s32_x (p0, z0, -65536),
		z0 = svsub_x (p0, z0, -65536))
