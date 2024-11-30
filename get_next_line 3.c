/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:00:18 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/29 15:08:19 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// typedef struct test_struct {
// 	int a;
// 	int b;
// 	int c;
// 	int d;
// 	int e;
// 	int f;
// 	const char *test;
// }	t_test_struct;

// void initialize(t_test_struct a); // (what)
// void initialize(t_test_struct *a) {
// 		a->a;
// 		a->b;
// 	}// (where)

// ->24234234 234234234 234234234 23423423 234234234 5345345 354435345
// 24234234 ->234234234 234234234 23423423 234234234 5345345 354435345

// int	len_line(char *patrick)
// {
// 	int	len;

// 	len = 0;
// 	while (patrick[len] && patrick[len] != '\n')
// 		len++;
// 	return (len);
// }
//only used in shorty so ignore for now

// char	*get_one_line(char *spongebob)
// {
// 	char	*patrick;
// 	int	oh;

// 	if (!spongebob)
// 		spongebob = ft_calloc(1, 1);
// 	oh = (len_line(spongebob));
// 	patrick = ft_calloc((oh + 2), sizeof(char));
// 	if (patrick == NULL)
// 		return (NULL);
// 	oh = 0;
// 	while (spongebob[oh] && spongebob[oh] != '\n')
// 	{
// 		patrick[oh] = spongebob[oh];
// 		oh++;
// 	}
// 	if (spongebob[oh] == '\n')
// 		patrick[oh] = '\n';
// 	patrick[oh++] = '\0';
// 	return (patrick);
// 	// printf("Patrick %s\n", patrick);

// }
// char	*shorty(char *spongebob)
// {
// 	char	*sandy;
// 	int		len;
// 	int		i;

// 	i = 0;
// 	len = len_line(spongebob);
// 	sandy = ft_calloc((ft_strlen(spongebob) - len + 1), sizeof(char));
// 	if (sandy == NULL)
// 		return (free(sandy), NULL);
// 	while (spongebob[len + i])
// 	{
// 		sandy[i] = spongebob[len + i];
// 		i++;
// 	}
// 	sandy[i] = '\0';
// 	// printf("sandy %s\n", sandy);
// 	free(spongebob);
// 	return (sandy);
// }
//shorty handled in the gnl function

char	*get_da_file(int fd, char *gary)

{
	int	rd;
	char	spongebob[BUFFER_SIZE + 1];

	ft_memset(&spongebob, 0, BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, spongebob, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		if (rd == 0)
			break ;
		spongebob[rd] = 0;
		gary = ft_strjoin(gary, spongebob);
		if (ft_strchr(gary, '\n'))
			break ;
	}
	// printf("Read content: GARRRYYY  %s\n", gary);
	return (gary);
}

char	*get_next_line(int fd)
{
	static char	*spongebob;
	char		*squidward;
	char		*ricky;
	size_t		morty;
	ssize_t	cut;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	spongebob = get_da_file(fd, spongebob);
	//1.I/n AM/n YOU/0(9byte)
	//2.AM/n YOU/0
	//3.YOU/0
	if (!spongebob)
		return (NULL);
	ricky = ft_strchr(spongebob, '\n');
	//1.(I)/n
	//2.(M)/n
	//3.Can not find/n
	if (!ricky)
		ricky = ft_strchr(spongebob, '\0');
		//3.(U)/0
	morty = ricky - spongebob;
	//1.1
	//2.(2 - 0) = 2
	//3.(3 - 0) = 3
	squidward = ft_substr(spongebob, 0, morty);
	//1. I
	//2. AM
	//3. YOU
	cut = ft_strlen(spongebob) - morty;
	//1. 8
	//2. 3
	//3. (3 - 3)here is the problem; i should mark this as the end of the file.
	if (cut == 0)
		spongebob = NULL;
	else
		ft_memmove(spongebob, &spongebob[morty + 1], cut);
		//1. AM/n YOU/0
		//2. from location 4, YOU/0;
	// printf("GNL-squidward %s\n", squidward);
	printf("GNL-SPONGEBOB: %s\n", spongebob);
	if (!squidward)
		return (free(squidward), NULL);
	// spongebob = shorty(spongebob);
	// printf("Short-spongebob %s\n", spongebob);
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
	printf("LETSEE %s\n", one);
	one = get_next_line(fd);
	printf("LETSEE %s\n", one);
	one = get_next_line(fd);
	printf("LETSEE %s\n", one);
	one = get_next_line(fd);
	printf("LETSEE %s\n", one);
	one = get_next_line(fd);
	printf("LETSEE %s\n", one);
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