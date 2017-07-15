# define BASE_COLOR 0x110000

typedef struct	s_complexe
{
	float	real_part;
	float	imaginary_part;
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
		if (sqrt(pow(z.real_part, 2) + pow(z.imaginary_part, 2)) > 2)
			return (((int)i * BASE_COLOR) & 0xFFFFFF);
		i++;
	}
	return (0);
}

float	ft_float_distance(float a, float b)
{
	if (b > a)
		return (b - a);
	else
		return (a - b);
}


__kernel void mandelbrot(__global int *buffer, int width, int height, t_complexe_cadran cadran, unsigned int iteration_number)
{
	t_complexe				c;
	int						global_id = get_global_id(0);
	int						pos_x = global_id % width;
	int						pos_y = global_id / width;
	int						color;

	c = cadran.min;
	c.imaginary_part += (ft_float_distance(cadran.min.imaginary_part, cadran.max.imaginary_part) / (float)height) * pos_y;
	c.real_part += (ft_float_distance(cadran.min.real_part, cadran.max.real_part) / (float)width) * pos_x;
	if (!(color = ft_is_bounded(c, iteration_number)))
	{
		buffer[(int)((int)pos_y * (width)) + (int)pos_x] = 0;
	}
	else
	{
		buffer[(int)((int)pos_y * (width)) + (int)pos_x] = color;
	}
}
