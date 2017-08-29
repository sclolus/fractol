/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.cl                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 07:20:00 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/29 08:50:32 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BASE_COLOR 0x101010

typedef struct	s_complexe
{
	double	real_part;
	double	imaginary_part;
}				t_complexe;

typedef struct	s_complexe_cadran
{
	t_complexe	min;
	t_complexe	max;
}				t_complexe_cadran;

typedef struct	s_color_point
{
	t_complexe	point;
	int			color;
}				t_color_point;

typedef struct	s_color_cadran
{
	t_color_point	x0_y0;
	t_color_point	x1_y0;
	t_color_point	x0_y1;
	t_color_point	x1_y1;
}				t_color_cadran;

# define INTERPOLATION_X1 -2.0
# define INTERPOLATION_X2 1.0
# define INTERPOLATION_Y1 -1.0
# define INTERPOLATION_Y2 1.0

/* const __constant t_color_cadran	color_cadran = { */
/* 	{{INTERPOLATION_X1, INTERPOLATION_Y1}, 0x0000CCFF}, */
/* 	{{INTERPOLATION_X2, INTERPOLATION_Y1}, 0x00FF55FF}, */
/* 	{{INTERPOLATION_X1, INTERPOLATION_Y2}, 0x00C000CC}, */
/* 	{{INTERPOLATION_X2, INTERPOLATION_Y2}, 0x0000AAFF}, */
/* }; */

/* const __constant t_color_cadran	color_cadran = { */
/* 	{{INTERPOLATION_X1, INTERPOLATION_Y1}, 0x00010101}, */
/* 	{{INTERPOLATION_X2, INTERPOLATION_Y1}, 0x00FA0000}, */
/* 	{{INTERPOLATION_X1, INTERPOLATION_Y2}, 0x00C000CC}, */
/* 	{{INTERPOLATION_X2, INTERPOLATION_Y2}, 0x00101010}, */
/* }; */

/*
** Nice spyche
*/

/* const __constant t_color_cadran	color_cadran = { */
/* 	{{INTERPOLATION_X1, INTERPOLATION_Y1}, 0x001F0000}, */
/* 	{{INTERPOLATION_X2, INTERPOLATION_Y1}, 0x0000CF00}, */
/* 	{{INTERPOLATION_X1, INTERPOLATION_Y2}, 0x000000AF}, */
/* 	{{INTERPOLATION_X2, INTERPOLATION_Y2}, 0x00101010}, */
/* }; */

/*
** COOL COLORS APPROVED BY ASIA
*/

const __constant t_color_cadran	color_cadran = {
	{{INTERPOLATION_X1, INTERPOLATION_Y1}, 0x00FF0000},
	{{INTERPOLATION_X2, INTERPOLATION_Y1}, 0x0000AA00},
	{{INTERPOLATION_X1, INTERPOLATION_Y2}, 0x000000FF},
	{{INTERPOLATION_X2, INTERPOLATION_Y2}, 0x00FF0000},
};

//0x110000

# define INTERPOLATION_DX(x) (x - INTERPOLATION_X1)
# define INTERPOLATION_DY(y) (y - INTERPOLATION_Y1)

# define EXTRACT_RED(x) (x & 0xFF0000)
# define EXTRACT_GREEN(x) (x & 0x00FF00)
# define EXTRACT_BLUE(x) (x & 0x0000FF)

# define DELTA_INTERPOLATION_X_R (EXTRACT_RED(color_cadran.x1_y0.color) - EXTRACT_RED(color_cadran.x0_y0.color))
# define DELTA_INTERPOLATION_Y_R (EXTRACT_RED(color_cadran.x0_y1.color) - EXTRACT_RED(color_cadran.x0_y0.color))
# define DELTA_INTERPOLATION_XY_R (EXTRACT_RED(color_cadran.x0_y0.color) + EXTRACT_RED(color_cadran.x1_y1.color) \
								 - EXTRACT_RED(color_cadran.x1_y0.color) - EXTRACT_RED(color_cadran.x0_y1.color))

# define DELTA_INTERPOLATION_X_G (EXTRACT_GREEN(color_cadran.x1_y0.color) - EXTRACT_GREEN(color_cadran.x0_y0.color))
# define DELTA_INTERPOLATION_Y_G (EXTRACT_GREEN(color_cadran.x0_y1.color) - EXTRACT_GREEN(color_cadran.x0_y0.color))
# define DELTA_INTERPOLATION_XY_G (EXTRACT_GREEN(color_cadran.x0_y0.color) + EXTRACT_GREEN(color_cadran.x1_y1.color) \
								 - EXTRACT_GREEN(color_cadran.x1_y0.color) - EXTRACT_GREEN(color_cadran.x0_y1.color))

# define DELTA_INTERPOLATION_X_B (EXTRACT_BLUE(color_cadran.x1_y0.color) - EXTRACT_BLUE(color_cadran.x0_y0.color))
# define DELTA_INTERPOLATION_Y_B (EXTRACT_BLUE(color_cadran.x0_y1.color) - EXTRACT_BLUE(color_cadran.x0_y0.color))
# define DELTA_INTERPOLATION_XY_B (EXTRACT_BLUE(color_cadran.x0_y0.color) + EXTRACT_BLUE(color_cadran.x1_y1.color) \
								 - EXTRACT_BLUE(color_cadran.x1_y0.color) - EXTRACT_BLUE(color_cadran.x0_y1.color))

