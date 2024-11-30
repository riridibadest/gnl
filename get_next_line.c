/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:00:18 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/21 19:51:12 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_da_file(int fd, char *gary)
{
	int		rd;
	char	*spongebob;
	char	*krabs;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	spongebob = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!spongebob)
		return (NULL);
	while ((rd = read(fd, spongebob, BUFFER_SIZE)) > 0)
	{
		if (rd < 0)
			return (free(spongebob), NULL);
		if (rd == 0)
			break ;
		spongebob[rd] = 0;
		krabs = ft_strjoin(gary, spongebob);
		free(gary);
		gary = krabs;
	}
	free(spongebob);
	return (gary);
}

int	len_line(char *patrick)
{
	int	len;

	len = 0;
	while (patrick[len] && patrick[len] != '\n')
		len++;
	return (len);
}

char	*get_one_line(char *spongebob)
{
	char	*patrick;
	char	*squidward;

	if (!spongebob)
		spongebob = ft_calloc(1, 1);
	patrick = ft_calloc((len_line(spongebob) + 2), sizeof(char));
	if (patrick == NULL)
		return (NULL);
	squidward = patrick;
	while (*spongebob && *spongebob != '\n')
		*patrick++ = *spongebob++;
	if (*spongebob == '\n')
		*patrick++ = '\n';
	*patrick++ = '\0';
	return (squidward);
}

char	*shorty(char *spongebob)
{
	char	*sandy;
	int		len;
	int		i;

	i = 0;
	len = len_line(spongebob);
	sandy = ft_calloc((ft_strlen(spongebob) - len + 1), sizeof(char));
	if (sandy == NULL)
		return (NULL);
	while (spongebob[len + i])
	{
		sandy[i] = spongebob[len + i];
		i++;
	}
	sandy[i] = '\0';
	free(spongebob);
	return (sandy);
}

char	*get_next_line(int fd)
{
	static char	*spongebob;
	char		*squidward;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	spongebob = get_da_file(fd, spongebob);
	if (!spongebob)
		return (NULL);
	squidward = get_one_line(spongebob);
	if (!squidward)
		return (free(squidward), NULL);
	spongebob = shorty(spongebob);
	return (squidward);
}
