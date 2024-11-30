/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:00:18 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/24 23:00:48 by yuerliu          ###   ########.fr       */
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
	if (!gary)
		gary = ft_calloc(1, 1);
	rd = read(fd, spongebob, BUFFER_SIZE);
	printf("Readbuffer %s\n", spongebob);
	while (rd > 0)
	{
		rd = read(fd, spongebob, BUFFER_SIZE);
		if (rd < 0)
			return (free(spongebob), NULL);
		if (rd == 0)
			break ;
		spongebob[rd] = 0;
		krabs = ft_strjoin(gary, spongebob);
		printf("Read content %s\n", krabs);
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
	int	oh;

	if (!spongebob)
		spongebob = ft_calloc(1, 1);
	oh = (len_line(spongebob));
	patrick = ft_calloc((oh + 2), sizeof(char));
	if (patrick == NULL)
		return (NULL);
	oh = 0;
	while (spongebob[oh] && spongebob[oh] != '\n')
	{
		patrick[oh] = spongebob[oh];
		oh++;
	}
	if (spongebob[oh] == '\n')
		patrick[oh] = '\n';
	printf("Patrick %s\n", patrick);
	patrick[oh++] = '\0';
	return (patrick);
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
		return (free(sandy), NULL);
	while (spongebob[len + i])
	{
		sandy[i] = spongebob[len + i];
		i++;
	}
	sandy[i] = '\0';
	printf("sandy %s\n", sandy);
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
	printf("GNL-spongebob %s\n", spongebob);
	if (!spongebob)
		return (NULL);
	squidward = get_one_line(spongebob);
	printf("GNL-squidward %s\n", squidward);
	if (!squidward)
		return (free(squidward), NULL);
	spongebob = shorty(spongebob);
	printf("Short-spongebob %s\n", spongebob);
	return (squidward);
}

int	main(void)
{
	int		fd;
	char	*one;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("OH");
		return (1);
	}
	one = get_next_line(fd);
	printf("LETSEE %s", one);
	free(one);
	close(fd);
	return (0);
}

// int main(void)
// {
// 	static char	*spongebob;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("OH");
// 		return (1);
// 	}
// 	spongebob = get_da_file(fd, spongebob);
// 	printf("spongebob1:%s\n", spongebob);
// }