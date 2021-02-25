/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:49 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/25 16:12:35 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
//#include <dlfcn.h>
#include <execinfo.h>
#include <stdarg.h>

int get_next_line(int fd, char **line);
void ft_bzero(void *s, size_t n);
size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
void *ft_memset(void *b, int c, size_t len);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
void check_leaks();
void free_mem(int argc, ...);
char *ft_strchr(const char *s, int c);
char *makestr(char *buf, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s1);
void *ft_memset(void *b, int c, size_t len);

#endif