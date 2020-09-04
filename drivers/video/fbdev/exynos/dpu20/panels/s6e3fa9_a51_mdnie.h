#ifndef __S6E3FA9_MDNIE_H__
#define __S6E3FA9_MDNIE_H__

/* 2019.08.26 */

/* SCR Position can be different each panel */
static struct mdnie_scr_info scr_info = {
	.index = 1,
	.cr = 32,		/* ASCR_WIDE_CR[7:0] */
	.wr = 50,		/* ASCR_WIDE_WR[7:0] */
	.wg = 52,		/* ASCR_WIDE_WG[7:0] */
	.wb = 54		/* ASCR_WIDE_WB[7:0] */
};

static struct mdnie_trans_info trans_info = {
	.index = 3,
	.offset = 16,
	.enable = 1
};

static struct mdnie_night_info night_info = {
	.max_w = 24,
	.max_h = 11
};

static struct mdnie_color_lens_info color_lens_info = {
	.max_color = 12,
	.max_level = 9,
	.max_w = 24
};

static inline int color_offset_f1(int x, int y)
{
	return ((y << 10) - (((x << 10) * 39) / 38) - (95 << 10)) >> 10;
}
static inline int color_offset_f2(int x, int y)
{
	return ((y << 10) - (((x << 10) * 36) / 35) - (56 << 10)) >> 10;
}
static inline int color_offset_f3(int x, int y)
{
	return ((y << 10) + (((x << 10) * 7) / 1) - (24728 << 10)) >> 10;
}
static inline int color_offset_f4(int x, int y)
{
	return ((y << 10) + (((x << 10) * 25) / 7) - (14031 << 10)) >> 10;
}

/* color coordination order is WR, WG, WB */
static unsigned char coordinate_data_1[] = {
	0xff, 0xff, 0xff, /* dummy */
	0xff, 0xfb, 0xfb, /* Tune_1 */
	0xff, 0xfc, 0xff, /* Tune_2 */
	0xfb, 0xf9, 0xff, /* Tune_3 */
	0xff, 0xfe, 0xfc, /* Tune_4 */
	0xff, 0xff, 0xff, /* Tune_5 */
	0xfb, 0xfc, 0xff, /* Tune_6 */
	0xfd, 0xff, 0xfa, /* Tune_7 */
	0xfc, 0xff, 0xfc, /* Tune_8 */
	0xfb, 0xff, 0xff, /* Tune_9 */
};

static unsigned char coordinate_data_2[] = {
	0xff, 0xff, 0xff, /* dummy */
	0xff, 0xfc, 0xf6, /* Tune_1 */
	0xff, 0xfc, 0xf6, /* Tune_2 */
	0xff, 0xfc, 0xf6, /* Tune_3 */
	0xff, 0xfc, 0xf6, /* Tune_4 */
	0xff, 0xfc, 0xf6, /* Tune_5 */
	0xff, 0xfc, 0xf6, /* Tune_6 */
	0xff, 0xfc, 0xf6, /* Tune_7 */
	0xff, 0xfc, 0xf6, /* Tune_8 */
	0xff, 0xfc, 0xf6, /* Tune_9 */
};

static unsigned char *coordinate_data[MODE_MAX] = {
	coordinate_data_2,
	coordinate_data_2,
	coordinate_data_2,
	coordinate_data_1,
	coordinate_data_1,
	coordinate_data_1,
};

static unsigned char adjust_ldu_data_1[] = {
	0xff, 0xff, 0xff,
	0xf6, 0xfa, 0xff,
	0xf4, 0xf8, 0xff,
	0xe9, 0xf2, 0xff,
	0xe2, 0xef, 0xff,
	0xd4, 0xe8, 0xff,
};

static unsigned char adjust_ldu_data_2[] = {
	0xff, 0xfa, 0xf1,
	0xff, 0xfd, 0xf8,
	0xff, 0xfd, 0xfa,
	0xfa, 0xfd, 0xff,
	0xf5, 0xfb, 0xff,
	0xe5, 0xf3, 0xff,
};

static unsigned char *adjust_ldu_data[MODE_MAX] = {
	adjust_ldu_data_2,
	adjust_ldu_data_2,
	adjust_ldu_data_2,
	adjust_ldu_data_1,
	adjust_ldu_data_1,
	adjust_ldu_data_1,
};

static unsigned char night_mode_data[] = {
	0x00, 0xff, 0xfc, 0x00, 0xf5, 0x00, 0xff, 0x00, 0x00, 0xfc, 0xf5, 0x00, 0xff, 0x00, 0xfc, 0x00, 0x00, 0xf5, 0xff, 0x00, 0xfc, 0x00, 0xf5, 0x00, /* 6500K */
	0x00, 0xff, 0xfa, 0x00, 0xf2, 0x00, 0xff, 0x00, 0x00, 0xfa, 0xf2, 0x00, 0xff, 0x00, 0xfa, 0x00, 0x00, 0xf2, 0xff, 0x00, 0xfa, 0x00, 0xf2, 0x00, /* 6300K */
	0x00, 0xff, 0xf9, 0x00, 0xee, 0x00, 0xff, 0x00, 0x00, 0xf9, 0xee, 0x00, 0xff, 0x00, 0xf9, 0x00, 0x00, 0xee, 0xff, 0x00, 0xf9, 0x00, 0xee, 0x00, /* 6100K */
	0x00, 0xff, 0xf7, 0x00, 0xe9, 0x00, 0xff, 0x00, 0x00, 0xf7, 0xe9, 0x00, 0xff, 0x00, 0xf7, 0x00, 0x00, 0xe9, 0xff, 0x00, 0xf7, 0x00, 0xe9, 0x00, /* 5900K */
	0x00, 0xff, 0xf5, 0x00, 0xe5, 0x00, 0xff, 0x00, 0x00, 0xf5, 0xe5, 0x00, 0xff, 0x00, 0xf5, 0x00, 0x00, 0xe5, 0xff, 0x00, 0xf5, 0x00, 0xe5, 0x00, /* 5700K */
	0x00, 0xff, 0xf3, 0x00, 0xe0, 0x00, 0xff, 0x00, 0x00, 0xf3, 0xe0, 0x00, 0xff, 0x00, 0xf3, 0x00, 0x00, 0xe0, 0xff, 0x00, 0xf3, 0x00, 0xe0, 0x00, /* 5500K */
	0x00, 0xff, 0xed, 0x00, 0xd2, 0x00, 0xff, 0x00, 0x00, 0xed, 0xd2, 0x00, 0xff, 0x00, 0xed, 0x00, 0x00, 0xd2, 0xff, 0x00, 0xed, 0x00, 0xd2, 0x00, /* 4900K */
	0x00, 0xff, 0xe6, 0x00, 0xbd, 0x00, 0xff, 0x00, 0x00, 0xe6, 0xbd, 0x00, 0xff, 0x00, 0xe6, 0x00, 0x00, 0xbd, 0xff, 0x00, 0xe6, 0x00, 0xbd, 0x00, /* 4300K */
	0x00, 0xff, 0xdc, 0x00, 0xa7, 0x00, 0xff, 0x00, 0x00, 0xdc, 0xa7, 0x00, 0xff, 0x00, 0xdc, 0x00, 0x00, 0xa7, 0xff, 0x00, 0xdc, 0x00, 0xa7, 0x00, /* 3700K */
	0x00, 0xff, 0xce, 0x00, 0x8a, 0x00, 0xff, 0x00, 0x00, 0xce, 0x8a, 0x00, 0xff, 0x00, 0xce, 0x00, 0x00, 0x8a, 0xff, 0x00, 0xce, 0x00, 0x8a, 0x00, /* 3100K */
	0x00, 0xff, 0xb0, 0x00, 0x5d, 0x00, 0xff, 0x00, 0x00, 0xb0, 0x5d, 0x00, 0xff, 0x00, 0xb0, 0x00, 0x00, 0x5d, 0xff, 0x00, 0xb0, 0x00, 0x5d, 0x00, /* 2300K */
};

