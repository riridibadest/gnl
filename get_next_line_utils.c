/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:06:00 by yuerliu           #+#    #+#             */
/*   Updated: 2024/12/10 19:13:47 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	size_t	total;
// 	void	*point;

// 	total = count * size;
// 	point = malloc(total);
// 	if (point == NULL)
// 		return (NULL);
// 	ft_memset(point, 0, total);
// 	return (point);
// }

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	what;

	i = 0;
	what = 0;
	while (src[what] != '\0')
	{
		what++;
	}
	if (size == 0)
		return (what);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	return (what);
}

size_t	ft_strlen(char const *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0' || *s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	strlens;

	if (s == NULL)
		return (NULL);
	strlens = ft_strlen(s);
	if (start >= strlens)
		return (ft_strdup(""));
	if (len > strlens - start)
		len = strlens - start;
	sub = malloc((sizeof(char)) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*pimp;

	i = ft_strlen(s1) + 1;
	pimp = (char *)malloc(i);
	if (pimp == NULL)
		return (NULL);
	ft_strlcpy(pimp, s1, i);
	pimp[i - 1] = '\0';
	return (pimp);
}
