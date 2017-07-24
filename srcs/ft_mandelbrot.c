/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 07:39:39 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/24 13:20:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* static int32_t	ft_is_bounded(t_complexe c, uint32_t iteration_number) */
/* { */
/* 	t_complexe		z; */
/* 	uint32_t		i; */

/* 	i = 0; */
/* 	z = (t_complexe){0, 0}; */
/* 	while (i < iteration_number) */
/* 	{ */
/* /\* 		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part *\/ */
/* /\* 			* z.imaginary_part), 2 * z.real_part * z.imaginary_part}; *\/ */
/* /\* 		z = (t_complexe){z.real_part + c.real_part *\/ */
/* /\* 						 , z.imaginary_part + c.imaginary_part}; *\/ */
/*  		z = ft_square_complexe(&z); */
/* 		z = ft_add_complexe(&z, &c); */

/* /\* 		if (ft_get_complexe_magnitude(&z) > 2) *\/ */
/* /\* 			return (((int)i * BASE_COLOR) & 0xFFFFFF); *\/ */
/* 		if (ft_get_complexe_magnitude(&z) > 2) */
/* 			return (0xFFFFFF); */

/* 		i++; */
/* 	} */
/* 	return (0); */
/* } */

static void	ft_get_perturbation_point_data(t_complexe_perturbation *perturbation
											 , t_complexe c, uint32_t iteration_number)
{
	t_complexe		z;
	uint32_t		i;

	i = 0;
	z = (t_complexe){0, 0};
//printf("___start___\n");
	while (i < iteration_number)
	{
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
						 , z.imaginary_part + c.imaginary_part};
		perturbation->x[i] = z;
// 		printf("i: %u, perturbation->x[i].real_part: %.32lf, perturbation->x[i].imaginary_part: %.32lf\n", i, perturbation->x[i].real_part, perturbation->x[i].imaginary_part);
//		printf("magnitude: %lf\n", sqrt(((perturbation->x[i].real_part * perturbation->x[i].real_part) + (perturbation->x[i].imaginary_part * perturbation->x[i].imaginary_part))));
/* 		if (ft_get_complexe_magnitude(&z) > 2) */
/* 			return (0xFFFFFF); */
		i++;
	}
//	printf("___end___\n");
}

static void	ft_get_perturbation_a_coefficient(t_complexe_perturbation *perturbation)
{
	uint32_t	i;
	t_complexe	*a;
//	t_complexe	tmp;

/* 	tmp = ft_multiply_complexe(&perturbation->x[0], &perturbation->x[1]); */
/* 	perturbation->a[2] = (ft_multiply_complexe(&(t_complexe){4, 0}, &tmp)); */
/* 	tmp = ft_multiply_complexe(&(t_complexe){-2, 0}, &perturbation->x[1]); */
/* 	tmp = ft_add_complexe(&tmp, &(t_complexe){-1, 0}); */
/* 	perturbation->a[2] = ft_add_complexe(&perturbation->a[2], &tmp); */
	perturbation->a[0] = (t_complexe){1, 0};
	a = perturbation->a;
	i = 1;
	while (i < perturbation->iteration_number)
	{
/*  		perturbation->a[i] = ft_multiply_complexe(&perturbation->x[i - 1], &perturbation->a[i - 1]); */
/* 		perturbation->a[i] = (t_complexe){perturbation->a[i].real_part * 2 + 1 */
/* 										  , perturbation->a[i].imaginary_part * 2}; */
		a[i].real_part = 2.0 * (perturbation->x[i - 1].real_part * a[i - 1].real_part
						- perturbation->x[i - 1].imaginary_part * a[i - 1].imaginary_part) + 1.0;
		a[i].imaginary_part = 2.0 * (perturbation->x[i - 1].real_part * a[i - 1].imaginary_part
						 + perturbation->x[i - 1].imaginary_part * a[i - 1].real_part);
		i++;
	}
}