static unsigned char color_lens_data[] = {
	//Blue
	0x00, 0xcc, 0xcc, 0x00, 0xff, 0x33, 0xcc, 0x00, 0x00, 0xcc, 0xff, 0x33, 0xcc, 0x00, 0xcc, 0x00, 0x33, 0xff, 0xcc, 0x00, 0xcc, 0x00, 0xff, 0x33, /* 20% */
	0x00, 0xbf, 0xbf, 0x00, 0xff, 0x40, 0xbf, 0x00, 0x00, 0xbf, 0xff, 0x40, 0xbf, 0x00, 0xbf, 0x00, 0x40, 0xff, 0xbf, 0x00, 0xbf, 0x00, 0xff, 0x40, /* 25% */
	0x00, 0xb2, 0xb2, 0x00, 0xff, 0x4d, 0xb2, 0x00, 0x00, 0xb2, 0xff, 0x4d, 0xb2, 0x00, 0xb2, 0x00, 0x4d, 0xff, 0xb2, 0x00, 0xb2, 0x00, 0xff, 0x4d, /* 30% */
	0x00, 0xa6, 0xa6, 0x00, 0xff, 0x59, 0xa6, 0x00, 0x00, 0xa6, 0xff, 0x59, 0xa6, 0x00, 0xa6, 0x00, 0x59, 0xff, 0xa6, 0x00, 0xa6, 0x00, 0xff, 0x59, /* 35% */
	0x00, 0x99, 0x99, 0x00, 0xff, 0x66, 0x99, 0x00, 0x00, 0x99, 0xff, 0x66, 0x99, 0x00, 0x99, 0x00, 0x66, 0xff, 0x99, 0x00, 0x99, 0x00, 0xff, 0x66, /* 40% */
	0x00, 0x8c, 0x8c, 0x00, 0xff, 0x73, 0x8c, 0x00, 0x00, 0x8c, 0xff, 0x73, 0x8c, 0x00, 0x8c, 0x00, 0x73, 0xff, 0x8c, 0x00, 0x8c, 0x00, 0xff, 0x73, /* 45% */
	0x00, 0x7f, 0x7f, 0x00, 0xff, 0x80, 0x7f, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x7f, 0x00, 0x7f, 0x00, 0x80, 0xff, 0x7f, 0x00, 0x7f, 0x00, 0xff, 0x80, /* 50% */
	0x00, 0x73, 0x73, 0x00, 0xff, 0x8c, 0x73, 0x00, 0x00, 0x73, 0xff, 0x8c, 0x73, 0x00, 0x73, 0x00, 0x8c, 0xff, 0x73, 0x00, 0x73, 0x00, 0xff, 0x8c, /* 55% */
	0x00, 0x66, 0x66, 0x00, 0xff, 0x99, 0x66, 0x00, 0x00, 0x66, 0xff, 0x99, 0x66, 0x00, 0x66, 0x00, 0x99, 0xff, 0x66, 0x00, 0x66, 0x00, 0xff, 0x99, /* 60% */

	//Azure
	0x00, 0xcc, 0xe5, 0x19, 0xff, 0x33, 0xcc, 0x00, 0x19, 0xe5, 0xff, 0x33, 0xcc, 0x00, 0xe5, 0x19, 0x33, 0xff, 0xcc, 0x00, 0xe5, 0x19, 0xff, 0x33, /* 20% */
	0x00, 0xbf, 0xdf, 0x20, 0xff, 0x40, 0xbf, 0x00, 0x20, 0xdf, 0xff, 0x40, 0xbf, 0x00, 0xdf, 0x20, 0x40, 0xff, 0xbf, 0x00, 0xdf, 0x20, 0xff, 0x40, /* 25% */
	0x00, 0xb2, 0xd8, 0x26, 0xff, 0x4d, 0xb2, 0x00, 0x26, 0xd8, 0xff, 0x4d, 0xb2, 0x00, 0xd8, 0x26, 0x4d, 0xff, 0xb2, 0x00, 0xd8, 0x26, 0xff, 0x4d, /* 30% */
	0x00, 0xa6, 0xd2, 0x2c, 0xff, 0x59, 0xa6, 0x00, 0x2c, 0xd2, 0xff, 0x59, 0xa6, 0x00, 0xd2, 0x2c, 0x59, 0xff, 0xa6, 0x00, 0xd2, 0x2c, 0xff, 0x59, /* 35% */
	0x00, 0x99, 0xcc, 0x33, 0xff, 0x66, 0x99, 0x00, 0x33, 0xcc, 0xff, 0x66, 0x99, 0x00, 0xcc, 0x33, 0x66, 0xff, 0x99, 0x00, 0xcc, 0x33, 0xff, 0x66, /* 40% */
	0x00, 0x8c, 0xc5, 0x39, 0xff, 0x73, 0x8c, 0x00, 0x39, 0xc5, 0xff, 0x73, 0x8c, 0x00, 0xc5, 0x39, 0x73, 0xff, 0x8c, 0x00, 0xc5, 0x39, 0xff, 0x73, /* 45% */
	0x00, 0x7f, 0xbf, 0x40, 0xff, 0x80, 0x7f, 0x00, 0x40, 0xbf, 0xff, 0x80, 0x7f, 0x00, 0xbf, 0x40, 0x80, 0xff, 0x7f, 0x00, 0xbf, 0x40, 0xff, 0x80, /* 50% */
	0x00, 0x73, 0xb9, 0x46, 0xff, 0x8c, 0x73, 0x00, 0x46, 0xb9, 0xff, 0x8c, 0x73, 0x00, 0xb9, 0x46, 0x8c, 0xff, 0x73, 0x00, 0xb9, 0x46, 0xff, 0x8c, /* 55% */
	0x00, 0x66, 0xb2, 0x4c, 0xff, 0x99, 0x66, 0x00, 0x4c, 0xb2, 0xff, 0x99, 0x66, 0x00, 0xb2, 0x4c, 0x99, 0xff, 0x66, 0x00, 0xb2, 0x4c, 0xff, 0x99, /* 60% */

	//Cyan
	0x00, 0xcc, 0xff, 0x33, 0xff, 0x33, 0xcc, 0x00, 0x33, 0xff, 0xff, 0x33, 0xcc, 0x00, 0xff, 0x33, 0x33, 0xff, 0xcc, 0x00, 0xff, 0x33, 0xff, 0x33, /* 20% */
	0x00, 0xbf, 0xff, 0x40, 0xff, 0x40, 0xbf, 0x00, 0x40, 0xff, 0xff, 0x40, 0xbf, 0x00, 0xff, 0x40, 0x40, 0xff, 0xbf, 0x00, 0xff, 0x40, 0xff, 0x40, /* 25% */
	0x00, 0xb2, 0xff, 0x4d, 0xff, 0x4d, 0xb2, 0x00, 0x4d, 0xff, 0xff, 0x4d, 0xb2, 0x00, 0xff, 0x4d, 0x4d, 0xff, 0xb2, 0x00, 0xff, 0x4d, 0xff, 0x4d, /* 30% */
	0x00, 0xa6, 0xff, 0x59, 0xff, 0x59, 0xa6, 0x00, 0x59, 0xff, 0xff, 0x59, 0xa6, 0x00, 0xff, 0x59, 0x59, 0xff, 0xa6, 0x00, 0xff, 0x59, 0xff, 0x59, /* 35% */
	0x00, 0x99, 0xff, 0x66, 0xff, 0x66, 0x99, 0x00, 0x66, 0xff, 0xff, 0x66, 0x99, 0x00, 0xff, 0x66, 0x66, 0xff, 0x99, 0x00, 0xff, 0x66, 0xff, 0x66, /* 40% */
	0x00, 0x8c, 0xff, 0x73, 0xff, 0x73, 0x8c, 0x00, 0x73, 0xff, 0xff, 0x73, 0x8c, 0x00, 0xff, 0x73, 0x73, 0xff, 0x8c, 0x00, 0xff, 0x73, 0xff, 0x73, /* 45% */
	0x00, 0x7f, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x00, 0x80, 0xff, 0xff, 0x80, 0x7f, 0x00, 0xff, 0x80, 0x80, 0xff, 0x7f, 0x00, 0xff, 0x80, 0xff, 0x80, /* 50% */
	0x00, 0x73, 0xff, 0x8c, 0xff, 0x8c, 0x73, 0x00, 0x8c, 0xff, 0xff, 0x8c, 0x73, 0x00, 0xff, 0x8c, 0x8c, 0xff, 0x73, 0x00, 0xff, 0x8c, 0xff, 0x8c, /* 55% */
	0x00, 0x66, 0xff, 0x99, 0xff, 0x99, 0x66, 0x00, 0x99, 0xff, 0xff, 0x99, 0x66, 0x00, 0xff, 0x99, 0x99, 0xff, 0x66, 0x00, 0xff, 0x99, 0xff, 0x99, /* 60% */

	//Spring green
	0x00, 0xcc, 0xff, 0x33, 0xe5, 0x19, 0xcc, 0x00, 0x33, 0xff, 0xe5, 0x19, 0xcc, 0x00, 0xff, 0x33, 0x19, 0xe5, 0xcc, 0x00, 0xff, 0x33, 0xe5, 0x19, /* 20% */
	0x00, 0xbf, 0xff, 0x40, 0xdf, 0x20, 0xbf, 0x00, 0x40, 0xff, 0xdf, 0x20, 0xbf, 0x00, 0xff, 0x40, 0x20, 0xdf, 0xbf, 0x00, 0xff, 0x40, 0xdf, 0x20, /* 25% */
	0x00, 0xb2, 0xff, 0x4d, 0xd8, 0x26, 0xb2, 0x00, 0x4d, 0xff, 0xd8, 0x26, 0xb2, 0x00, 0xff, 0x4d, 0x26, 0xd8, 0xb2, 0x00, 0xff, 0x4d, 0xd8, 0x26, /* 30% */
	0x00, 0xa6, 0xff, 0x59, 0xd2, 0x2c, 0xa6, 0x00, 0x59, 0xff, 0xd2, 0x2c, 0xa6, 0x00, 0xff, 0x59, 0x2c, 0xd2, 0xa6, 0x00, 0xff, 0x59, 0xd2, 0x2c, /* 35% */
	0x00, 0x99, 0xff, 0x66, 0xcc, 0x33, 0x99, 0x00, 0x66, 0xff, 0xcc, 0x33, 0x99, 0x00, 0xff, 0x66, 0x33, 0xcc, 0x99, 0x00, 0xff, 0x66, 0xcc, 0x33, /* 40% */
	0x00, 0x8c, 0xff, 0x73, 0xc5, 0x39, 0x8c, 0x00, 0x73, 0xff, 0xc5, 0x39, 0x8c, 0x00, 0xff, 0x73, 0x39, 0xc5, 0x8c, 0x00, 0xff, 0x73, 0xc5, 0x39, /* 45% */
	0x00, 0x7f, 0xff, 0x80, 0xbf, 0x40, 0x7f, 0x00, 0x80, 0xff, 0xbf, 0x40, 0x7f, 0x00, 0xff, 0x80, 0x40, 0xbf, 0x7f, 0x00, 0xff, 0x80, 0xbf, 0x40, /* 50% */
	0x00, 0x73, 0xff, 0x8c, 0xb9, 0x46, 0x73, 0x00, 0x8c, 0xff, 0xb9, 0x46, 0x73, 0x00, 0xff, 0x8c, 0x46, 0xb9, 0x73, 0x00, 0xff, 0x8c, 0xb9, 0x46, /* 55% */
	0x00, 0x66, 0xff, 0x99, 0xb2, 0x4c, 0x66, 0x00, 0x99, 0xff, 0xb2, 0x4c, 0x66, 0x00, 0xff, 0x99, 0x4c, 0xb2, 0x66, 0x00, 0xff, 0x99, 0xb2, 0x4c, /* 60% */

	//Green
	0x00, 0xcc, 0xff, 0x33, 0xcc, 0x00, 0xcc, 0x00, 0x33, 0xff, 0xcc, 0x00, 0xcc, 0x00, 0xff, 0x33, 0x00, 0xcc, 0xcc, 0x00, 0xff, 0x33, 0xcc, 0x00, /* 20% */
	0x00, 0xbf, 0xff, 0x40, 0xbf, 0x00, 0xbf, 0x00, 0x40, 0xff, 0xbf, 0x00, 0xbf, 0x00, 0xff, 0x40, 0x00, 0xbf, 0xbf, 0x00, 0xff, 0x40, 0xbf, 0x00, /* 25% */
	0x00, 0xb2, 0xff, 0x4d, 0xb2, 0x00, 0xb2, 0x00, 0x4d, 0xff, 0xb2, 0x00, 0xb2, 0x00, 0xff, 0x4d, 0x00, 0xb2, 0xb2, 0x00, 0xff, 0x4d, 0xb2, 0x00, /* 30% */
	0x00, 0xa6, 0xff, 0x59, 0xa6, 0x00, 0xa6, 0x00, 0x59, 0xff, 0xa6, 0x00, 0xa6, 0x00, 0xff, 0x59, 0x00, 0xa6, 0xa6, 0x00, 0xff, 0x59, 0xa6, 0x00, /* 35% */
	0x00, 0x99, 0xff, 0x66, 0x99, 0x00, 0x99, 0x00, 0x66, 0xff, 0x99, 0x00, 0x99, 0x00, 0xff, 0x66, 0x00, 0x99, 0x99, 0x00, 0xff, 0x66, 0x99, 0x00, /* 40% */
	0x00, 0x8c, 0xff, 0x73, 0x8c, 0x00, 0x8c, 0x00, 0x73, 0xff, 0x8c, 0x00, 0x8c, 0x00, 0xff, 0x73, 0x00, 0x8c, 0x8c, 0x00, 0xff, 0x73, 0x8c, 0x00, /* 45% */
	0x00, 0x7f, 0xff, 0x80, 0x7f, 0x00, 0x7f, 0x00, 0x80, 0xff, 0x7f, 0x00, 0x7f, 0x00, 0xff, 0x80, 0x00, 0x7f, 0x7f, 0x00, 0xff, 0x80, 0x7f, 0x00, /* 50% */
	0x00, 0x73, 0xff, 0x8c, 0x73, 0x00, 0x73, 0x00, 0x8c, 0xff, 0x73, 0x00, 0x73, 0x00, 0xff, 0x8c, 0x00, 0x73, 0x73, 0x00, 0xff, 0x8c, 0x73, 0x00, /* 55% */
	0x00, 0x66, 0xff, 0x99, 0x66, 0x00, 0x66, 0x00, 0x99, 0xff, 0x66, 0x00, 0x66, 0x00, 0xff, 0x99, 0x00, 0x66, 0x66, 0x00, 0xff, 0x99, 0x66, 0x00, /* 60% */

	//Chartreuse Green
	0x19, 0xe5, 0xff, 0x33, 0xcc, 0x00, 0xe5, 0x19, 0x33, 0xff, 0xcc, 0x00, 0xe5, 0x19, 0xff, 0x33, 0x00, 0xcc, 0xe5, 0x19, 0xff, 0x33, 0xcc, 0x00, /* 20% */
	0x20, 0xdf, 0xff, 0x40, 0xbf, 0x00, 0xdf, 0x20, 0x40, 0xff, 0xbf, 0x00, 0xdf, 0x20, 0xff, 0x40, 0x00, 0xbf, 0xdf, 0x20, 0xff, 0x40, 0xbf, 0x00, /* 25% */
	0x26, 0xd8, 0xff, 0x4d, 0xb2, 0x00, 0xd8, 0x26, 0x4d, 0xff, 0xb2, 0x00, 0xd8, 0x26, 0xff, 0x4d, 0x00, 0xb2, 0xd8, 0x26, 0xff, 0x4d, 0xb2, 0x00, /* 30% */
	0x2c, 0xd2, 0xff, 0x59, 0xa6, 0x00, 0xd2, 0x2c, 0x59, 0xff, 0xa6, 0x00, 0xd2, 0x2c, 0xff, 0x59, 0x00, 0xa6, 0xd2, 0x2c, 0xff, 0x59, 0xa6, 0x00, /* 35% */
	0x33, 0xcc, 0xff, 0x66, 0x99, 0x00, 0xcc, 0x33, 0x66, 0xff, 0x99, 0x00, 0xcc, 0x33, 0xff, 0x66, 0x00, 0x99, 0xcc, 0x33, 0xff, 0x66, 0x99, 0x00, /* 40% */
	0x39, 0xc5, 0xff, 0x73, 0x8c, 0x00, 0xc5, 0x39, 0x73, 0xff, 0x8c, 0x00, 0xc5, 0x39, 0xff, 0x73, 0x00, 0x8c, 0xc5, 0x39, 0xff, 0x73, 0x8c, 0x00, /* 45% */
	0x40, 0xbf, 0xff, 0x80, 0x7f, 0x00, 0xbf, 0x40, 0x80, 0xff, 0x7f, 0x00, 0xbf, 0x40, 0xff, 0x80, 0x00, 0x7f, 0xbf, 0x40, 0xff, 0x80, 0x7f, 0x00, /* 50% */
	0x46, 0xb9, 0xff, 0x8c, 0x73, 0x00, 0xb9, 0x46, 0x8c, 0xff, 0x73, 0x00, 0xb9, 0x46, 0xff, 0x8c, 0x00, 0x73, 0xb9, 0x46, 0xff, 0x8c, 0x73, 0x00, /* 55% */
	0x4c, 0xb2, 0xff, 0x99, 0x66, 0x00, 0xb2, 0x4c, 0x99, 0xff, 0x66, 0x00, 0xb2, 0x4c, 0xff, 0x99, 0x00, 0x66, 0xb2, 0x4c, 0xff, 0x99, 0x66, 0x00, /* 60% */

	//Yellow
	0x33, 0xff, 0xff, 0x33, 0xcc, 0x00, 0xff, 0x33, 0x33, 0xff, 0xcc, 0x00, 0xff, 0x33, 0xff, 0x33, 0x00, 0xcc, 0xff, 0x33, 0xff, 0x33, 0xcc, 0x00, /* 20% */
	0x40, 0xff, 0xff, 0x40, 0xbf, 0x00, 0xff, 0x40, 0x40, 0xff, 0xbf, 0x00, 0xff, 0x40, 0xff, 0x40, 0x00, 0xbf, 0xff, 0x40, 0xff, 0x40, 0xbf, 0x00, /* 25% */
	0x4d, 0xff, 0xff, 0x4d, 0xb2, 0x00, 0xff, 0x4d, 0x4d, 0xff, 0xb2, 0x00, 0xff, 0x4d, 0xff, 0x4d, 0x00, 0xb2, 0xff, 0x4d, 0xff, 0x4d, 0xb2, 0x00, /* 30% */
	0x59, 0xff, 0xff, 0x59, 0xa6, 0x00, 0xff, 0x59, 0x59, 0xff, 0xa6, 0x00, 0xff, 0x59, 0xff, 0x59, 0x00, 0xa6, 0xff, 0x59, 0xff, 0x59, 0xa6, 0x00, /* 35% */
	0x66, 0xff, 0xff, 0x66, 0x99, 0x00, 0xff, 0x66, 0x66, 0xff, 0x99, 0x00, 0xff, 0x66, 0xff, 0x66, 0x00, 0x99, 0xff, 0x66, 0xff, 0x66, 0x99, 0x00, /* 40% */
	0x73, 0xff, 0xff, 0x73, 0x8c, 0x00, 0xff, 0x73, 0x73, 0xff, 0x8c, 0x00, 0xff, 0x73, 0xff, 0x73, 0x00, 0x8c, 0xff, 0x73, 0xff, 0x73, 0x8c, 0x00, /* 45% */
	0x80, 0xff, 0xff, 0x80, 0x7f, 0x00, 0xff, 0x80, 0x80, 0xff, 0x7f, 0x00, 0xff, 0x80, 0xff, 0x80, 0x00, 0x7f, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x00, /* 50% */
	0x8c, 0xff, 0xff, 0x8c, 0x73, 0x00, 0xff, 0x8c, 0x8c, 0xff, 0x73, 0x00, 0xff, 0x8c, 0xff, 0x8c, 0x00, 0x73, 0xff, 0x8c, 0xff, 0x8c, 0x73, 0x00, /* 55% */
	0x99, 0xff, 0xff, 0x99, 0x66, 0x00, 0xff, 0x99, 0x99, 0xff, 0x66, 0x00, 0xff, 0x99, 0xff, 0x99, 0x00, 0x66, 0xff, 0x99, 0xff, 0x99, 0x66, 0x00, /* 60% */

	//Orange
	0x33, 0xff, 0xe5, 0x19, 0xcc, 0x00, 0xff, 0x33, 0x19, 0xe5, 0xcc, 0x00, 0xff, 0x33, 0xe5, 0x19, 0x00, 0xcc, 0xff, 0x33, 0xe5, 0x19, 0xcc, 0x00, /* 20% */
	0x40, 0xff, 0xdf, 0x20, 0xbf, 0x00, 0xff, 0x40, 0x20, 0xdf, 0xbf, 0x00, 0xff, 0x40, 0xdf, 0x20, 0x00, 0xbf, 0xff, 0x40, 0xdf, 0x20, 0xbf, 0x00, /* 25% */
	0x4d, 0xff, 0xd8, 0x26, 0xb2, 0x00, 0xff, 0x4d, 0x26, 0xd8, 0xb2, 0x00, 0xff, 0x4d, 0xd8, 0x26, 0x00, 0xb2, 0xff, 0x4d, 0xd8, 0x26, 0xb2, 0x00, /* 30% */
	0x59, 0xff, 0xd2, 0x2c, 0xa6, 0x00, 0xff, 0x59, 0x2c, 0xd2, 0xa6, 0x00, 0xff, 0x59, 0xd2, 0x2c, 0x00, 0xa6, 0xff, 0x59, 0xd2, 0x2c, 0xa6, 0x00, /* 35% */
	0x66, 0xff, 0xcc, 0x33, 0x99, 0x00, 0xff, 0x66, 0x33, 0xcc, 0x99, 0x00, 0xff, 0x66, 0xcc, 0x33, 0x00, 0x99, 0xff, 0x66, 0xcc, 0x33, 0x99, 0x00, /* 40% */
	0x73, 0xff, 0xc5, 0x39, 0x8c, 0x00, 0xff, 0x73, 0x39, 0xc5, 0x8c, 0x00, 0xff, 0x73, 0xc5, 0x39, 0x00, 0x8c, 0xff, 0x73, 0xc5, 0x39, 0x8c, 0x00, /* 45% */
	0x80, 0xff, 0xbf, 0x40, 0x7f, 0x00, 0xff, 0x80, 0x40, 0xbf, 0x7f, 0x00, 0xff, 0x80, 0xbf, 0x40, 0x00, 0x7f, 0xff, 0x80, 0xbf, 0x40, 0x7f, 0x00, /* 50% */
	0x8c, 0xff, 0xb9, 0x46, 0x73, 0x00, 0xff, 0x8c, 0x46, 0xb9, 0x73, 0x00, 0xff, 0x8c, 0xb9, 0x46, 0x00, 0x73, 0xff, 0x8c, 0xb9, 0x46, 0x73, 0x00, /* 55% */
	0x99, 0xff, 0xb2, 0x4c, 0x66, 0x00, 0xff, 0x99, 0x4c, 0xb2, 0x66, 0x00, 0xff, 0x99, 0xb2, 0x4c, 0x00, 0x66, 0xff, 0x99, 0xb2, 0x4c, 0x66, 0x00, /* 60% */

	//Red
	0x33, 0xff, 0xcc, 0x00, 0xcc, 0x00, 0xff, 0x33, 0x00, 0xcc, 0xcc, 0x00, 0xff, 0x33, 0xcc, 0x00, 0x00, 0xcc, 0xff, 0x33, 0xcc, 0x00, 0xcc, 0x00, /* 20% */
	0x40, 0xff, 0xbf, 0x00, 0xbf, 0x00, 0xff, 0x40, 0x00, 0xbf, 0xbf, 0x00, 0xff, 0x40, 0xbf, 0x00, 0x00, 0xbf, 0xff, 0x40, 0xbf, 0x00, 0xbf, 0x00, /* 25% */
	0x4d, 0xff, 0xb2, 0x00, 0xb2, 0x00, 0xff, 0x4d, 0x00, 0xb2, 0xb2, 0x00, 0xff, 0x4d, 0xb2, 0x00, 0x00, 0xb2, 0xff, 0x4d, 0xb2, 0x00, 0xb2, 0x00, /* 30% */
	0x59, 0xff, 0xa6, 0x00, 0xa6, 0x00, 0xff, 0x59, 0x00, 0xa6, 0xa6, 0x00, 0xff, 0x59, 0xa6, 0x00, 0x00, 0xa6, 0xff, 0x59, 0xa6, 0x00, 0xa6, 0x00, /* 35% */
	0x66, 0xff, 0x99, 0x00, 0x99, 0x00, 0xff, 0x66, 0x00, 0x99, 0x99, 0x00, 0xff, 0x66, 0x99, 0x00, 0x00, 0x99, 0xff, 0x66, 0x99, 0x00, 0x99, 0x00, /* 40% */
	0x73, 0xff, 0x8c, 0x00, 0x8c, 0x00, 0xff, 0x73, 0x00, 0x8c, 0x8c, 0x00, 0xff, 0x73, 0x8c, 0x00, 0x00, 0x8c, 0xff, 0x73, 0x8c, 0x00, 0x8c, 0x00, /* 45% */
	0x80, 0xff, 0x7f, 0x00, 0x7f, 0x00, 0xff, 0x80, 0x00, 0x7f, 0x7f, 0x00, 0xff, 0x80, 0x7f, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x7f, 0x00, 0x7f, 0x00, /* 50% */
	0x8c, 0xff, 0x73, 0x00, 0x73, 0x00, 0xff, 0x8c, 0x00, 0x73, 0x73, 0x00, 0xff, 0x8c, 0x73, 0x00, 0x00, 0x73, 0xff, 0x8c, 0x73, 0x00, 0x73, 0x00, /* 55% */
	0x99, 0xff, 0x66, 0x00, 0x66, 0x00, 0xff, 0x99, 0x00, 0x66, 0x66, 0x00, 0xff, 0x99, 0x66, 0x00, 0x00, 0x66, 0xff, 0x99, 0x66, 0x00, 0x66, 0x00, /* 60% */

	//Rose
	0x33, 0xff, 0xcc, 0x00, 0xe5, 0x19, 0xff, 0x33, 0x00, 0xcc, 0xe5, 0x19, 0xff, 0x33, 0xcc, 0x00, 0x19, 0xe5, 0xff, 0x33, 0xcc, 0x00, 0xe5, 0x19, /* 20% */
	0x40, 0xff, 0xbf, 0x00, 0xdf, 0x20, 0xff, 0x40, 0x00, 0xbf, 0xdf, 0x20, 0xff, 0x40, 0xbf, 0x00, 0x20, 0xdf, 0xff, 0x40, 0xbf, 0x00, 0xdf, 0x20, /* 25% */
	0x4d, 0xff, 0xb2, 0x00, 0xd8, 0x26, 0xff, 0x4d, 0x00, 0xb2, 0xd8, 0x26, 0xff, 0x4d, 0xb2, 0x00, 0x26, 0xd8, 0xff, 0x4d, 0xb2, 0x00, 0xd8, 0x26, /* 30% */
	0x59, 0xff, 0xa6, 0x00, 0xd2, 0x2c, 0xff, 0x59, 0x00, 0xa6, 0xd2, 0x2c, 0xff, 0x59, 0xa6, 0x00, 0x2c, 0xd2, 0xff, 0x59, 0xa6, 0x00, 0xd2, 0x2c, /* 35% */
	0x66, 0xff, 0x99, 0x00, 0xcc, 0x33, 0xff, 0x66, 0x00, 0x99, 0xcc, 0x33, 0xff, 0x66, 0x99, 0x00, 0x33, 0xcc, 0xff, 0x66, 0x99, 0x00, 0xcc, 0x33, /* 40% */
	0x73, 0xff, 0x8c, 0x00, 0xc5, 0x39, 0xff, 0x73, 0x00, 0x8c, 0xc5, 0x39, 0xff, 0x73, 0x8c, 0x00, 0x39, 0xc5, 0xff, 0x73, 0x8c, 0x00, 0xc5, 0x39, /* 45% */
	0x80, 0xff, 0x7f, 0x00, 0xbf, 0x40, 0xff, 0x80, 0x00, 0x7f, 0xbf, 0x40, 0xff, 0x80, 0x7f, 0x00, 0x40, 0xbf, 0xff, 0x80, 0x7f, 0x00, 0xbf, 0x40, /* 50% */
	0x8c, 0xff, 0x73, 0x00, 0xb9, 0x46, 0xff, 0x8c, 0x00, 0x73, 0xb9, 0x46, 0xff, 0x8c, 0x73, 0x00, 0x46, 0xb9, 0xff, 0x8c, 0x73, 0x00, 0xb9, 0x46, /* 55% */
	0x99, 0xff, 0x66, 0x00, 0xb2, 0x4c, 0xff, 0x99, 0x00, 0x66, 0xb2, 0x4c, 0xff, 0x99, 0x66, 0x00, 0x4c, 0xb2, 0xff, 0x99, 0x66, 0x00, 0xb2, 0x4c, /* 60% */

	//Magenta
	0x33, 0xff, 0xcc, 0x00, 0xff, 0x33, 0xff, 0x33, 0x00, 0xcc, 0xff, 0x33, 0xff, 0x33, 0xcc, 0x00, 0x33, 0xff, 0xff, 0x33, 0xcc, 0x00, 0xff, 0x33, /* 20% */
	0x40, 0xff, 0xbf, 0x00, 0xff, 0x40, 0xff, 0x40, 0x00, 0xbf, 0xff, 0x40, 0xff, 0x40, 0xbf, 0x00, 0x40, 0xff, 0xff, 0x40, 0xbf, 0x00, 0xff, 0x40, /* 25% */
	0x4d, 0xff, 0xb2, 0x00, 0xff, 0x4d, 0xff, 0x4d, 0x00, 0xb2, 0xff, 0x4d, 0xff, 0x4d, 0xb2, 0x00, 0x4d, 0xff, 0xff, 0x4d, 0xb2, 0x00, 0xff, 0x4d, /* 30% */
	0x59, 0xff, 0xa6, 0x00, 0xff, 0x59, 0xff, 0x59, 0x00, 0xa6, 0xff, 0x59, 0xff, 0x59, 0xa6, 0x00, 0x59, 0xff, 0xff, 0x59, 0xa6, 0x00, 0xff, 0x59, /* 35% */
	0x66, 0xff, 0x99, 0x00, 0xff, 0x66, 0xff, 0x66, 0x00, 0x99, 0xff, 0x66, 0xff, 0x66, 0x99, 0x00, 0x66, 0xff, 0xff, 0x66, 0x99, 0x00, 0xff, 0x66, /* 40% */
	0x73, 0xff, 0x8c, 0x00, 0xff, 0x73, 0xff, 0x73, 0x00, 0x8c, 0xff, 0x73, 0xff, 0x73, 0x8c, 0x00, 0x73, 0xff, 0xff, 0x73, 0x8c, 0x00, 0xff, 0x73, /* 45% */
	0x80, 0xff, 0x7f, 0x00, 0xff, 0x80, 0xff, 0x80, 0x00, 0x7f, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x00, 0x80, 0xff, 0xff, 0x80, 0x7f, 0x00, 0xff, 0x80, /* 50% */
	0x8c, 0xff, 0x73, 0x00, 0xff, 0x8c, 0xff, 0x8c, 0x00, 0x73, 0xff, 0x8c, 0xff, 0x8c, 0x73, 0x00, 0x8c, 0xff, 0xff, 0x8c, 0x73, 0x00, 0xff, 0x8c, /* 55% */
	0x99, 0xff, 0x66, 0x00, 0xff, 0x99, 0xff, 0x99, 0x00, 0x66, 0xff, 0x99, 0xff, 0x99, 0x66, 0x00, 0x99, 0xff, 0xff, 0x99, 0x66, 0x00, 0xff, 0x99, /* 60% */

	//Violet
	0x19, 0xe5, 0xcc, 0x00, 0xff, 0x33, 0xe5, 0x19, 0x00, 0xcc, 0xff, 0x33, 0xe5, 0x19, 0xcc, 0x00, 0x33, 0xff, 0xe5, 0x19, 0xcc, 0x00, 0xff, 0x33, /* 20% */
	0x20, 0xdf, 0xbf, 0x00, 0xff, 0x40, 0xdf, 0x20, 0x00, 0xbf, 0xff, 0x40, 0xdf, 0x20, 0xbf, 0x00, 0x40, 0xff, 0xdf, 0x20, 0xbf, 0x00, 0xff, 0x40, /* 25% */
	0x26, 0xd8, 0xb2, 0x00, 0xff, 0x4d, 0xd8, 0x26, 0x00, 0xb2, 0xff, 0x4d, 0xd8, 0x26, 0xb2, 0x00, 0x4d, 0xff, 0xd8, 0x26, 0xb2, 0x00, 0xff, 0x4d, /* 30% */
	0x2c, 0xd2, 0xa6, 0x00, 0xff, 0x59, 0xd2, 0x2c, 0x00, 0xa6, 0xff, 0x59, 0xd2, 0x2c, 0xa6, 0x00, 0x59, 0xff, 0xd2, 0x2c, 0xa6, 0x00, 0xff, 0x59, /* 35% */
	0x33, 0xcc, 0x99, 0x00, 0xff, 0x66, 0xcc, 0x33, 0x00, 0x99, 0xff, 0x66, 0xcc, 0x33, 0x99, 0x00, 0x66, 0xff, 0xcc, 0x33, 0x99, 0x00, 0xff, 0x66, /* 40% */
	0x39, 0xc5, 0x8c, 0x00, 0xff, 0x73, 0xc5, 0x39, 0x00, 0x8c, 0xff, 0x73, 0xc5, 0x39, 0x8c, 0x00, 0x73, 0xff, 0xc5, 0x39, 0x8c, 0x00, 0xff, 0x73, /* 45% */
	0x40, 0xbf, 0x7f, 0x00, 0xff, 0x80, 0xbf, 0x40, 0x00, 0x7f, 0xff, 0x80, 0xbf, 0x40, 0x7f, 0x00, 0x80, 0xff, 0xbf, 0x40, 0x7f, 0x00, 0xff, 0x80, /* 50% */
	0x46, 0xb9, 0x73, 0x00, 0xff, 0x8c, 0xb9, 0x46, 0x00, 0x73, 0xff, 0x8c, 0xb9, 0x46, 0x73, 0x00, 0x8c, 0xff, 0xb9, 0x46, 0x73, 0x00, 0xff, 0x8c, /* 55% */
	0x4c, 0xb2, 0x66, 0x00, 0xff, 0x99, 0xb2, 0x4c, 0x00, 0x66, 0xff, 0x99, 0xb2, 0x4c, 0x66, 0x00, 0x99, 0xff, 0xb2, 0x4c, 0x66, 0x00, 0xff, 0x99, /* 60% */
};

