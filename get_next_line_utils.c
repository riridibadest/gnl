/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:06:00 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/20 18:09:28 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*point;

	total = count * size;
	point = malloc(total);
	if (point == NULL)
		return (NULL);
	ft_memset(point, 0, total);
	return (point);
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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*i;
	size_t			n;

	i = (unsigned char *)b;
	n = 0;
	while (n < len)
	{
		i[n] = (unsigned char)c;
		n++;
	}
	return (i);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		sizetotal;
// 	char	*res;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	sizetotal = ft_strlen(s1) + ft_strlen(s2);
// 	res = malloc(sizeof(char) * (sizetotal + 1));
// 	if (!res || !s1 || !s2)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		res[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	res[sizetotal] = 0;
// 	return (res);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_characters;
	char	*str_space;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_characters = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_space = (char *)malloc(total_characters * sizeof(char));
	if (str_space == NULL)
		return (NULL);
	while (s1[i])
	{
		str_space[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str_space[i] = s2[j];
		i++;
		j++;
	}
	str_space[total_characters] = '\0';
	return (str_space);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new;
// 	size_t	i;
// 	size_t	ii;
// 	int		size;

// 	size = (ft_strlen(s1) + ft_strlen(s2));
// 	new = (char *)malloc((sizeof(char)) * (size + 1));
// 	if (!new || !s1 || !s2)
// 		return (NULL);
// 	i = 0;
// 	ii = 0;
// 	while (*s1 != '\0')
// 	{
// 		new[i] = s1[i];
// 		i++;
// 	}
// 	while (*s2 != '\0')
// 	{
// 		new[i + ii] = s2[ii];
// 		ii++;
// 	}
// 	new[i + ii] = '\0';
// 	return (new);
// }

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
