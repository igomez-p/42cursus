/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:20:33 by igomez-p          #+#    #+#             */
/*   Updated: 2019/12/13 15:14:58 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_temp(char *l)
{
	int		p;
	int		k;
	char	*temp;

	p = 0;
	while (l[p] && l[p] != '\n')
		p++;
	temp = (char *)malloc(sizeof(char) * (p + 1));
	if (!temp)
		return (NULL);
	k = 0;
	while (k != p)
	{
		temp[k] = l[k];
		k++;
	}
	temp[k] = '\0';
	return (temp);
}

char	*ft_newstatic(char *aux, char *l, char **line)
{
	char	*aux2;

	aux2 = ft_strdup(&aux[1]);
	*line = ft_temp(l);
	free(l);
	l = NULL;
	l = ft_strdup(aux2);
	free(aux2);
	return (l);
}

char	*ft_swap(char *l, char *buf)
{
	char *temp;

	temp = ft_strjoin(l, buf);
	free(l);
	l = ft_strdup(temp);
	free(temp);
	return (l);
}

int		get_next_line(int fd, char **line)
{
	static char	*l[4096];
	char		*b;
	int			nbytes;
	char		*aux;

	l[fd] = (!l[fd]) ? ft_strdup("") : l[fd];
	if (!(b = malloc(BUFFER_SIZE + 1)) || fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((nbytes = read(fd, b, BUFFER_SIZE)) > 0)
	{
		b[nbytes] = '\0';
		l[fd] = ft_swap(l[fd], b);
		if ((aux = ft_strchr(l[fd], '\n')) != NULL)
		{
			free(b);
			return (((l[fd] = ft_newstatic(aux, l[fd], line)) != NULL) ? 1 : 1);
		}
	}
	free(b);
	if ((aux = ft_strchr(l[fd], '\n')) != NULL)
		return (((l[fd] = ft_newstatic(aux, l[fd], line)) != NULL) ? 1 : 1);
	*line = ft_strdup(l[fd]);
	free(l[fd]);
	l[fd] = NULL;
	return (0);
}
