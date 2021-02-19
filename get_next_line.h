/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:49 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/17 19:53:58 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int get_next_line(int fd, char **line);
void ft_bzero(void *s, size_t n);
size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
void *ft_memset(void *b, int c, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
//size_t get_temp(size_t btsread, size_t i, char *buf, char **temp);

#endif