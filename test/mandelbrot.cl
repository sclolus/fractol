//# define BASE_COLOR 0xA0010A
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

__kernel void mandelbrot(__global __write_only int * restrict buffer, const int width
						 , const int height, const t_complexe_cadran cadran
						 , const unsigned int iteration_number, const t_complexe distance)
{
	t_complexe						c;
	const int						global_id = get_global_id(0);
	const int						pos_x = global_id % width;
	const int						pos_y = global_id / width;
	t_complexe						z;
	unsigned int					i;

	c = (t_complexe){cadran.min.real_part +  (distance.real_part) * pos_x
					 , cadran.min.imaginary_part + (distance.imaginary_part) * pos_y};
	i = 0;
	z = (t_complexe){0, 0};
	while (i < (iteration_number & 15))
	{
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		i++;
	}
	while (i < iteration_number)
	{
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};

	if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i)) * BASE_COLOR  ) & 0xFFFFFF;
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i  + 1) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 2) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 3) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};

	if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 4)) * BASE_COLOR  ) & 0xFFFFFF;
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 5) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 6) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 7) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};

	if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
	{
		buffer[(pos_y * (width)) + pos_x] = (((i + 8)) * BASE_COLOR  ) & 0xFFFFFF;
		return ;
	}
	z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
												  * z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
	z = (t_complexe){z.real_part + c.real_part
					 , z.imaginary_part + c.imaginary_part};
	if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
	{
		buffer[(pos_y * (width)) + pos_x] = (((i  + 9) * BASE_COLOR  ) & 0xFFFFFF);
		return ;
	}
	z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 10) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 11) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
	if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 12)) * BASE_COLOR  ) & 0xFFFFFF;
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i  + 13) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 14) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + 15) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}

		i += 16;
	}
	buffer[(pos_y * (width)) + pos_x] = 0;
}
