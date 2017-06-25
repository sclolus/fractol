/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:55:51 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/25 18:17:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include "key_codes_macos.h"
# include "events.h"
# include "mlx.h"
# include "libft.h"

typedef void* MLX_WIN;
typedef void* MLX_IMG;
typedef void* MLX_PTR;

# define WINDOW_NAME "fdf"

typedef struct	s_mem_block
{
	uint64_t			capacity;
	uint64_t			offset;
	void				*block;
	struct s_mem_block	*next;
}				t_mem_block;

typedef struct	s_matrice
{
	uint64_t	x;
	uint64_t	y;
	uint64_t	z;
}				t_matrice;

typedef struct	s_point
{
	t_matrice	coords;
}				t_point;

/*
** Mem_block handling
*/

#define MEM_BLOCK_LIMIT 256
#define DEFAULT_MEM_BLOCK_SIZE 1U << 32

void		*ft_mem_block_push_back_elem(t_mem_block *mem_block
									, void *elem, uint32_t size);
t_mem_block	*ft_create_mem_block(uint64_t capacity);


/*
** Error handling
*/

# define INVALID_MEM_CAPACITY "Invalid capacity provided to ft_create_mem_block()"
# define MALLOC_FAILURE "malloc() failed due to insufficient ressources left"
# define MLX_INIT_ERROR "mlx_init() failed"
# define MLX_NEW_WIN_ERROR "mlx_new_window() failed"
# define MLX_NEW_IMG_ERROR "mlx_new_image() failed"
#endif
