/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:55 by yuerliu           #+#    #+#             */
/*   Updated: 2024/12/10 19:23:18 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t		ft_strlen(char const *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*get_next_line(int fd);
char			*get_da_file(int fd, char *rdin);
char			*ft_strchr(char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*shorty(void *dst, const void *src, size_t len);

#endif