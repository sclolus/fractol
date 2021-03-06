/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_screenshot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 09:00:46 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/30 07:15:38 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <sys/stat.h>

static char	*ft_get_random_filename(void)
{
	static char		filename[256] = SCREENSHOT_FILENAME_HEADER;
	int				fd;
	int64_t			ret;

	if ((fd = open(RANDOM_FILE, O_RDONLY)) == -1)
	{
		ft_error(1, (char*[]){ERR_OPEN_SCREENSHOT}, 0);
		return (NULL);
	}
	ret = read(fd, filename + sizeof(SCREENSHOT_FILENAME_HEADER) - 1, 5);
	ft_strcat(filename, ".bmp");
	if (close(fd) == -1)
	{
		ft_error(1, (char*[]){ERR_CLOSE_SCREENSHOT}, 0);
		return (NULL);
	}
	ft_normalize_random_filename(filename);
	return (filename);
}

static void	ft_put_bmp_header_into_file(int fd, uint32_t size)
{
	const static unsigned short		header_field = 0x4D42;
	static char						buffer[18];

	size += 54;
	ft_memcpy(buffer, &header_field, 2);
	ft_memcpy(buffer + 2, &size, 4);
	ft_memcpy(buffer + 6, "\0\0\0\0", 4);
	ft_memcpy(buffer + 10, &(uint32_t){54}, 4);
	ft_memcpy(buffer + 14, &(uint32_t){40}, 4);
	write(fd, buffer, 18);
}

static void	ft_put_image_header_into_file(int fd, uint32_t width
										, uint32_t height)
{
	static char	buffer[36];

	ft_memcpy(buffer, &width, 4);
	ft_memcpy(buffer + 4, &height, 4);
	ft_memcpy(buffer + 8, &(uint16_t){1}, 2);
	ft_memcpy(buffer + 10, &(uint16_t){24}, 2);
	ft_memcpy(buffer + 12, &(uint32_t){0}, 4);
	ft_memcpy(buffer + 16, &(uint32_t){(width | 4) * height}, 4);
	ft_memcpy(buffer + 20, &(uint32_t){300}, 4);
	ft_memcpy(buffer + 24, &(uint32_t){300}, 4);
	ft_memcpy(buffer + 28, &(uint32_t){0}, 4);
	ft_memcpy(buffer + 32, &(uint32_t){0}, 4);
	write(fd, buffer, 36);
}

static void	ft_put_buffer_into_file(int fd, int *buffer
									, uint32_t width, uint32_t height)
{
	static char	bmp_buffer[4 * ((WINDOW_WIDTH + 3) & ~3) * WINDOW_HEIGHT];
	uint32_t	offset;
	uint32_t	i;
	uint32_t	u;

	i = width * height;
	offset = 0;
	while (i > 0)
	{
		u = ~0U;
		while (++u < width)
		{
			ft_memcpy(bmp_buffer + (offset), buffer + ((i--
						- 1) / width * width) + u, 3);
			offset += 3;
		}
		while (u & (4 - 1))
		{
			ft_memcpy(bmp_buffer + offset, &(char){'\0'}, 1);
			offset++;
			u++;
		}
	}
	write(fd, bmp_buffer, 4 * ((WINDOW_WIDTH + 3) & (~3)) * WINDOW_HEIGHT);
}

void		ft_create_screenshot(void *buffer, uint32_t width, uint32_t height)
{
	char	*filename;
	int		fd;

	mkdir("./screenshots", S_IRWXU);
	if (!(filename = ft_get_random_filename()))
		return ;
	if ((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)) == -1)
	{
		ft_error(1, (char*[]){ERR_OPEN_SCREENSHOT}, 0);
		return ;
	}
	ft_put_bmp_header_into_file(fd, width * height);
	ft_put_image_header_into_file(fd, width, height);
	ft_put_buffer_into_file(fd, (int *)buffer, width, height);
	if (close(fd) == -1)
	{
		ft_error(1, (char*[]){ERR_CLOSE_SCREENSHOT}, 0);
		return ;
	}
	ft_bzero(filename + sizeof(SCREENSHOT_FILENAME_HEADER), 256
			- sizeof(SCREENSHOT_FILENAME_HEADER));
}
