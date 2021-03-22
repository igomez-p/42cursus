/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:31:02 by igomez-p          #+#    #+#             */
/*   Updated: 2021/01/31 18:20:06 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	paint(t_cub *c)
{
	int		x;
	int		y;

	y = 0;
	while (y < c->res.rend_y)
	{
		x = 0;
		while (x < c->res.rend_x)
		{
			c->win.data[y * c->res.rend_x + x] = 0x026600;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(c->libx.mlx, c->libx.window, c->libx.img, 0, 0);

	return (1);
}

int key_handler(int key, t_cub *c)
{
	printf("key %d\n\r", key);
	if (key == (int)'W' || key == (int)'w')
	{
		c->player.up = 1;
		printf("KEY W\n\r");
	}
	else if (key == (int)'A' || key == (int)'a')
	{
		c->player.right = 1;
		printf("KEY A\n\r");
	}
	else if (key == (int)'S' || key == (int)'s')
	{
		c->player.down = 1;
		printf("KEY S\n\r");
	}
	else if (key == (int)'D' || key == (int)'d')
	{
		c->player.left = 1;
		printf("KEY D\n\r");
	}

	return 1;
}

int			exit_program(t_cub *c)
{
	//int			i;

	write(1, "Closing program...\n", 19);
	//i = 0;

//	TODO: LIBERAR MAPA

//	if (t->fd > 0)
//		close(t->fd);
	if (c->libx.img)
		mlx_destroy_image(c->libx.mlx, c->libx.img);
	if (c->libx.window)
		mlx_destroy_window(c->libx.mlx, c->libx.window);

	exit(0);
	return (0);
}
