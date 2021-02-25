/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:49 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/25 19:49:17 by asydykna         ###   ########.fr       */
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
size_t ft_strlen(const char *s);
void *ft_memset(void *b, int c, size_t len);
void check_leaks();
void free_mem(int argc, ...);
char *ft_strchr(const char *s, int c);
char *mkstr(char *buf, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s1);
void *ft_memset(void *b, int c, size_t len);
char *mk_nstr(size_t size);

#endif