# define DELTA_X (INTERPOLATION_X2 - INTERPOLATION_X1)
# define DELTA_Y (INTERPOLATION_Y2 - INTERPOLATION_Y1)

# define LINEAR_X1 -0
# define LINEAR_X2 1
# define LINEAR_Y1 0xFF0000
# define LINEAR_Y2 0xFF0CA0
# define LINEAR_INTERPOLATION(x) (((((int)((LINEAR_X2 - x) / (LINEAR_X2 - LINEAR_X1)) * EXTRACT_RED(LINEAR_Y1)) \
										+ (int)(((x - LINEAR_X1) / (LINEAR_X2 - LINEAR_X1)) * EXTRACT_RED(LINEAR_Y2))) & 0xFF0000) \
								  | ((((int)(((LINEAR_X2 - x) / (LINEAR_X2 - LINEAR_X1)) * EXTRACT_GREEN(LINEAR_Y1)) \
									   + (int)(((x - LINEAR_X1) / (LINEAR_X2 - LINEAR_X1)) * EXTRACT_GREEN(LINEAR_Y2)))) & 0x00FF00) \
								  | ((((int)(((LINEAR_X2 - x) / (LINEAR_X2 - LINEAR_X1)) * EXTRACT_BLUE(LINEAR_Y1)) \
									   + (int)(((x - LINEAR_X1) / (LINEAR_X2 - LINEAR_X1)) * EXTRACT_BLUE(LINEAR_Y2)))) & 0x0000FF))

# define BILINEAR_INTERPOLATION(c) (((int)((DELTA_INTERPOLATION_X_R) * (INTERPOLATION_DX(c.real_part) / DELTA_X) \
									+ (DELTA_INTERPOLATION_Y_R) * (INTERPOLATION_DY(c.imaginary_part) / DELTA_Y) \
									+ (DELTA_INTERPOLATION_XY_R) * (INTERPOLATION_DX(c.real_part) / DELTA_X) \
									* (INTERPOLATION_DY(c.imaginary_part) / DELTA_Y) \
										   + EXTRACT_RED(color_cadran.x0_y0.color)) & 0xFF0000) \
									| ((int)((DELTA_INTERPOLATION_X_G) * (INTERPOLATION_DX(c.real_part) / DELTA_X) \
									+ (DELTA_INTERPOLATION_Y_G) * (INTERPOLATION_DY(c.imaginary_part) / DELTA_Y) \
									+ (DELTA_INTERPOLATION_XY_G) * (INTERPOLATION_DX(c.real_part) / DELTA_X) \
									* (INTERPOLATION_DY(c.imaginary_part) / DELTA_Y) \
											+ EXTRACT_GREEN(color_cadran.x0_y0.color)) & 0x00FF00) \
									| ((int)((DELTA_INTERPOLATION_X_B) * (INTERPOLATION_DX(c.real_part) / DELTA_X) \
									+ (DELTA_INTERPOLATION_Y_B) * (INTERPOLATION_DY(c.imaginary_part) / DELTA_Y) \
									+ (DELTA_INTERPOLATION_XY_B) * (INTERPOLATION_DX(c.real_part) / DELTA_X) \
									* (INTERPOLATION_DY(c.imaginary_part) / DELTA_Y) \
											 + EXTRACT_BLUE(color_cadran.x0_y0.color)) & 0x0000FF))
# define ITERATION_CHECK(c) ({ n = 1; \
		tmp = z; \
		while (n < degree) \
		{ \
			z = (t_complexe){z.real_part * tmp.real_part - (z.imaginary_part * tmp.imaginary_part), \
							 z.real_part * tmp.imaginary_part + tmp.real_part * z.imaginary_part}; \
			n++; \
		} \
		z.real_part += c.real_part; \
		z.imaginary_part += c.imaginary_part; \
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4) \
		{ \
			buffer[(pos_y * (width)) + pos_x] = ((BILINEAR_INTERPOLATION(c) * i) & 0xFFFFFF); \
			return ; \
		} \
		i++;})

__kernel void multibrot(__global __write_only int * restrict buffer
						 , const int width
						 , const int height, const t_complexe_cadran cadran
						 , const unsigned int iteration_number, const t_complexe distance
						 , const unsigned int degree)
{
	t_complexe						c;
	t_complexe						tmp;
	const int						pos_x = get_global_id(0);
	const int						pos_y = get_global_id(1);
	t_complexe						z;
	unsigned int					i;
	unsigned int					n;

	c = (t_complexe){cadran.min.real_part + (distance.real_part) * pos_x
					 , cadran.min.imaginary_part + (distance.imaginary_part) * pos_y};
	i = 0;
	z = (t_complexe){0, 0};
	while (i < (iteration_number & 15))
		ITERATION_CHECK(c);
	while (i < iteration_number)
	{
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
		ITERATION_CHECK(c);
	}
	buffer[(pos_y * (width)) + pos_x] = 0;
}
