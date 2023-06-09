/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** and_u16_m_tied1:
**	and	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (and_u16_m_tied1, svuint16_t,
		z0 = svand_u16_m (p0, z0, z1),
		z0 = svand_m (p0, z0, z1))

/*
** and_u16_m_tied2:
**	mov	(z[0-9]+)\.d, z0\.d
**	movprfx	z0, z1
**	and	z0\.h, p0/m, z0\.h, \1\.h
**	ret
*/
TEST_UNIFORM_Z (and_u16_m_tied2, svuint16_t,
		z0 = svand_u16_m (p0, z1, z0),
		z0 = svand_m (p0, z1, z0))

/*
** and_u16_m_untied:
**	movprfx	z0, z1
**	and	z0\.h, p0/m, z0\.h, z2\.h
**	ret
*/
TEST_UNIFORM_Z (and_u16_m_untied, svuint16_t,
		z0 = svand_u16_m (p0, z1, z2),
		z0 = svand_m (p0, z1, z2))

/*
** and_w0_u16_m_tied1:
**	mov	(z[0-9]+\.h), w0
**	and	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZX (and_w0_u16_m_tied1, svuint16_t, uint16_t,
		 z0 = svand_n_u16_m (p0, z0, x0),
		 z0 = svand_m (p0, z0, x0))

/*
** and_w0_u16_m_untied:
**	mov	(z[0-9]+\.h), w0
**	movprfx	z0, z1
**	and	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZX (and_w0_u16_m_untied, svuint16_t, uint16_t,
		 z0 = svand_n_u16_m (p0, z1, x0),
		 z0 = svand_m (p0, z1, x0))

/*
** and_1_u16_m_tied1:
**	mov	(z[0-9]+\.h), #1
**	and	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (and_1_u16_m_tied1, svuint16_t,
		z0 = svand_n_u16_m (p0, z0, 1),
		z0 = svand_m (p0, z0, 1))

/*
** and_1_u16_m_untied:
**	mov	(z[0-9]+\.h), #1
**	movprfx	z0, z1
**	and	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (and_1_u16_m_untied, svuint16_t,
		z0 = svand_n_u16_m (p0, z1, 1),
		z0 = svand_m (p0, z1, 1))

/*
** and_m2_u16_m:
**	mov	(z[0-9]+\.h), #-2
**	and	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (and_m2_u16_m, svuint16_t,
		z0 = svand_n_u16_m (p0, z0, -2),
		z0 = svand_m (p0, z0, -2))

/*
** and_255_u16_m_tied1:
**	uxtb	z0\.h, p0/m, z0\.h
**	ret
*/
TEST_UNIFORM_Z (and_255_u16_m_tied1, svuint16_t,
		z0 = svand_n_u16_m (p0, z0, 255),
		z0 = svand_m (p0, z0, 255))

/*
** and_255_u16_m_untied:
**	movprfx	z0, z1
**	uxtb	z0\.h, p0/m, z1\.h
**	ret
*/
TEST_UNIFORM_Z (and_255_u16_m_untied, svuint16_t,
		z0 = svand_n_u16_m (p0, z1, 255),
		z0 = svand_m (p0, z1, 255))

/*
** and_u16_z_tied1:
**	movprfx	z0\.h, p0/z, z0\.h
**	and	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (and_u16_z_tied1, svuint16_t,
		z0 = svand_u16_z (p0, z0, z1),
		z0 = svand_z (p0, z0, z1))

/*
** and_u16_z_tied2:
**	movprfx	z0\.h, p0/z, z0\.h
**	and	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (and_u16_z_tied2, svuint16_t,
		z0 = svand_u16_z (p0, z1, z0),
		z0 = svand_z (p0, z1, z0))

/*
** and_u16_z_untied:
** (
**	movprfx	z0\.h, p0/z, z1\.h
**	and	z0\.h, p0/m, z0\.h, z2\.h
** |
**	movprfx	z0\.h, p0/z, z2\.h
**	and	z0\.h, p0/m, z0\.h, z1\.h
** )
**	ret
*/
TEST_UNIFORM_Z (and_u16_z_untied, svuint16_t,
		z0 = svand_u16_z (p0, z1, z2),
		z0 = svand_z (p0, z1, z2))