static void	ft_get_perturbation_b_coefficient(t_complexe_perturbation *perturbation)
{
	uint32_t	i;
	t_complexe	*b;

/* 	perturbation->b[2] = ft_add_complexe(&(t_complexe){(perturbation->x[0].real_part - 1) */
/* 	* (perturbation->x[0].real_part - 1) - (perturbation->x[0].imaginary_part */
/* 	* perturbation->x[0].imaginary_part), 2 * (perturbation->x[0].real_part - 1) */
/* 	* perturbation->x[0].imaginary_part}, &(t_complexe){perturbation->x[1].real_part * 2 */
/* 	, perturbation->x[1].imaginary_part * 2}); */
	perturbation->b[0] = (t_complexe){0, 0};
	b = perturbation->b;
	i = 1;
	while (i < perturbation->iteration_number)
	{
/* 		perturbation->b[i] = ft_multiply_complexe(&perturbation->x[i - 1], &perturbation->b[i - 1]); */
/* 		perturbation->b[i] = (t_complexe){perturbation->b[i].real_part * 2 */
/* 										  , perturbation->b[i].imaginary_part * 2}; */
/* 		perturbation->b[i] = ft_add_complexe(&perturbation->b[i], &(t_complexe){perturbation->a[i - 1].real_part * perturbation->a[i - 1].real_part - (perturbation->a[i - 1].imaginary_part */
/* 		* perturbation->a[i - 1].imaginary_part), 2 * perturbation->a[i - 1].real_part * perturbation->a[i - 1].imaginary_part}); */
		b[i].real_part = 2.0 * (perturbation->x[i - 1].real_part * b[i - 1].real_part
			- perturbation->x[i - 1].imaginary_part * b[i - 1].imaginary_part)
			+ perturbation->a[i - 1].real_part * perturbation->a[i - 1].real_part
			- perturbation->a[i - 1].imaginary_part * perturbation->a[i - 1].imaginary_part;
		b[i].imaginary_part = 2.0 * (perturbation->x[i - 1].real_part * b[i - 1].imaginary_part
						+ perturbation->x[i - 1].imaginary_part * b[i - 1].real_part
						+ perturbation->a[i - 1].real_part * perturbation->a[i - 1].imaginary_part);
		i++;
	}
}

static void	ft_get_perturbation_coefficient(t_complexe_perturbation *perturbation)
{
	uint32_t	i;
//	t_complexe	tmp;
	t_complexe	*c;

	ft_get_perturbation_a_coefficient(perturbation);
	ft_get_perturbation_b_coefficient(perturbation);
/* 	perturbation->c[2] = (t_complexe){perturbation->x[0].real_part * 4 - 2, perturbation->x[0].imaginary_part * 4}; */
	perturbation->c[0] = (t_complexe){0, 0};
	c = perturbation->c;
	i = 1;
	while (i < perturbation->iteration_number)
	{
/* 		perturbation->c[i] = ft_multiply_complexe(&perturbation->x[i - 1], &perturbation->c[i - 1]); */
/* 		perturbation->c[i] = (t_complexe){perturbation->c[i].real_part * 2 */
/* 										  , perturbation->c[i].imaginary_part * 2}; */
/* 		tmp = ft_multiply_complexe(&perturbation->a[i - 1], &perturbation->b[i - 1]); */
/* 		tmp = (t_complexe){tmp.real_part * 2, tmp.imaginary_part * 2}; */
/* 		perturbation->c[i] = ft_add_complexe(&perturbation->c[i], &tmp); */
		c[i].real_part = 2.0 * (perturbation->x[i - 1].real_part * c[i - 1].real_part
			- perturbation->x[i - 1].imaginary_part * c[i - 1].imaginary_part
			+ perturbation->a[i - 1].real_part * perturbation->b[i - 1].real_part
			- perturbation->a[i - 1].imaginary_part * perturbation->b[i - 1].imaginary_part);
		c[i].imaginary_part = 2.0 * (perturbation->x[i - 1].real_part * c[i - 1].imaginary_part
						+ perturbation->x[i - 1].imaginary_part * c[i - 1].real_part
						+ perturbation->a[i - 1].real_part * perturbation->b[i - 1].imaginary_part
						+ perturbation->a[i - 1].imaginary_part * perturbation->b[i - 1].real_part);
		i++;
	}

}

static void	ft_get_perturbation_data(t_complexe_perturbation *perturbation
											 , t_complexe c, uint32_t iteration_number)
{
	t_complexe		*ptr;

	if (perturbation->x == NULL)
	{
		if (!(ptr = (t_complexe*)malloc(sizeof(t_complexe) * iteration_number * 4)))
			ft_error_exit(1, (char*[]){MALLOC_FAILURE}, 1);
	}
	else
		ptr = perturbation->x;
	perturbation->x = ptr;
	perturbation->a = ptr + iteration_number;
	perturbation->b = ptr + iteration_number * 2;
	perturbation->c = ptr + iteration_number * 3;
	perturbation->iteration_number = iteration_number;
	ft_get_perturbation_point_data(perturbation, c, iteration_number);
	ft_get_perturbation_coefficient(perturbation);
}

