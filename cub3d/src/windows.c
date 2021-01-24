/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:31:02 by igomez-p          #+#    #+#             */
/*   Updated: 2021/01/24 19:08:05 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	paint(int keycode, t_cub c)
{
	int x = 0, y = 0;
	int heigh = 875, width = 2048;

	while (y < heigh)
	{
		x = 0;
		while (x < width)
		{
			mlx_pixel_put(c.minilibx.mlx, c.minilibx.window, x, y, 65355);
			//ft_memcpy(cub.minilib.img_ptr + 4 * t->res[X] * start + 4 * x, &t->tex[t->id].data[4 * t->tex[t->id].x * t->x_floortext + 4 * t->y_floortext], sizeof(int));
			x++;
		}
		y++;
	}
	return (0);
}

int			exit_program(t_cub cub)
{
	int			i;

	write(1, "Closing program...\n", 19);
	i = -1;
/*	if (cub.map)
	{
		while (++i < cub.nrows)
			free(cub.map[i]);
		free(cub.map);
	}*/
//	if (t->fd > 0)
//		close(t->fd);
	mlx_destroy_image(cub.minilibx.mlx, cub.minilibx.img);
	mlx_destroy_window(cub.minilibx.mlx, cub.minilibx.window);
	exit(0);
	return (0);
}
