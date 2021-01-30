/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:52:45 by igomez-p          #+#    #+#             */
/*   Updated: 2021/01/30 17:44:41 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub.h"

void	init_cub(t_cub *info)
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

	info->minilibx.mlx = NULL;
	info->minilibx.window = NULL;
	info->minilibx.img = NULL;
	info->minilibx.img_addr = NULL;
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

	t_cub	cub;
	cub.res.rend_x = 2048;	// ancho
	cub.res.rend_y = 875;	// alto

	//cub.first = 0;
//	init_cub(&cub);
/*	check_file(argc, argv, &cub);
	grab_file(&cub, argc, argv);*/

	if (!(cub.minilibx.mlx = mlx_init()))
		check_error(cub, "Error al inicializar MLX\n");

/*	read_from_file(&cub);
	load_textures(&cub);
	load_hud(&cub);
	read_map(&cub);
	close(cub.fd);
	set_mini_map(&cub, &cub.m_map);*/

	if(!(cub.minilibx.window = mlx_new_window(cub.minilibx.mlx, cub.res.rend_x, cub.res.rend_y, "Cub3D")))
		check_error(cub, "Error new window\n");
	if (!(cub.minilibx.img = mlx_new_image(cub.minilibx.mlx, cub.res.rend_x, cub.res.rend_y)))
		check_error(cub, "Error new image\n");


	cub.minilibx.img_addr = mlx_get_data_addr(cub.minilibx.img, &cub.win.bpp, &cub.win.sz_line, &cub.win.endian);
	//printf("bpp %d | sz_line %d | endian %d\nr", cub.win.bpp, cub.win.sz_line, cub.win.endian);

//ft_memcpy(cub.minilibx.img_addr, (void *)999, sizeof(int));
	if (argc == 3 && (!ft_strncmp(argv[2], "--save", 7)))
		return 1;	//save_bmp(&cub);

	mlx_hook(cub.minilibx.window, 17, 0, exit_program, 0);
/*	mlx_hook(cub.minilibx.window, 2, 0, key_press, &cub);
	mlx_hook(cub.minilibx.window, 3, 0, key_release, &cub);*/
//	paint(1, cub);
	mlx_loop_hook(cub.minilibx.mlx, paint, &cub);
	mlx_loop(cub.minilibx.mlx);
	return (0);
}
