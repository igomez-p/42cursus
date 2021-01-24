/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:21:03 by igomez-p          #+#    #+#             */
/*   Updated: 2021/01/24 12:58:26 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"

static char	*path_tex(char *line)
{
	int i;

	line = ft_strnstr(line, "./", ft_strlen(line));
	if (!line)
	{
		perror("Error\nNo se encuentra la textura\n");
		return (NULL);
	}
	i = ft_strlen(line) - 1;
	while (line[i] == ' ')
	{
		line[i] = '\0';
		i--;
	}
	return (strdup(line));
}

void		info_tex(char *line, t_cub *info)
{
	if (!ft_strncmp(line, "NO", 2))
		info->tex.path_norte = path_tex(line);
	else if (!ft_strncmp(line, "SO", 2))
		info->tex.path_sur = path_tex(line);
	else if (!ft_strncmp(line, "WE", 2))
		info->tex.path_oeste = path_tex(line);
	else if (!ft_strncmp(line, "EA", 2))
		info->tex.path_este = path_tex(line);
	else if (!ft_strncmp(line, "S", 1))
		info->tex.path_sprite = path_tex(line);
}

static int	save_int(char **line)
{
	char	*num;
	char	caracter[2];
	int		n;

	num = ft_strdup("");
	while (!ft_isdigit((int)**line) && **line)
		*line = *line + 1;
	while (ft_isdigit((int)**line))
	{
		caracter[0] = **line;
		caracter[1] = '\0';
		num = ft_swap(num, caracter);
		*line = *line + 1;
	}
	n = ft_atoi(num);
	free(num);
	return (n);
}

void	info_res(char *line, t_cub *info)
{
	if (ft_strnstr(line, "R", 1))
	{
		info->res.rend_x = save_int(&line);
		info->res.rend_y = save_int(&line);
		if (info->res.rend_x <= 0 || info->res.rend_y <= 0)
			perror("Error\nResolución incorrecta\n");
	}
}

void	info_color(char *line, t_cub *info)
{
	if (ft_strnstr(line, "F", 1))
	{
		info->col.rgb_suelo[0] = save_int(&line);
		if (!(info->col.rgb_suelo[0] >= 0 && info->col.rgb_suelo[0] <= 255))
			perror("Error\nValor RGB incorrecto\n");
		info->col.rgb_suelo[1] = save_int(&line);
		if (!(info->col.rgb_suelo[1] >= 0 && info->col.rgb_suelo[1] <= 255))
			perror("Error\nValor RGB incorrecto\n");
		info->col.rgb_suelo[2] = save_int(&line);
		if (!(info->col.rgb_suelo[2] >= 0 && info->col.rgb_suelo[2] <= 255))
			perror("Error\nValor RGB incorrecto\n");

	}
	else if (ft_strnstr(line, "C", 1))
	{
		info->col.rgb_techo[0] = save_int(&line);
		if (!(info->col.rgb_techo[0] >= 0 && info->col.rgb_techo[0] <= 255))
			perror("Error\nValor RGB incorrecto\n");
		info->col.rgb_techo[1] = save_int(&line);
		if (!(info->col.rgb_techo[1] >= 0 && info->col.rgb_techo[1] <= 255))
			perror("Error\nValor RGB incorrecto\n");
		info->col.rgb_techo[2] = save_int(&line);
		if (!(info->col.rgb_techo[2] >= 0 && info->col.rgb_techo[2] <= 255))
			perror("Error\nValor RGB incorrecto\n");
	}
}

int		len_linea(char *line)
{
	int i;
	int cont;

	i = 0;
	cont = 0;
	while (line[i])
	{
		if (line[i] == VACIO || line[i] == MURO || line[i] == OBJETO || line[i] == NADA ||
			line[i] == 'N' || line[i] == 'S' || line[i] == 'O' || line[i] == 'E')
			cont++;
		i++;
	}
	return (cont);
}

char	*fill_map(char *line)
{
	char	*aux;
	int		p;
	int		k;

	p = 0;
	k = len_linea(line);
	if ((int)ft_strlen(line) == k)
		return (ft_strdup(line));
	else
		aux = malloc(k + 1);
	if (!aux)
		return (NULL);
	k = 0;
	while (line[p])
	{
		if (line[p] == VACIO || line[p] == MURO || line[p] == OBJETO || line[p] == NADA ||
			line[p] == 'N' || line[p] == 'S' || line[p] == 'O' || line[p] == 'E')
		{
			aux[k] = line[p];
			k++;
		}
		p++;
	}
	aux[k] = '\0';
	return (aux);
}

char	*info_map(char *line, char *stc)
{
	char	*aux;

	if (!stc)
		stc = fill_map(line);
	else
	{
		aux = fill_map(line);
		stc = ft_swap(stc, aux);
		free(aux);
	}
	return (stc);
}

int		check_errors(t_cub cub)
{
	// Mapa debe estar rodeado por muros
	int i, j;

	i = 0;
	j = 0;

	while (cub.map[0][i] && cub.map[cub.nrows-1][j])
	{
		if (cub.map[0][i] != MURO || cub.map[cub.nrows-1][j] != MURO)
			return -1;

		i++;
		j++;
	}
	return 0;
}
