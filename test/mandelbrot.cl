# define BASE_COLOR 0x110000

typedef struct	s_complexe
{
	float	real_part;
	float	imaginary_part;
}				t_complexe;

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

__kernel void mandelbrot(__global int *buffer, int width, int height)
{
	int					global_id = get_global_id(0);
	t_complexe			c;
	unsigned int		i;
	unsigned int		u;
	unsigned int		iteration_number;
	int					color;

	i = 0;
	c = (t_complexe){-2, -1};
	iteration_number = 32;
	while (i < width)
	{
		u = 0;
		while (u < height)
		{
			if (!(color = ft_is_bounded(c, iteration_number)))
				buffer[(int)((int)i * (width)) + (int)u] = 0;
			else
				buffer[(int)((int)i * (height)) + (int)u] = color;
			c.real_part += 3 / (float)width;
			u++;
		}
		c.real_part = -(float)2;
		c.imaginary_part += 2 / (float)height;
		i++;
	}

}
