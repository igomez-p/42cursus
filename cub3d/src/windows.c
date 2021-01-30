/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:31:02 by igomez-p          #+#    #+#             */
/*   Updated: 2021/01/30 18:05:52 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	paint(int keycode, t_cub c)
{
	int x = 0, y = 0;
	int sizeline = 650;
	c.win.data = malloc(sizeof(c.minilibx.img_addr));
	ft_memset(c.win.data, 10, sizeof(c.minilibx.img_addr));
	while (x < c.res.rend_x)
	{
		y = 0;
		while (y < (int)(c.res.rend_y / 2))
		{
			ft_memcpy(c.minilibx.img_addr + 4 * c.res.rend_x * y + x * 4,
					c.win.data[y % 512 * sizeline +
					x % 512 * c.win.bpp / 8], sizeof(int));
			y++;
		}
		x++;
	}
	free(c.win.data);
	return (1);
}

int			exit_program(t_cub cub)
{
	int			i;

	write(1, "Closing program...\n", 19);
	i = -1;
/*	if (cub)
		free(cub);
	if (cub.map)
	{
		while (++i < cub.nrows)
			free(cub.map[i]);
		free(cub.map);
	}*/
//	if (t->fd > 0)
//		close(t->fd);
	if (cub.minilibx.img)
		mlx_destroy_image(cub.minilibx.mlx, cub.minilibx.img);
	if (cub.minilibx.window)
		mlx_destroy_window(cub.minilibx.mlx, cub.minilibx.window);

	exit(0);
	return (0);
}