/*
** and_w0_u16_z_tied1:
**	mov	(z[0-9]+\.h), w0
**	movprfx	z0\.h, p0/z, z0\.h
**	and	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZX (and_w0_u16_z_tied1, svuint16_t, uint16_t,
		 z0 = svand_n_u16_z (p0, z0, x0),
		 z0 = svand_z (p0, z0, x0))

/*
** and_w0_u16_z_untied:
**	mov	(z[0-9]+\.h), w0
** (
**	movprfx	z0\.h, p0/z, z1\.h
**	and	z0\.h, p0/m, z0\.h, \1
** |
**	movprfx	z0\.h, p0/z, \1
**	and	z0\.h, p0/m, z0\.h, z1\.h
** )
**	ret
*/
TEST_UNIFORM_ZX (and_w0_u16_z_untied, svuint16_t, uint16_t,
		 z0 = svand_n_u16_z (p0, z1, x0),
		 z0 = svand_z (p0, z1, x0))

/*
** and_1_u16_z_tied1:
**	mov	(z[0-9]+\.h), #1
**	movprfx	z0\.h, p0/z, z0\.h
**	and	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (and_1_u16_z_tied1, svuint16_t,
		z0 = svand_n_u16_z (p0, z0, 1),
		z0 = svand_z (p0, z0, 1))

/*
** and_1_u16_z_untied:
**	mov	(z[0-9]+\.h), #1
** (
**	movprfx	z0\.h, p0/z, z1\.h
**	and	z0\.h, p0/m, z0\.h, \1
** |
**	movprfx	z0\.h, p0/z, \1
**	and	z0\.h, p0/m, z0\.h, z1\.h
** )
**	ret
*/
TEST_UNIFORM_Z (and_1_u16_z_untied, svuint16_t,
		z0 = svand_n_u16_z (p0, z1, 1),
		z0 = svand_z (p0, z1, 1))

/*
** and_255_u16_z_tied1:
** (
**	mov	(z[0-9]+)\.d, z0\.d
**	movprfx	z0\.h, p0/z, \1\.h
**	uxtb	z0\.h, p0/m, \1\.h
** |
**	mov	(z[0-9]+\.h), #255
**	movprfx	z0\.h, p0/z, z0\.h
**	and	z0\.h, p0/m, z0\.h, \1
** )
**	ret
*/
TEST_UNIFORM_Z (and_255_u16_z_tied1, svuint16_t,
		z0 = svand_n_u16_z (p0, z0, 255),
		z0 = svand_z (p0, z0, 255))

/*
** and_255_u16_z_untied:
**	movprfx	z0\.h, p0/z, z1\.h
**	uxtb	z0\.h, p0/m, z1\.h
**	ret
*/
TEST_UNIFORM_Z (and_255_u16_z_untied, svuint16_t,
		z0 = svand_n_u16_z (p0, z1, 255),
		z0 = svand_z (p0, z1, 255))

/*
** and_u16_x_tied1:
**	and	z0\.d, (z0\.d, z1\.d|z1\.d, z0\.d)
**	ret
*/
TEST_UNIFORM_Z (and_u16_x_tied1, svuint16_t,
		z0 = svand_u16_x (p0, z0, z1),
		z0 = svand_x (p0, z0, z1))

/*
** and_u16_x_tied2:
**	and	z0\.d, (z0\.d, z1\.d|z1\.d, z0\.d)
**	ret
*/
TEST_UNIFORM_Z (and_u16_x_tied2, svuint16_t,
		z0 = svand_u16_x (p0, z1, z0),
		z0 = svand_x (p0, z1, z0))

/*
** and_u16_x_untied:
**	and	z0\.d, (z1\.d, z2\.d|z2\.d, z1\.d)
**	ret
*/
TEST_UNIFORM_Z (and_u16_x_untied, svuint16_t,
		z0 = svand_u16_x (p0, z1, z2),
		z0 = svand_x (p0, z1, z2))

/*
** and_w0_u16_x_tied1:
**	mov	(z[0-9]+)\.h, w0
**	and	z0\.d, (z0\.d, \1\.d|\1\.d, z0\.d)
**	ret
*/
TEST_UNIFORM_ZX (and_w0_u16_x_tied1, svuint16_t, uint16_t,
		 z0 = svand_n_u16_x (p0, z0, x0),
		 z0 = svand_x (p0, z0, x0))