static uint32_t	test = 1;
static int32_t	ft_apply_perturbation(t_complexe_perturbation *perturbation, t_complexe y)
{
	t_complexe	deltas[4];
	t_complexe	tmp[3];
	uint32_t	i;

//	ft_get_perturbation_data(perturbation, y, perturbation->iteration_number);
	deltas[0] = (t_complexe){y.real_part - perturbation->x[0].real_part
						, y.imaginary_part - perturbation->x[0].imaginary_part};
	deltas[1] = ft_square_complexe(deltas);
	deltas[2] = ft_multiply_complexe(deltas, &deltas[1]);
	deltas[3] = ft_pow_complexe(deltas, 4);
/* 	if (((deltas[1].real_part * deltas[1].real_part) + (deltas[1].imaginary_part * deltas[1].imaginary_part)) < (deltas[2].real_part * deltas[2].real_part) + (deltas[2].imaginary_part * deltas[2].imaginary_part)) */
/* 	{ */
/* 		printf("deltas_2: %lf, deltas_3: %lf\n", (deltas[1].real_part * deltas[1].real_part) + (deltas[1].imaginary_part * deltas[1].imaginary_part), (deltas[2].real_part * deltas[2].real_part) + (deltas[2].imaginary_part * deltas[2].imaginary_part)); */
/* 		printf("test = %u\n", ++test); */
/* 		ft_get_perturbation_data(perturbation, y, perturbation->iteration_number); */
/* 		return (ft_apply_perturbation(perturbation, y)); */
/* 	} */
//	printf("deltas[0].real_part: %.64lf, deltas[0].imaginary_part: %.64lf\n", deltas[0].real_part, deltas[0].imaginary_part);

	i = 0;
	while (i < perturbation->iteration_number)
	{
//		printf("======================\n");
		tmp[0] = ft_multiply_complexe(&deltas[0], &perturbation->a[i]);
			printf("->a[i].real_part: %lf, ->a[i].imaginary_part: %lf \n", perturbation->a[i].real_part, perturbation->a[i].imaginary_part);
		printf("a: tmp[0].real_part: %.32lf, tmp[0].imaginary_part: %.32lf\n", tmp[0].real_part, tmp[0].imaginary_part);
		tmp[1] = ft_multiply_complexe(&deltas[1], &perturbation->b[i]);
		printf("->b[i].real_part: %lf, ->b[i].imaginary_part: %lf \n", perturbation->b[i].real_part, perturbation->b[i].imaginary_part);
		printf("b: tmp[1].real_part: %.32lf, tmp[1].imaginary_part: %.32lf\n", tmp[1].real_part, tmp[1].imaginary_part);
		tmp[2] = ft_multiply_complexe(&deltas[2], &perturbation->c[i]);
		if (((tmp[1].real_part * tmp[1].real_part) + (tmp[1].imaginary_part * tmp[1].imaginary_part)) < ((tmp[2].real_part * tmp[2].real_part) + (tmp[2].imaginary_part * tmp[2].imaginary_part)))
		{
			printf("deltas_2: %lf, deltas_3: %lf\n", (deltas[1].real_part * deltas[1].real_part) + (deltas[1].imaginary_part * deltas[1].imaginary_part), (deltas[2].real_part * deltas[2].real_part) + (deltas[2].imaginary_part * deltas[2].imaginary_part));
			printf("test = %u\n", ++test);

			ft_get_perturbation_data(perturbation, y, perturbation->iteration_number);
			return (ft_apply_perturbation(perturbation, y));
		}
		printf("->c[i].real_part: %lf, ->c[i].imaginary_part: %lf \n", perturbation->c[i].real_part, perturbation->c[i].imaginary_part);
		printf("c: tmp[2].real_part: %.32lf, tmp[2].imaginary_part: %.32lf\n", tmp[2].real_part, tmp[2].imaginary_part);
		tmp[0] = ft_add_complexe(&tmp[0], &tmp[1]);
		tmp[0] = ft_add_complexe(&tmp[0], &tmp[2]);
		tmp[0] = ft_add_complexe(&tmp[0], &deltas[3]);
		printf("_____At iteration: %u\n", i);
		printf("tmp[0].real_part: %.32lf, tmp[0].imaginary_part: %.32lf\n", tmp[0].real_part, tmp[0].imaginary_part);
		printf("deltas[0].real_part: %.32lf, deltas[0].imaginary_part: %.32lf\n", deltas[0].real_part, deltas[0].imaginary_part);

		tmp[0] = (t_complexe){tmp[0].real_part + perturbation->x[i].real_part,
							  tmp[0].imaginary_part + perturbation->x[i].imaginary_part};
		if (((tmp[0].real_part * tmp[0].real_part) + (tmp[0].imaginary_part * tmp[0].imaginary_part)) > 4)
		{
/* 			printf("test.real_part: %lf, test.imaginary_part: %lf \n ",test.real_part, test.imaginary_part); */
/* 			printf("test2.real_part: %lf, test2.imaginary_part: %lf \n ",test2.real_part, test2.imaginary_part); */

			return ((BASE_COLOR * i) &0xFFFFFF);
		}
		i++;
	}
/* 	printf("test.real_part: %lf, test.imaginary_part: %lf \n ",test.real_part, test.imaginary_part); */
/* 	printf("test2.real_part: %lf, test2.imaginary_part: %lf \n ",test2.real_part, test2.imaginary_part); */

/* 	printf("x.real_part: %lf, x.imaginary_part: %lf\n", perturbation->x[perturbation->iteration_number - 1].real_part, perturbation->x[perturbation->iteration_number - 1].imaginary_part); */
/* 	printf("tmp[0].real_part: %lf, tmp[0].imaginary_part: %lf\n", tmp[0].real_part, tmp[0].imaginary_part); */
	return (0);
}


