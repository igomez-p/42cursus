/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:52:45 by igomez-p          #+#    #+#             */
/*   Updated: 2021/01/24 13:31:00 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"
#include <stdio.h>

void	ini_cub(t_cub *info)
{
	int i;

	info->res.rend_x = 0;
	info->res.rend_y = 0;

	info->tex.path_norte = NULL;
	info->tex.path_sur = NULL;
	info->tex.path_oeste = NULL;
	info->tex.path_este = NULL;
	info->tex.path_sprite = NULL;

	i = 0;
	while (i < 3)
	{
		info->col.rgb_suelo[i] = 0;
		info->col.rgb_techo[i] = 0;
		i++;
	}

	info->map = NULL;
	info->minilibx.new_mlx = mlx_init();
}
// Función para leer archivo .cub
void	read_cub(char *filename, t_cub *info)
{
	int	fd;
	char	*linea;
	char	*stc_line;

	stc_line = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		perror("Error\nFallo al abrir el archivo\n");
	else
	{
		linea = 0;
		while (get_next_line(fd, &linea) > 0)
		{
			//Puede haber espacios antes de un identificador?? en ese caso, mover puntero hasta el 1er char alpha
			if (ft_strchr(linea, 'R'))
				info_res(linea, info);
			else if (!ft_strncmp(linea, "NO", 2) || !ft_strncmp(linea, "SO", 2) ||
					!ft_strncmp(linea, "WE", 2) || !ft_strncmp(linea, "EA", 2) ||
					!ft_strncmp(linea, "S", 1))
				info_tex(linea, info);
			else if (ft_strchr(linea, 'F') || ft_strchr(linea, 'C'))
				info_color(linea, info);
			else if (ft_strchr(linea, '1'))
			{
				stc_line = info_map(linea, stc_line);
				stc_line = ft_swap(stc_line, "\n");
			}
			free(linea);
			linea = 0;
		}
		if (!get_next_line(fd, &linea) && ft_strchr(linea, '1'))
			stc_line = info_map(linea, stc_line);
		info->map = ft_split(stc_line, '\n');
	}
}

void eliminarEspacios(t_cub *cub)
{
    char **map_aux = NULL;
    int filas = 0, colum = 0, y = 0, x = 0;
    while (cub->map[filas])
    {
        while (cub->map[filas][colum])
        {
            if (cub->map[filas][colum] != NADA)
            {
                map_aux[y][x] = cub->map[filas][colum];
                x++;
            }
            colum++;
        }
        y++;
        filas++;
    }
	cub->nrows = filas;
    cub->map = map_aux;
   // mapaColum = x;
   // mapaFilas = y;
}

int		main(int argc, char *argv[])
{
	// argumento 1: archivo rt con info sobre el elemento
	// argumento 2: --save

	if (argc < 2)
	{
		perror("Error\nNumero de argumentos invalido\n");
		return (-1);
	}

	t_cub cub;
	cub.res.rend_x = 1024;
	cub.res.rend_y = 900;
/*	ini_cub(&cub);
	read_cub(argv[1], &cub);
	eliminarEspacios(&cub);*/

	cub.minilibx.new_mlx = mlx_init();
	if (!cub.minilibx.new_mlx)
		return 0;

	if (!(cub.minilibx.new_window = mlx_new_window(cub.minilibx.new_mlx, cub.res.rend_x, cub.res.rend_y, "Cub 3D")))
		return 0;

	if (!(cub.minilibx.new_img = mlx_new_image(cub.minilibx.new_mlx, 850, 650)))
	{
		mlx_destroy_window(cub.minilibx.new_mlx, cub.minilibx.new_window);
		return 0;
	}

/*	for (int i = 240; i < 850; i++)
	{
		for (int k = 124; k < 650; k++)
		{
			mlx_pixel_put(cub.minilibx.new_mlx, cub.minilibx.new_window, i, k, 126);
		}
	}
	mlx_string_put(cub.minilibx.new_mlx, cub.minilibx.new_window, 452, 235, (int)0xFFFFFFFF, "HOLA");
	mlx_string_put(cub.minilibx.new_mlx, cub.minilibx.new_window, 450, 255, (int)0xFFFFFFFF, "CARACOLA");
*/
	memset(cub.minilibx.new_img->buffer, 123, 4*850*650);

	mlx_put_image_to_window(cub.minilibx.new_mlx, cub.minilibx.new_window, cub.minilibx.new_img, 850, 650);
//	mlx_loop_hook(cub.minilibx.new_mlx, 0, 0);
	mlx_loop(cub.minilibx.new_mlx);

	/*if (!ft_strncmp(argv[2], "--save", ft_strlen(argv[2])))
		// guardar archivo en formato bmp
	else
	{
		// se muestra la imagen en ventana (con ciertas reglas)
	}*/

	// ESTRUCTURA GUARDADA
	/*printf("\nR: %d %d", cub.res.rend_x, cub.res.rend_x);
	printf("\nNO: %s", cub.tex.path_norte);
	printf("\nSO: %s", cub.tex.path_sur);
	printf("\nWE: %s", cub.tex.path_oeste);
	printf("\nEA: %s", cub.tex.path_este);
	printf("\nS: %s", cub.tex.path_sprite);
	printf("\nF: %d,%d,%d", cub.col.rgb_suelo[0], cub.col.rgb_suelo[1], cub.col.rgb_suelo[2]);
	printf("\nC: %d,%d,%d", cub.col.rgb_techo[0], cub.col.rgb_techo[1], cub.col.rgb_techo[2]);

	int i = 0;
	printf("\n");
	while (cub.map[i] != NULL)
	{
		printf("MAPmain: %s\n", cub.map[i]);
		i++;
	}*/
	return (0);
}
