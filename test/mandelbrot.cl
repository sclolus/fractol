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

static int	ft_is_bounded(t_complexe c, unsigned int iteration_number)
{
	t_complexe			z;
	unsigned int		i;

	i = 0;
	z = (t_complexe){0, 0};
	while (i < iteration_number)
	{
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if (sqrt((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part)) > 2)
			return (((int)i * BASE_COLOR) & 0xFFFFFF);
		i++;
	}
	return (0);
}

double	ft_double_distance(double a, double b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}


__kernel void mandelbrot(__global int *buffer, int width, int height, t_complexe_cadran cadran, unsigned int iteration_number, t_complexe distance)
{
	t_complexe				c;
	int						global_id = get_global_id(0);
	int						pos_x = global_id % width;
	int						pos_y = global_id / width;
	t_complexe			z;
	unsigned int		i;

	c = (t_complexe){cadran.min.real_part +  (distance.real_part / width) * pos_x
					 , cadran.min.imaginary_part + (distance.imaginary_part/ height) * pos_y};
	i = 0;
	z = (t_complexe){0, 0};
	while (i < (iteration_number & 4))
	{
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i + (int)c.imaginary_part) * BASE_COLOR  ) & 0xFFFFFF);
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
			buffer[(pos_y * (width)) + pos_x] = (((i + (int)c.imaginary_part)) * BASE_COLOR  ) & 0xFFFFFF;
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i - (int)c.imaginary_part + 1) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i * (int)c.imaginary_part + 2) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2.0 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		if ((z.real_part * z.real_part) + (z.imaginary_part * z.imaginary_part) > 4)
		{
			buffer[(pos_y * (width)) + pos_x] = (((i / (int)c.imaginary_part + 3) * BASE_COLOR  ) & 0xFFFFFF);
			return ;
		}
		i += 4;
	}
	buffer[(pos_y * (width)) + pos_x] = 0;
}