static inline int get_hbm_index(int idx)
{
	int i = 0;
	int idx_list[] = {
		40000	/* idx < 40000: HBM_OFF */
				/* idx >= 40000: HBM_ON */
	};

	while (i < ARRAY_SIZE(idx_list)) {
		if (idx < idx_list[i])
			break;
		i++;
	}

	return i;
}

static unsigned char BYPASS_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char BYPASS_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char BYPASS_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char GRAYSCALE_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0x4c, /* ascr_skin_Rr */
	0x4c, /* ascr_skin_Rg */
	0x4c, /* ascr_skin_Rb */
	0xe2, /* ascr_skin_Yr */
	0xe2, /* ascr_skin_Yg */
	0xe2, /* ascr_skin_Yb */
	0x69, /* ascr_skin_Mr */
	0x69, /* ascr_skin_Mg */
	0x69, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0xb3, /* ascr_Cr */
	0x4c, /* ascr_Rr */
	0xb3, /* ascr_Cg */
	0x4c, /* ascr_Rg */
	0xb3, /* ascr_Cb */
	0x4c, /* ascr_Rb */
	0x69, /* ascr_Mr */
	0x96, /* ascr_Gr */
	0x69, /* ascr_Mg */
	0x96, /* ascr_Gg */
	0x69, /* ascr_Mb */
	0x96, /* ascr_Gb */
	0xe2, /* ascr_Yr */
	0x1d, /* ascr_Br */
	0xe2, /* ascr_Yg */
	0x1d, /* ascr_Bg */
	0xe2, /* ascr_Yb */
	0x1d, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char GRAYSCALE_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char GRAYSCALE_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xc0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char GRAYSCALE_NEGATIVE_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0x4c, /* ascr_skin_Rr */
	0x4c, /* ascr_skin_Rg */
	0x4c, /* ascr_skin_Rb */
	0xe2, /* ascr_skin_Yr */
	0xe2, /* ascr_skin_Yg */
	0xe2, /* ascr_skin_Yb */
	0x69, /* ascr_skin_Mr */
	0x69, /* ascr_skin_Mg */
	0x69, /* ascr_skin_Mb */
	0x00, /* ascr_skin_Wr */
	0x00, /* ascr_skin_Wg */
	0x00, /* ascr_skin_Wb */
	0xb3, /* ascr_Cr */
	0x4c, /* ascr_Rr */
	0xb3, /* ascr_Cg */
	0x4c, /* ascr_Rg */
	0xb3, /* ascr_Cb */
	0x4c, /* ascr_Rb */
	0x69, /* ascr_Mr */
	0x96, /* ascr_Gr */
	0x69, /* ascr_Mg */
	0x96, /* ascr_Gg */
	0x69, /* ascr_Mb */
	0x96, /* ascr_Gb */
	0xe2, /* ascr_Yr */
	0x1d, /* ascr_Br */
	0xe2, /* ascr_Yg */
	0x1d, /* ascr_Bg */
	0xe2, /* ascr_Yb */
	0x1d, /* ascr_Bb */
	0x00, /* ascr_Wr */
	0xff, /* ascr_Kr */
	0x00, /* ascr_Wg */
	0xff, /* ascr_Kg */
	0x00, /* ascr_Wb */
	0xff, /* ascr_Kb */
};

