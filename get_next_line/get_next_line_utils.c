/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:55:41 by igomez-p          #+#    #+#             */
/*   Updated: 2019/12/10 18:16:49 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s;
	int		p;
	int		p2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	p = 0;
	while (s1[p])
	{
		s[p] = s1[p];
		p++;
	}
	p2 = 0;
	while (s2[p2])
	{
		s[p] = s2[p2];
		p++;
		p2++;
	}
	s[p] = '\0';
	return (s);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	aux;
	int		pos;

	aux = (char)c;
	pos = 0;
	while (s[pos])
	{
		if (s[pos] == aux)
			return ((char *)&s[pos]);
		pos++;
	}
	if (!s[pos] && aux == '\0')
		return ((char *)&s[pos]);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;
	size_t	lend;

	lend = 0;
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (dst[lend] && lend < dstsize)
		lend++;
	l = lend;
	while (src[lend - l] && (lend + 1) < dstsize)
	{
		dst[lend] = src[lend - l];
		lend++;
	}
	dst[lend] = '\0';
	return (ft_strlen(src) + l);
}