void			ft_mandelbrot(t_pthread_execution_data *pthread_data)
{
	t_complexe_perturbation perturbation_data;
	int						*image;
	t_complexe				c;
	uint32_t				i;
	uint32_t				u;
	uint32_t				iteration_number;

	ft_bzero(&perturbation_data, sizeof(t_complexe_perturbation));
	i = pthread_data->win_cadran.min.y;
	image = pthread_data->mlx_data.frame->buffer;
	c = pthread_data->complexe_cadran.min;
	iteration_number = ft_get_t_fractal_data()[MANDELBROT].iteration_number;
	ft_get_perturbation_data(&perturbation_data, (t_complexe){ft_double_distance(pthread_data->complexe_cadran.min.real_part, pthread_data->complexe_cadran.max.real_part) / 2 + pthread_data->complexe_cadran.min.real_part
				, ft_double_distance(pthread_data->complexe_cadran.min.imaginary_part, pthread_data->complexe_cadran.max.imaginary_part) / 2 + pthread_data->complexe_cadran.min.imaginary_part}, iteration_number);
	while (i < pthread_data->win_cadran.max.y)
	{
		u = pthread_data->win_cadran.min.x;
		while (u < pthread_data->win_cadran.max.x)
		{
			image[(int)((int)i * (WINDOW_WIDTH)) + (int)u] = ft_apply_perturbation(&perturbation_data, c);
			c.real_part += pthread_data->c_augmentation_rate.real_part;
			u++;
		}
		c.real_part = pthread_data->complexe_cadran.min.real_part;
		c.imaginary_part += pthread_data->c_augmentation_rate.imaginary_part;
		i++;
	}
	free(perturbation_data.x);
/* 	i = pthread_data->win_cadran.min.y; */
/* 	image = pthread_data->mlx_data.frame->buffer; */
/* 	c = pthread_data->complexe_cadran.min; */
/* 	iteration_number = ft_get_t_fractal_data()[MANDELBROT].iteration_number; */
/* 	while (i < pthread_data->win_cadran.max.y) */
/* 	{ */
/* 		u = pthread_data->win_cadran.min.x; */
/* 		while (u < pthread_data->win_cadran.max.x) */
/* 		{ */
/* 			image[(int)((int)i * (WINDOW_WIDTH)) + (int)u] = ft_is_bounded(c, iteration_number); */
/* 			c.real_part += pthread_data->c_augmentation_rate.real_part; */
/* 			u++; */
/* 		} */
/* 		c.real_part = pthread_data->complexe_cadran.min.real_part; */
/* 		c.imaginary_part += pthread_data->c_augmentation_rate.imaginary_part; */
/* 		i++; */
/* 	} */
}