static unsigned char GRAYSCALE_NEGATIVE_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char GRAYSCALE_NEGATIVE_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xc0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char NEGATIVE_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0x00, /* ascr_Wr */
	0xff, /* ascr_Kr */
	0x00, /* ascr_Wg */
	0xff, /* ascr_Kg */
	0x00, /* ascr_Wb */
	0xff, /* ascr_Kb */
};

static unsigned char NEGATIVE_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char NEGATIVE_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xc0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char NIGHT_MODE_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char NIGHT_MODE_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char NIGHT_MODE_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xc0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char COLOR_BLIND_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char COLOR_BLIND_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char COLOR_BLIND_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xc0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char COLOR_LENS_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char COLOR_LENS_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char COLOR_LENS_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xc0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char LIGHT_NOTIFICATION_1[] = {
	/* start */
	0xDF,
	0x01, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x60, /* ascr_skin_Rg */
	0x13, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf9, /* ascr_skin_Yg */
	0x13, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x60, /* ascr_skin_Mg */
	0xac, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf9, /* ascr_skin_Wg */
	0xac, /* ascr_skin_Wb */
	0x66, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xf9, /* ascr_Cg */
	0x60, /* ascr_Rg */
	0xac, /* ascr_Cb */
	0x13, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x66, /* ascr_Gr */
	0x60, /* ascr_Mg */
	0xf9, /* ascr_Gg */
	0xac, /* ascr_Mb */
	0x13, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x66, /* ascr_Br */
	0xf9, /* ascr_Yg */
	0x60, /* ascr_Bg */
	0x13, /* ascr_Yb */
	0xac, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf9, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xac, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char LIGHT_NOTIFICATION_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char LIGHT_NOTIFICATION_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char SCREEN_CURTAIN_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0x00, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0x00, /* ascr_skin_Yr */
	0x00, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0x00, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0x00, /* ascr_skin_Mb */
	0x00, /* ascr_skin_Wr */
	0x00, /* ascr_skin_Wg */
	0x00, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0x00, /* ascr_Rr */
	0x00, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0x00, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0x00, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0x00, /* ascr_Gg */
	0x00, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0x00, /* ascr_Yr */
	0x00, /* ascr_Br */
	0x00, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0x00, /* ascr_Bb */
	0x00, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0x00, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0x00, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char SCREEN_CURTAIN_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char SCREEN_CURTAIN_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xc0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

/******************** UI ********************/
static unsigned char STANDARD_UI_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xef, /* ascr_skin_Rr */
	0x32, /* ascr_skin_Rg */
	0x2c, /* ascr_skin_Rb */
	0xf1, /* ascr_skin_Yr */
	0xea, /* ascr_skin_Yg */
	0x40, /* ascr_skin_Yb */
	0xfa, /* ascr_skin_Mr */
	0x40, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xef, /* ascr_Rr */
	0xea, /* ascr_Cg */
	0x32, /* ascr_Rg */
	0xe6, /* ascr_Cb */
	0x2c, /* ascr_Rb */
	0xfa, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x40, /* ascr_Mg */
	0xde, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x30, /* ascr_Gb */
	0xf1, /* ascr_Yr */
	0x2b, /* ascr_Br */
	0xea, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x40, /* ascr_Yb */
	0xdd, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char STANDARD_UI_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x02, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char STANDARD_UI_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char NATURAL_UI_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xda, /* ascr_skin_Rr */
	0x11, /* ascr_skin_Rg */
	0x29, /* ascr_skin_Rb */
	0xf4, /* ascr_skin_Yr */
	0xef, /* ascr_skin_Yg */
	0x5a, /* ascr_skin_Yb */
	0xe4, /* ascr_skin_Mr */
	0x34, /* ascr_skin_Mg */
	0xe6, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xfc, /* ascr_skin_Wg */
	0xf6, /* ascr_skin_Wb */
	0x8a, /* ascr_Cr */
	0xda, /* ascr_Rr */
	0xf4, /* ascr_Cg */
	0x11, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xe4, /* ascr_Mr */
	0x7c, /* ascr_Gr */
	0x34, /* ascr_Mg */
	0xfc, /* ascr_Gg */
	0xe6, /* ascr_Mb */
	0x51, /* ascr_Gb */
	0xf4, /* ascr_Yr */
	0x2c, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x2e, /* ascr_Bg */
	0x5a, /* ascr_Yb */
	0xdf, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfc, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xf6, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char NATURAL_UI_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char NATURAL_UI_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char DYNAMIC_UI_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xde, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xef, /* ascr_skin_Yr */
	0xe7, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xeb, /* ascr_skin_Mr */
	0x16, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x5d, /* ascr_Cr */
	0xde, /* ascr_Rr */
	0xf2, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xea, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xeb, /* ascr_Mr */
	0x50, /* ascr_Gr */
	0x16, /* ascr_Mg */
	0xe3, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xef, /* ascr_Yr */
	0x2e, /* ascr_Br */
	0xe7, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xe2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char DYNAMIC_UI_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char DYNAMIC_UI_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char MOVIE_UI_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char MOVIE_UI_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char MOVIE_UI_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char AUTO_UI_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x37, /* ascr_dist_up */
	0x29, /* ascr_dist_down */
	0x19, /* ascr_dist_right */
	0x47, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x25,
	0x3d,
	0x00, /* ascr_div_down */
	0x31,
	0xf4,
	0x00, /* ascr_div_right */
	0x51,
	0xec,
	0x00, /* ascr_div_left */
	0x1c,
	0xd8,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char AUTO_UI_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char AUTO_UI_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

/******************** GALLERY ********************/
static unsigned char STANDARD_GALLERY_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xef, /* ascr_skin_Rr */
	0x32, /* ascr_skin_Rg */
	0x2c, /* ascr_skin_Rb */
	0xf1, /* ascr_skin_Yr */
	0xea, /* ascr_skin_Yg */
	0x40, /* ascr_skin_Yb */
	0xfa, /* ascr_skin_Mr */
	0x40, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xef, /* ascr_Rr */
	0xea, /* ascr_Cg */
	0x32, /* ascr_Rg */
	0xe6, /* ascr_Cb */
	0x2c, /* ascr_Rb */
	0xfa, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x40, /* ascr_Mg */
	0xde, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x30, /* ascr_Gb */
	0xf1, /* ascr_Yr */
	0x2b, /* ascr_Br */
	0xea, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x40, /* ascr_Yb */
	0xdd, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char STANDARD_GALLERY_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x02, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char STANDARD_GALLERY_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char NATURAL_GALLERY_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xda, /* ascr_skin_Rr */
	0x11, /* ascr_skin_Rg */
	0x29, /* ascr_skin_Rb */
	0xf4, /* ascr_skin_Yr */
	0xef, /* ascr_skin_Yg */
	0x5a, /* ascr_skin_Yb */
	0xe4, /* ascr_skin_Mr */
	0x34, /* ascr_skin_Mg */
	0xe6, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xfc, /* ascr_skin_Wg */
	0xf6, /* ascr_skin_Wb */
	0x8a, /* ascr_Cr */
	0xda, /* ascr_Rr */
	0xf4, /* ascr_Cg */
	0x11, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xe4, /* ascr_Mr */
	0x7c, /* ascr_Gr */
	0x34, /* ascr_Mg */
	0xfc, /* ascr_Gg */
	0xe6, /* ascr_Mb */
	0x51, /* ascr_Gb */
	0xf4, /* ascr_Yr */
	0x2c, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x2e, /* ascr_Bg */
	0x5a, /* ascr_Yb */
	0xdf, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfc, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xf6, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char NATURAL_GALLERY_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char NATURAL_GALLERY_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char DYNAMIC_GALLERY_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xde, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xef, /* ascr_skin_Yr */
	0xe7, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xeb, /* ascr_skin_Mr */
	0x16, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x5d, /* ascr_Cr */
	0xde, /* ascr_Rr */
	0xf2, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xea, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xeb, /* ascr_Mr */
	0x50, /* ascr_Gr */
	0x16, /* ascr_Mg */
	0xe3, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xef, /* ascr_Yr */
	0x2e, /* ascr_Br */
	0xe7, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xe2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char DYNAMIC_GALLERY_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char DYNAMIC_GALLERY_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char MOVIE_GALLERY_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char MOVIE_GALLERY_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char MOVIE_GALLERY_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char AUTO_GALLERY_1[] = {
	/* start */
	0xDF,
	0x01, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xff, /* ascr_skin_Rr */
	0x30, /* ascr_skin_Rg */
	0x58, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf0, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xf0, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xf9, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char AUTO_GALLERY_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x0c, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x10,
	0x02, /* de_maxplus 11 */
	0x00,
	0x02, /* de_maxminus 11 */
	0x00,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x01,
	0x00, /* fa_step_n 10 */
	0x01,
	0x00, /* fa_max_de_gain 10 */
	0x10,
	0x00, /* fa_pcl_ppi 14 */
	0x01,
	0x28, /* fa_os_cnt_10_co */
	0x3c, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char AUTO_GALLERY_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

/******************** VIDEO ********************/
static unsigned char STANDARD_VIDEO_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xef, /* ascr_skin_Rr */
	0x32, /* ascr_skin_Rg */
	0x2c, /* ascr_skin_Rb */
	0xf1, /* ascr_skin_Yr */
	0xea, /* ascr_skin_Yg */
	0x40, /* ascr_skin_Yb */
	0xfa, /* ascr_skin_Mr */
	0x40, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xef, /* ascr_Rr */
	0xea, /* ascr_Cg */
	0x32, /* ascr_Rg */
	0xe6, /* ascr_Cb */
	0x2c, /* ascr_Rb */
	0xfa, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x40, /* ascr_Mg */
	0xde, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x30, /* ascr_Gb */
	0xf1, /* ascr_Yr */
	0x2b, /* ascr_Br */
	0xea, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x40, /* ascr_Yb */
	0xdd, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char STANDARD_VIDEO_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x02, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char STANDARD_VIDEO_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char NATURAL_VIDEO_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xda, /* ascr_skin_Rr */
	0x11, /* ascr_skin_Rg */
	0x29, /* ascr_skin_Rb */
	0xf4, /* ascr_skin_Yr */
	0xef, /* ascr_skin_Yg */
	0x5a, /* ascr_skin_Yb */
	0xe4, /* ascr_skin_Mr */
	0x34, /* ascr_skin_Mg */
	0xe6, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xfc, /* ascr_skin_Wg */
	0xf6, /* ascr_skin_Wb */
	0x8a, /* ascr_Cr */
	0xda, /* ascr_Rr */
	0xf4, /* ascr_Cg */
	0x11, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xe4, /* ascr_Mr */
	0x7c, /* ascr_Gr */
	0x34, /* ascr_Mg */
	0xfc, /* ascr_Gg */
	0xe6, /* ascr_Mb */
	0x51, /* ascr_Gb */
	0xf4, /* ascr_Yr */
	0x2c, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x2e, /* ascr_Bg */
	0x5a, /* ascr_Yb */
	0xdf, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfc, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xf6, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char NATURAL_VIDEO_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char NATURAL_VIDEO_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char DYNAMIC_VIDEO_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xde, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xef, /* ascr_skin_Yr */
	0xe7, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xeb, /* ascr_skin_Mr */
	0x16, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x5d, /* ascr_Cr */
	0xde, /* ascr_Rr */
	0xf2, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xea, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xeb, /* ascr_Mr */
	0x50, /* ascr_Gr */
	0x16, /* ascr_Mg */
	0xe3, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xef, /* ascr_Yr */
	0x2e, /* ascr_Br */
	0xe7, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xe2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char DYNAMIC_VIDEO_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char DYNAMIC_VIDEO_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char MOVIE_VIDEO_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char MOVIE_VIDEO_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char MOVIE_VIDEO_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char AUTO_VIDEO_1[] = {
	/* start */
	0xDF,
	0x01, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xff, /* ascr_skin_Rr */
	0x30, /* ascr_skin_Rg */
	0x58, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf0, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xf0, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xf9, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char AUTO_VIDEO_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x0e, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x10,
	0x00, /* de_maxplus 11 */
	0x40,
	0x00, /* de_maxminus 11 */
	0x40,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x01,
	0x00, /* fa_step_n 10 */
	0x01,
	0x00, /* fa_max_de_gain 10 */
	0x10,
	0x00, /* fa_pcl_ppi 14 */
	0x01,
	0x28, /* fa_os_cnt_10_co */
	0x3c, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char AUTO_VIDEO_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

/******************** CAMERA ********************/
static unsigned char STANDARD_CAMERA_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xef, /* ascr_skin_Rr */
	0x32, /* ascr_skin_Rg */
	0x2c, /* ascr_skin_Rb */
	0xf1, /* ascr_skin_Yr */
	0xea, /* ascr_skin_Yg */
	0x40, /* ascr_skin_Yb */
	0xfa, /* ascr_skin_Mr */
	0x40, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xef, /* ascr_Rr */
	0xea, /* ascr_Cg */
	0x32, /* ascr_Rg */
	0xe6, /* ascr_Cb */
	0x2c, /* ascr_Rb */
	0xfa, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x40, /* ascr_Mg */
	0xde, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x30, /* ascr_Gb */
	0xf1, /* ascr_Yr */
	0x2b, /* ascr_Br */
	0xea, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x40, /* ascr_Yb */
	0xdd, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char STANDARD_CAMERA_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x02, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char STANDARD_CAMERA_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char NATURAL_CAMERA_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xda, /* ascr_skin_Rr */
	0x11, /* ascr_skin_Rg */
	0x29, /* ascr_skin_Rb */
	0xf4, /* ascr_skin_Yr */
	0xef, /* ascr_skin_Yg */
	0x5a, /* ascr_skin_Yb */
	0xe4, /* ascr_skin_Mr */
	0x34, /* ascr_skin_Mg */
	0xe6, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xfc, /* ascr_skin_Wg */
	0xf6, /* ascr_skin_Wb */
	0x8a, /* ascr_Cr */
	0xda, /* ascr_Rr */
	0xf4, /* ascr_Cg */
	0x11, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xe4, /* ascr_Mr */
	0x7c, /* ascr_Gr */
	0x34, /* ascr_Mg */
	0xfc, /* ascr_Gg */
	0xe6, /* ascr_Mb */
	0x51, /* ascr_Gb */
	0xf4, /* ascr_Yr */
	0x2c, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x2e, /* ascr_Bg */
	0x5a, /* ascr_Yb */
	0xdf, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfc, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xf6, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char NATURAL_CAMERA_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char NATURAL_CAMERA_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char DYNAMIC_CAMERA_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xde, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xef, /* ascr_skin_Yr */
	0xe7, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xeb, /* ascr_skin_Mr */
	0x16, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x5d, /* ascr_Cr */
	0xde, /* ascr_Rr */
	0xf2, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xea, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xeb, /* ascr_Mr */
	0x50, /* ascr_Gr */
	0x16, /* ascr_Mg */
	0xe3, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xef, /* ascr_Yr */
	0x2e, /* ascr_Br */
	0xe7, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xe2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char DYNAMIC_CAMERA_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char DYNAMIC_CAMERA_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char MOVIE_CAMERA_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char MOVIE_CAMERA_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char MOVIE_CAMERA_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char AUTO_CAMERA_1[] = {
	/* start */
	0xDF,
	0x01, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xff, /* ascr_skin_Rr */
	0x30, /* ascr_skin_Rg */
	0x58, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf0, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xf0, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xf9, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char AUTO_CAMERA_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x0c, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x28,
	0x00, /* de_maxplus 11 */
	0xa0,
	0x00, /* de_maxminus 11 */
	0xa0,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x01,
	0x00, /* fa_step_n 10 */
	0x01,
	0x00, /* fa_max_de_gain 10 */
	0x28,
	0x00, /* fa_pcl_ppi 14 */
	0x01,
	0x28, /* fa_os_cnt_10_co */
	0x3c, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char AUTO_CAMERA_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

/******************** BROWSER ********************/
static unsigned char STANDARD_BROWSER_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xef, /* ascr_skin_Rr */
	0x32, /* ascr_skin_Rg */
	0x2c, /* ascr_skin_Rb */
	0xf1, /* ascr_skin_Yr */
	0xea, /* ascr_skin_Yg */
	0x40, /* ascr_skin_Yb */
	0xfa, /* ascr_skin_Mr */
	0x40, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xef, /* ascr_Rr */
	0xea, /* ascr_Cg */
	0x32, /* ascr_Rg */
	0xe6, /* ascr_Cb */
	0x2c, /* ascr_Rb */
	0xfa, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x40, /* ascr_Mg */
	0xde, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x30, /* ascr_Gb */
	0xf1, /* ascr_Yr */
	0x2b, /* ascr_Br */
	0xea, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x40, /* ascr_Yb */
	0xdd, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char STANDARD_BROWSER_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x02, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char STANDARD_BROWSER_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char NATURAL_BROWSER_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xda, /* ascr_skin_Rr */
	0x11, /* ascr_skin_Rg */
	0x29, /* ascr_skin_Rb */
	0xf4, /* ascr_skin_Yr */
	0xef, /* ascr_skin_Yg */
	0x5a, /* ascr_skin_Yb */
	0xe4, /* ascr_skin_Mr */
	0x34, /* ascr_skin_Mg */
	0xe6, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xfc, /* ascr_skin_Wg */
	0xf6, /* ascr_skin_Wb */
	0x8a, /* ascr_Cr */
	0xda, /* ascr_Rr */
	0xf4, /* ascr_Cg */
	0x11, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xe4, /* ascr_Mr */
	0x7c, /* ascr_Gr */
	0x34, /* ascr_Mg */
	0xfc, /* ascr_Gg */
	0xe6, /* ascr_Mb */
	0x51, /* ascr_Gb */
	0xf4, /* ascr_Yr */
	0x2c, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x2e, /* ascr_Bg */
	0x5a, /* ascr_Yb */
	0xdf, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfc, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xf6, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char NATURAL_BROWSER_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char NATURAL_BROWSER_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char DYNAMIC_BROWSER_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xde, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xef, /* ascr_skin_Yr */
	0xe7, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xeb, /* ascr_skin_Mr */
	0x16, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x5d, /* ascr_Cr */
	0xde, /* ascr_Rr */
	0xf2, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xea, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xeb, /* ascr_Mr */
	0x50, /* ascr_Gr */
	0x16, /* ascr_Mg */
	0xe3, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xef, /* ascr_Yr */
	0x2e, /* ascr_Br */
	0xe7, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xe2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char DYNAMIC_BROWSER_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char DYNAMIC_BROWSER_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char MOVIE_BROWSER_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char MOVIE_BROWSER_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char MOVIE_BROWSER_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char AUTO_BROWSER_1[] = {
	/* start */
	0xDF,
	0x01, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xff, /* ascr_skin_Rr */
	0x30, /* ascr_skin_Rg */
	0x58, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf0, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xf0, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xf9, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char AUTO_BROWSER_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char AUTO_BROWSER_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

/******************** eBOOK ********************/
static unsigned char STANDARD_EBOOK_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xef, /* ascr_skin_Rr */
	0x32, /* ascr_skin_Rg */
	0x2c, /* ascr_skin_Rb */
	0xf1, /* ascr_skin_Yr */
	0xea, /* ascr_skin_Yg */
	0x40, /* ascr_skin_Yb */
	0xfa, /* ascr_skin_Mr */
	0x40, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xef, /* ascr_Rr */
	0xea, /* ascr_Cg */
	0x32, /* ascr_Rg */
	0xe6, /* ascr_Cb */
	0x2c, /* ascr_Rb */
	0xfa, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x40, /* ascr_Mg */
	0xde, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x30, /* ascr_Gb */
	0xf1, /* ascr_Yr */
	0x2b, /* ascr_Br */
	0xea, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x40, /* ascr_Yb */
	0xdd, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char STANDARD_EBOOK_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char STANDARD_EBOOK_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char DYNAMIC_EBOOK_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xde, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xef, /* ascr_skin_Yr */
	0xe7, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xeb, /* ascr_skin_Mr */
	0x16, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x5d, /* ascr_Cr */
	0xde, /* ascr_Rr */
	0xf2, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xea, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xeb, /* ascr_Mr */
	0x50, /* ascr_Gr */
	0x16, /* ascr_Mg */
	0xe3, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xef, /* ascr_Yr */
	0x2e, /* ascr_Br */
	0xe7, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xe2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char DYNAMIC_EBOOK_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char DYNAMIC_EBOOK_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char NATURAL_EBOOK_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xda, /* ascr_skin_Rr */
	0x11, /* ascr_skin_Rg */
	0x29, /* ascr_skin_Rb */
	0xf4, /* ascr_skin_Yr */
	0xef, /* ascr_skin_Yg */
	0x5a, /* ascr_skin_Yb */
	0xe4, /* ascr_skin_Mr */
	0x34, /* ascr_skin_Mg */
	0xe6, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xfc, /* ascr_skin_Wg */
	0xf6, /* ascr_skin_Wb */
	0x8a, /* ascr_Cr */
	0xda, /* ascr_Rr */
	0xf4, /* ascr_Cg */
	0x11, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xe4, /* ascr_Mr */
	0x7c, /* ascr_Gr */
	0x34, /* ascr_Mg */
	0xfc, /* ascr_Gg */
	0xe6, /* ascr_Mb */
	0x51, /* ascr_Gb */
	0xf4, /* ascr_Yr */
	0x2c, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x2e, /* ascr_Bg */
	0x5a, /* ascr_Yb */
	0xdf, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfc, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xf6, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char NATURAL_EBOOK_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char NATURAL_EBOOK_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char MOVIE_EBOOK_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char MOVIE_EBOOK_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char MOVIE_EBOOK_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char AUTO_EBOOK_1[] = {
	/* start */
	0xDF,
	0x01, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf6, /* ascr_skin_Wg */
	0xe6, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf6, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xe6, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char AUTO_EBOOK_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char AUTO_EBOOK_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char AUTO_EMAIL_1[] = {
	/* start */
	0xDF,
	0x01, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf5, /* ascr_skin_Wg */
	0xe4, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf5, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xe4, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char AUTO_EMAIL_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char AUTO_EMAIL_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

/******************** DMB ********************/
static unsigned char STANDARD_DMB_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xef, /* ascr_skin_Rr */
	0x32, /* ascr_skin_Rg */
	0x2c, /* ascr_skin_Rb */
	0xf1, /* ascr_skin_Yr */
	0xea, /* ascr_skin_Yg */
	0x40, /* ascr_skin_Yb */
	0xfa, /* ascr_skin_Mr */
	0x40, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xef, /* ascr_Rr */
	0xea, /* ascr_Cg */
	0x32, /* ascr_Rg */
	0xe6, /* ascr_Cb */
	0x2c, /* ascr_Rb */
	0xfa, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x40, /* ascr_Mg */
	0xde, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x30, /* ascr_Gb */
	0xf1, /* ascr_Yr */
	0x2b, /* ascr_Br */
	0xea, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x40, /* ascr_Yb */
	0xdd, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char STANDARD_DMB_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x02, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char STANDARD_DMB_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char NATURAL_DMB_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xda, /* ascr_skin_Rr */
	0x11, /* ascr_skin_Rg */
	0x29, /* ascr_skin_Rb */
	0xf4, /* ascr_skin_Yr */
	0xef, /* ascr_skin_Yg */
	0x5a, /* ascr_skin_Yb */
	0xe4, /* ascr_skin_Mr */
	0x34, /* ascr_skin_Mg */
	0xe6, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xfc, /* ascr_skin_Wg */
	0xf6, /* ascr_skin_Wb */
	0x8a, /* ascr_Cr */
	0xda, /* ascr_Rr */
	0xf4, /* ascr_Cg */
	0x11, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xe4, /* ascr_Mr */
	0x7c, /* ascr_Gr */
	0x34, /* ascr_Mg */
	0xfc, /* ascr_Gg */
	0xe6, /* ascr_Mb */
	0x51, /* ascr_Gb */
	0xf4, /* ascr_Yr */
	0x2c, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x2e, /* ascr_Bg */
	0x5a, /* ascr_Yb */
	0xdf, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfc, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xf6, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char NATURAL_DMB_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char NATURAL_DMB_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char DYNAMIC_DMB_1[] = {
	/* start */
	0xDF,
	0x11, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xde, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xef, /* ascr_skin_Yr */
	0xe7, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xeb, /* ascr_skin_Mr */
	0x16, /* ascr_skin_Mg */
	0xe5, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf7, /* ascr_skin_Wg */
	0xef, /* ascr_skin_Wb */
	0x5d, /* ascr_Cr */
	0xde, /* ascr_Rr */
	0xf2, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xea, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xeb, /* ascr_Mr */
	0x50, /* ascr_Gr */
	0x16, /* ascr_Mg */
	0xe3, /* ascr_Gg */
	0xe5, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xef, /* ascr_Yr */
	0x2e, /* ascr_Br */
	0xe7, /* ascr_Yg */
	0x2c, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xe2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xf7, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char DYNAMIC_DMB_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x20,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char DYNAMIC_DMB_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char MOVIE_DMB_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char MOVIE_DMB_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char MOVIE_DMB_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char AUTO_DMB_1[] = {
	/* start */
	0xDF,
	0x01, /* linear_on ascr_skin_on 0000 0000 */
	0x6a, /* ascr_skin_cb */
	0x9a, /* ascr_skin_cr */
	0x25, /* ascr_dist_up */
	0x1a, /* ascr_dist_down */
	0x16, /* ascr_dist_right */
	0x2a, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0x37,
	0x5a,
	0x00, /* ascr_div_down */
	0x4e,
	0xc5,
	0x00, /* ascr_div_right */
	0x5d,
	0x17,
	0x00, /* ascr_div_left */
	0x30,
	0xc3,
	0xff, /* ascr_skin_Rr */
	0x30, /* ascr_skin_Rg */
	0x58, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf0, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xf0, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xf9, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char AUTO_DMB_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x0c, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x10,
	0x02, /* de_maxplus 11 */
	0x00,
	0x02, /* de_maxminus 11 */
	0x00,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x01,
	0x00, /* fa_step_n 10 */
	0x01,
	0x00, /* fa_max_de_gain 10 */
	0x10,
	0x00, /* fa_pcl_ppi 14 */
	0x01,
	0x28, /* fa_os_cnt_10_co */
	0x3c, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char AUTO_DMB_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char HMT_GRAY_8_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char HMT_GRAY_8_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char HMT_GRAY_8_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char HMT_GRAY_16_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char HMT_GRAY_16_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char HMT_GRAY_16_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

#ifdef CONFIG_LCD_HMT
static unsigned char HMT_3000K_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xc8, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0x82, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char HMT_3000K_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char HMT_3000K_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char HMT_4000K_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xde, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xb0, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char HMT_4000K_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char HMT_4000K_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char HMT_5000K_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xed, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xcf, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char HMT_5000K_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char HMT_5000K_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};

static unsigned char HMT_6500K_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xf0, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char HMT_6500K_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x00, /* slce_on cadrx_en 0000 0000 */
	0x00, /* lce_gain 000 0000 */
	0x30, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x20,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x00, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x0a, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x00, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x00, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0xe6, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x02,
	0x00, /* fa_step_n 10 */
	0x02,
	0x01, /* fa_max_de_gain 10 */
	0xf4,
	0x08, /* fa_pcl_ppi 14 */
	0x8a,
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char HMT_6500K_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0xf0, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};
#endif

static unsigned char LOCAL_CE_1[] = {
	/* start */
	0xDF,
	0x00, /* linear_on ascr_skin_on 0000 0000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xff, /* ascr_skin_Rr */
	0x00, /* ascr_skin_Rg */
	0x00, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xff, /* ascr_skin_Yg */
	0x00, /* ascr_skin_Yb */
	0xff, /* ascr_skin_Mr */
	0x00, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xff, /* ascr_skin_Wg */
	0xff, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static unsigned char LOCAL_CE_2[] = {
	0xDE,
	0x00, /* gamut_gamma_on gamut_blk_shift 0000 0000 */
	0x40, /* gamut_scale */
	0x04, /* gamut_r1 */
	0x00,
	0x00, /* gamut_r2 */
	0x00,
	0x00, /* gamut_r3 */
	0x00,
	0x00, /* gamut_g1 */
	0x00,
	0x04, /* gamut_g2 */
	0x00,
	0x00, /* gamut_g3 */
	0x00,
	0x00, /* gamut_b1 */
	0x00,
	0x00, /* gamut_b2 */
	0x00,
	0x04, /* gamut_b3 */
	0x00,
	0x11, /* slce_on cadrx_en 0000 0000 */
	0x2c, /* lce_gain 000 0000 */
	0x20, /* lce_color_gain 00 0000 */
	0x01, /* lce_min_ref_offset */
	0x00,
	0x70, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x34,
	0x01, /* lce_ref_gain 9 */
	0x40,
	0x66, /* lce_block_size h v 0000 0000 */
	0x03, /* lce_dark_th 000 */
	0x01, /* lce_reduct_slope 0000 */
	0x11, /* lce_black cc1 0000 0000 */
	0x00, /* lce_color_th 12 */
	0x26,
	0x08, /* lce_med_w */
	0x08, /* lce_small_w */
	0x06, /* lce_lg_flicker Avg pixel_cnt 000v */
	0x00, /* lce_lg_avg_th */
	0x0a, /* lce_lg_pixel_th */
	0x06, /* lce_lg_pixel_cnt_th 23 */
	0xae,
	0x00,
	0x20, /* lce_lg_mix_weight 7 */
	0x10, /* cadrx_gain */
	0x20, /* cadrx_ui_illum_a1 */
	0x40, /* cadrx_ui_illum_a2 */
	0x60, /* cadrx_ui_illum_a3 */
	0x00, /* cadrx_ui_illum_offset1 */
	0x40,
	0x00, /* cadrx_ui_illum_offset2 */
	0x50,
	0x00, /* cadrx_ui_illum_offset3 */
	0x60,
	0x00, /* cadrx_ui_illum_offset4 */
	0x70,
	0x00, /* cadrx_ui_illum_slope1 */
	0x80,
	0x00, /* cadrx_ui_illum_slope2 */
	0x80,
	0x00, /* cadrx_ui_illum_slope3 */
	0x80,
	0x00, /* cadrx_ui_illum_slope4 */
	0x00,
	0x20, /* cadrx_ui_ref_a1 */
	0x40, /* cadrx_ui_ref_a2 */
	0x60, /* cadrx_ui_ref_a3 */
	0x01, /* cadrx_ui_ref_offset1 */
	0x40,
	0x01, /* cadrx_ui_ref_offset2 */
	0x80,
	0x01, /* cadrx_ui_ref_offset3 */
	0x80,
	0x01, /* cadrx_ui_ref_offset4 */
	0x80,
	0x02, /* cadrx_ui_ref_slope1 */
	0x00,
	0x00, /* cadrx_ui_ref_slope2 */
	0x00,
	0x00, /* cadrx_ui_ref_slope3 */
	0x00,
	0x00, /* cadrx_ui_ref_slope4 */
	0x00,
	0x07, /* bi_filter_en bi_en bcr_en 000 */
	0x40, /* reduce_halo_neg */
	0x40, /* reduce_halo_pos */
	0x6e, /* neg_bi_min */
	0x82, /* neg_bi_max */
	0x00, /* pos_bi_min */
	0xff, /* pos_bi_max */
	0x02, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x02, /* de_maxplus 11 */
	0x00,
	0x02, /* de_maxminus 11 */
	0x00,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 10 */
	0x01,
	0x00, /* fa_step_n 10 */
	0x01,
	0x00, /* fa_max_de_gain 10 */
	0x10,
	0x00, /* fa_pcl_ppi 14 */
	0x00,
	0x28, /* fa_os_cnt_10_co */
	0x3c, /* fa_os_cnt_20_co */
	0x04, /* fa_edge_cnt */
	0x0f, /* fa_AVG_y_cnt */
	0x01, /* cs_gain 10 */
	0x30,
	0x00, /* gamma_x_0 */
	0x08, /* gamma_x_1 */
	0x10, /* gamma_x_2 */
	0x18, /* gamma_x_3 */
	0x20, /* gamma_x_4 */
	0x28, /* gamma_x_5 */
	0x30, /* gamma_x_6 */
	0x38, /* gamma_x_7 */
	0x40, /* gamma_x_8 */
	0x48, /* gamma_x_9 */
	0x50, /* gamma_x_10 */
	0x58, /* gamma_x_11 */
	0x60, /* gamma_x_12 */
	0x68, /* gamma_x_13 */
	0x70, /* gamma_x_14 */
	0x78, /* gamma_x_15 */
	0x80, /* gamma_x_16 */
	0x88, /* gamma_x_17 */
	0x90, /* gamma_x_18 */
	0x98, /* gamma_x_19 */
	0xa0, /* gamma_x_20 */
	0xa8, /* gamma_x_21 */
	0xb0, /* gamma_x_22 */
	0xb8, /* gamma_x_23 */
	0xc0, /* gamma_x_24 */
	0xc8, /* gamma_x_25 */
	0xd0, /* gamma_x_26 */
	0xd8, /* gamma_x_27 */
	0xe0, /* gamma_x_28 */
	0xe8, /* gamma_x_29 */
	0xf0, /* gamma_x_30 */
	0xf8, /* gamma_x_31 */
	0x01, /* gamma_x_32 */
	0x00,
	0x00, /* gamma_y_0 */
	0x08, /* gamma_y_1 */
	0x10, /* gamma_y_2 */
	0x18, /* gamma_y_3 */
	0x20, /* gamma_y_4 */
	0x28, /* gamma_y_5 */
	0x30, /* gamma_y_6 */
	0x38, /* gamma_y_7 */
	0x40, /* gamma_y_8 */
	0x48, /* gamma_y_9 */
	0x50, /* gamma_y_10 */
	0x58, /* gamma_y_11 */
	0x60, /* gamma_y_12 */
	0x68, /* gamma_y_13 */
	0x70, /* gamma_y_14 */
	0x78, /* gamma_y_15 */
	0x80, /* gamma_y_16 */
	0x88, /* gamma_y_17 */
	0x90, /* gamma_y_18 */
	0x98, /* gamma_y_19 */
	0xa0, /* gamma_y_20 */
	0xa8, /* gamma_y_21 */
	0xb0, /* gamma_y_22 */
	0xb8, /* gamma_y_23 */
	0xc0, /* gamma_y_24 */
	0xc8, /* gamma_y_25 */
	0xd0, /* gamma_y_26 */
	0xd8, /* gamma_y_27 */
	0xe0, /* gamma_y_28 */
	0xe8, /* gamma_y_29 */
	0xf0, /* gamma_y_30 */
	0xf8, /* gamma_y_31 */
	0x01, /* gamma_y_32 */
	0x00,
};

static unsigned char LOCAL_CE_3[] = {
	0xDD,
	0x01, /* mdnie_en */
	0x00, /* mask 00 0000 */
	0x00, /* ascr algo aolce gamut 00 00 00 00 */
	0x07, /* v_partial_on */
	0x7f, /* partial_en1 */
	0x7f, /* partial_en2 */
	0x00, /* roi_en */
	0x00, /* roi_block */
	0x00, /* roi_sx */
	0x00, /* roi_sx */
	0x00, /* roi_sy */
	0x00, /* roi_sy */
	0x00, /* roi_ex */
	0x00, /* roi_ex */
	0x00, /* roi_ey */
	0x00, /* roi_ey */
	0x7f, /* trans_on trans_block 0000 0000 */
	0x04, /* trans_slope */
	0x01, /* trans_interval */
	/* end */
};


static unsigned char LEVEL_UNLOCK[] = {
	0xF0,
	0x5A, 0x5A
};

static unsigned char LEVEL_LOCK[] = {
	0xF0,
	0xA5, 0xA5
};

#define MDNIE_SET(id)	\
{							\
	.name		= #id,				\
	.update_flag	= {0, 1, 2, 3, 0},			\
	.seq		= {				\
		{	.cmd = LEVEL_UNLOCK,	.len = ARRAY_SIZE(LEVEL_UNLOCK),	.sleep = 0,},	\
		{	.cmd = id##_1,		.len = ARRAY_SIZE(id##_1),		.sleep = 0,},	\
		{	.cmd = id##_2,		.len = ARRAY_SIZE(id##_2),		.sleep = 0,},	\
		{	.cmd = id##_3,		.len = ARRAY_SIZE(id##_3),		.sleep = 0,},	\
		{	.cmd = LEVEL_LOCK,	.len = ARRAY_SIZE(LEVEL_LOCK),		.sleep = 0,},	\
	}	\
}

static struct mdnie_table bypass_table[BYPASS_MAX] = {
	[BYPASS_ON] = MDNIE_SET(BYPASS)
};

static struct mdnie_table accessibility_table[ACCESSIBILITY_MAX] = {
	[NEGATIVE] = MDNIE_SET(NEGATIVE),
	MDNIE_SET(COLOR_BLIND),
	MDNIE_SET(SCREEN_CURTAIN),
	MDNIE_SET(GRAYSCALE),
	MDNIE_SET(GRAYSCALE_NEGATIVE)
};

static struct mdnie_table hbm_table[HBM_MAX] = {
	[HBM_ON] = MDNIE_SET(LOCAL_CE)
};

#ifdef CONFIG_LCD_HMT
static struct mdnie_table hmt_table[HMT_MDNIE_MAX] = {
	[HMT_MDNIE_ON] = MDNIE_SET(HMT_3000K),
	MDNIE_SET(HMT_4000K),
	MDNIE_SET(HMT_5000K),
	MDNIE_SET(HMT_6500K)
};
#endif

static struct mdnie_table dmb_table[MODE_MAX] = {
	MDNIE_SET(DYNAMIC_DMB),
	MDNIE_SET(STANDARD_DMB),
	MDNIE_SET(NATURAL_DMB),
	MDNIE_SET(MOVIE_DMB),
	MDNIE_SET(AUTO_DMB),
	MDNIE_SET(AUTO_EBOOK)
};

static struct mdnie_table night_table[NIGHT_MODE_MAX] = {
	[NIGHT_MODE_ON] = MDNIE_SET(NIGHT_MODE)
};

static struct mdnie_table lens_table[COLOR_LENS_MAX] = {
	[COLOR_LENS_ON] = MDNIE_SET(COLOR_LENS)
};

static struct mdnie_table light_notification_table[LIGHT_NOTIFICATION_MAX] = {
	[LIGHT_NOTIFICATION_ON] = MDNIE_SET(LIGHT_NOTIFICATION)
};

static struct mdnie_table main_table[SCENARIO_MAX][MODE_MAX] = {
	{
		MDNIE_SET(DYNAMIC_UI),
		MDNIE_SET(STANDARD_UI),
		MDNIE_SET(NATURAL_UI),
		MDNIE_SET(MOVIE_UI),
		MDNIE_SET(AUTO_UI),
		MDNIE_SET(AUTO_EBOOK)
	}, {
		MDNIE_SET(DYNAMIC_VIDEO),
		MDNIE_SET(STANDARD_VIDEO),
		MDNIE_SET(NATURAL_VIDEO),
		MDNIE_SET(MOVIE_VIDEO),
		MDNIE_SET(AUTO_VIDEO),
		MDNIE_SET(AUTO_EBOOK)
	},
	[CAMERA_MODE] = {
		MDNIE_SET(DYNAMIC_CAMERA),
		MDNIE_SET(STANDARD_CAMERA),
		MDNIE_SET(NATURAL_CAMERA),
		MDNIE_SET(MOVIE_CAMERA),
		MDNIE_SET(AUTO_CAMERA),
		MDNIE_SET(AUTO_EBOOK)
	},
	[GALLERY_MODE] = {
		MDNIE_SET(DYNAMIC_GALLERY),
		MDNIE_SET(STANDARD_GALLERY),
		MDNIE_SET(NATURAL_GALLERY),
		MDNIE_SET(MOVIE_GALLERY),
		MDNIE_SET(AUTO_GALLERY),
		MDNIE_SET(AUTO_EBOOK)
	}, {
		MDNIE_SET(DYNAMIC_GALLERY),
		MDNIE_SET(STANDARD_GALLERY),
		MDNIE_SET(NATURAL_GALLERY),
		MDNIE_SET(MOVIE_GALLERY),
		MDNIE_SET(AUTO_GALLERY),
		MDNIE_SET(AUTO_EBOOK)
	}, {
		MDNIE_SET(DYNAMIC_BROWSER),
		MDNIE_SET(STANDARD_BROWSER),
		MDNIE_SET(NATURAL_BROWSER),
		MDNIE_SET(MOVIE_BROWSER),
		MDNIE_SET(AUTO_BROWSER),
		MDNIE_SET(AUTO_EBOOK)
	}, {
		MDNIE_SET(DYNAMIC_EBOOK),
		MDNIE_SET(STANDARD_EBOOK),
		MDNIE_SET(NATURAL_EBOOK),
		MDNIE_SET(MOVIE_EBOOK),
		MDNIE_SET(AUTO_EBOOK),
		MDNIE_SET(AUTO_EBOOK)
	}, {
		MDNIE_SET(AUTO_EMAIL),
		MDNIE_SET(AUTO_EMAIL),
		MDNIE_SET(AUTO_EMAIL),
		MDNIE_SET(AUTO_EMAIL),
		MDNIE_SET(AUTO_EMAIL),
		MDNIE_SET(AUTO_EBOOK)
	}, {
		MDNIE_SET(HMT_GRAY_8),
		MDNIE_SET(HMT_GRAY_8),
		MDNIE_SET(HMT_GRAY_8),
		MDNIE_SET(HMT_GRAY_8),
		MDNIE_SET(HMT_GRAY_8),
		MDNIE_SET(HMT_GRAY_8)
	}, {
		MDNIE_SET(HMT_GRAY_16),
		MDNIE_SET(HMT_GRAY_16),
		MDNIE_SET(HMT_GRAY_16),
		MDNIE_SET(HMT_GRAY_16),
		MDNIE_SET(HMT_GRAY_16),
		MDNIE_SET(HMT_GRAY_16)
	}
};

#undef MDNIE_SET

static struct mdnie_tune tune_info = {
	.bypass_table = bypass_table,
	.accessibility_table = accessibility_table,
	.hbm_table = hbm_table,
	.night_table = night_table,
	.lens_table = lens_table,
	.light_notification_table = light_notification_table,

#ifdef CONFIG_LCD_HMT
	.hmt_table = hmt_table,
#endif
	.dmb_table = dmb_table,
	.main_table = main_table,

	.coordinate_table = coordinate_data,
	.adjust_ldu_table = adjust_ldu_data,
	.night_mode_table = night_mode_data,
	.color_lens_table = color_lens_data,
	.scr_info = &scr_info,
	.get_hbm_index = get_hbm_index,
	.trans_info = &trans_info,
	.night_info = &night_info,
	.color_lens_info = &color_lens_info,
	.color_offset = {NULL, color_offset_f1, color_offset_f2, color_offset_f3, color_offset_f4}
};
#endif