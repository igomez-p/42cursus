/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:51:44 by igomez-p          #+#    #+#             */
/*   Updated: 2021/01/23 19:42:16 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define NADA ' '
# define VACIO '0'
# define MURO '1'
# define OBJETO '2'
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "/usr/local/include/mlx.h"
# include "mlx_int.h"
// open, read, write, malloc, free, perror, strerror, exit
// librería math y minilib

/*
INFORMACIÓN TIPO DE ESCENA archivo .cub

- Se puede separar cada tipo de elemento con una o varias líneas vacías
- Los elementos, excepto el map, pueden ir colocados en cualquier orden
- Problemas config archivo -> "Error\n" + mensaje explícito a elegir

- Resolución:		R [tam renderizado eje x] [tam renderizado eje y]
- Textura norte:	NO ./path_textura_norte
- Textura sur:		SO ./path_textura_sur
- Textura oeste:	WE ./path_textura_oeste
- Textura este:		EA ./path_textura_este
- Textura sprite:	S ./path_textura_sprite
- Color suelo:		F [R,G,B en rango (0,255)]
- Color techo:		C [R,G,B en rango (0,255)]
- map
	- 0: espacios vacíos
	- 1: muros
	- 2: objeto
	- N, S, E o W: posición inicial jugador y orientación
	- Debe estar encerrado/rodeado por muros, si no error
	- Siempre al final del archivo .cub
	- Info de cada elemento puede ir separada por uno o varios espacios

TECLAS

- teclado izq y dcha -> rotar cámara
- W, A, S y D -> desplazar cámara (personaje)
- ESC y/o clic sobre aspa roja -> cerrar ventana, salir del programa limpiamente
- Tamaño ventana pedida en map > pantalla ? Limitar tamaño ventana a la pantalla

*/
typedef struct	s_resolucion {
				int rend_x;
				int rend_y;
}				t_resolucion;

typedef struct	s_texturas {
				char *path_norte;
				char *path_sur;
				char *path_oeste;
				char *path_este;
				char *path_sprite;
}				t_texturas;

typedef struct	s_colores {
				int rgb_suelo[3];
				int rgb_techo[3];
}				t_colores;

typedef struct	s_minilibx {
				void	*new_mlx;
				void	*new_window;
				mlx_img_list_t	*new_img;
}				t_minilix;

typedef struct	s_cub {
				t_resolucion res;
				t_texturas tex;
				t_colores col;
				char **map;
				int	nrows;
				t_minilix minilibx;
}				t_cub;

void			info_tex(char *line, t_cub *info);
void			info_res(char *line, t_cub *info);
void			info_color(char *line, t_cub *info);
char			*info_map(char *line, char *stc);
void			ini_cub(t_cub *info);
void			read_cub(char *filename, t_cub *info);
void			eliminarEspacios(t_cub *cub);


#endif
