/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:58:54 by igomez-p          #+#    #+#             */
/*   Updated: 2021/01/30 17:37:08 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
#include "../inc/libftprintf.h"

void	check_error(t_cub cub, char *str)
{
		int		i;
		int		len = ft_strlen(str);

	write(1, "Error\n", 6);
	if (!str)
		perror("");
	else
		write(1, str, len);

	i = -1;
	/*if (cub.map)
	{
		while (++i < cub.nrows)
			free(cub.map[i]);
		free(cub.map);
	}*/
//	if (t->fd > 0)
//		close(t->fd);
	if (cub.minilibx.window)
		mlx_destroy_window(cub.minilibx.mlx, cub.minilibx.window);
	if (cub.minilibx.mlx)
		mlx_destroy_image(cub.minilibx.mlx, cub.minilibx.img);
	exit(1);
}