/*
** and_w0_u16_x_untied:
**	mov	(z[0-9]+)\.h, w0
**	and	z0\.d, (z1\.d, \1\.d|\1\.d, z1\.d)
**	ret
*/
TEST_UNIFORM_ZX (and_w0_u16_x_untied, svuint16_t, uint16_t,
		 z0 = svand_n_u16_x (p0, z1, x0),
		 z0 = svand_x (p0, z1, x0))

/*
** and_1_u16_x_tied1:
**	and	z0\.h, z0\.h, #0x1
**	ret
*/
TEST_UNIFORM_Z (and_1_u16_x_tied1, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, 1),
		z0 = svand_x (p0, z0, 1))

/*
** and_1_u16_x_untied:
**	movprfx	z0, z1
**	and	z0\.h, z0\.h, #0x1
**	ret
*/
TEST_UNIFORM_Z (and_1_u16_x_untied, svuint16_t,
		z0 = svand_n_u16_x (p0, z1, 1),
		z0 = svand_x (p0, z1, 1))

/*
** and_127_u16_x:
**	and	z0\.h, z0\.h, #0x7f
**	ret
*/
TEST_UNIFORM_Z (and_127_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, 127),
		z0 = svand_x (p0, z0, 127))

/*
** and_128_u16_x:
**	and	z0\.h, z0\.h, #0x80
**	ret
*/
TEST_UNIFORM_Z (and_128_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, 128),
		z0 = svand_x (p0, z0, 128))

/*
** and_255_u16_x:
**	and	z0\.h, z0\.h, #0xff
**	ret
*/
TEST_UNIFORM_Z (and_255_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, 255),
		z0 = svand_x (p0, z0, 255))

/*
** and_256_u16_x:
**	and	z0\.h, z0\.h, #0x100
**	ret
*/
TEST_UNIFORM_Z (and_256_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, 256),
		z0 = svand_x (p0, z0, 256))

/*
** and_257_u16_x:
**	and	z0\.h, z0\.h, #0x101
**	ret
*/
TEST_UNIFORM_Z (and_257_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, 257),
		z0 = svand_x (p0, z0, 257))

/*
** and_512_u16_x:
**	and	z0\.h, z0\.h, #0x200
**	ret
*/
TEST_UNIFORM_Z (and_512_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, 512),
		z0 = svand_x (p0, z0, 512))

/*
** and_65280_u16_x:
**	and	z0\.h, z0\.h, #0xff00
**	ret
*/
TEST_UNIFORM_Z (and_65280_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, 0xff00),
		z0 = svand_x (p0, z0, 0xff00))

/*
** and_m127_u16_x:
**	and	z0\.h, z0\.h, #0xff81
**	ret
*/
TEST_UNIFORM_Z (and_m127_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, -127),
		z0 = svand_x (p0, z0, -127))

/*
** and_m128_u16_x:
**	and	z0\.h, z0\.h, #0xff80
**	ret
*/
TEST_UNIFORM_Z (and_m128_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, -128),
		z0 = svand_x (p0, z0, -128))

/*
** and_m255_u16_x:
**	and	z0\.h, z0\.h, #0xff01
**	ret
*/
TEST_UNIFORM_Z (and_m255_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, -255),
		z0 = svand_x (p0, z0, -255))

/*
** and_m256_u16_x:
**	and	z0\.h, z0\.h, #0xff00
**	ret
*/
TEST_UNIFORM_Z (and_m256_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, -256),
		z0 = svand_x (p0, z0, -256))

/*
** and_m257_u16_x:
**	and	z0\.h, z0\.h, #0xfeff
**	ret
*/
TEST_UNIFORM_Z (and_m257_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, -257),
		z0 = svand_x (p0, z0, -257))

/*
** and_m512_u16_x:
**	and	z0\.h, z0\.h, #0xfe00
**	ret
*/
TEST_UNIFORM_Z (and_m512_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, -512),
		z0 = svand_x (p0, z0, -512))

/*
** and_m32768_u16_x:
**	and	z0\.h, z0\.h, #0x8000
**	ret
*/
TEST_UNIFORM_Z (and_m32768_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, -0x8000),
		z0 = svand_x (p0, z0, -0x8000))

/*
** and_5_u16_x:
**	mov	(z[0-9]+)\.h, #5
**	and	z0\.d, (z0\.d, \1\.d|\1\.d, z0\.d)
**	ret
*/
TEST_UNIFORM_Z (and_5_u16_x, svuint16_t,
		z0 = svand_n_u16_x (p0, z0, 5),
		z0 = svand_x (p0, z0, 5))
