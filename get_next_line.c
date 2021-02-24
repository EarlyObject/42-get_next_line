/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/24 16:42:52 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t fill_tail(size_t i, size_t *btsread, char **buf, char **ptr)
{
	char *tail;

	tail = NULL;
	if (i < *btsread)
	{
		if (!(tail = (char *)malloc((*btsread) - i)))
			return (-1);
		ft_strlcpy(tail, (*buf) + i + 1, (*btsread) - i);
		free_mem(1, *buf);
		*buf = tail;
		*btsread = (i == 0) ? (*btsread) - 1 : (*btsread) - i;
		free_mem(1, *ptr);
		return (1);
	} else
	{
		buf[0][0] = 0;
		*btsread = 0;
	}
	return (2);
}

size_t fill_temp(char **oldtemp, char **buf, size_t btsread)
{
	size_t i;
	char *temp;

	temp = NULL;
	if (!(temp = (char *)malloc(btsread + 1)))
		return (-1);
	i = 0;
	while (i < btsread)
	{
		if ((*buf)[i] == '\n' || (*buf)[i] == EOF)
			break;
		temp[i] = *(*buf + i);
		i++;
	}
	temp[i] = '\0';
	free_mem(1, *oldtemp);
	*oldtemp = temp;
	return (i);
}

int get_next_line(int fd, char **line)
{
	static size_t btsread;
	size_t i;
	static char *buf;
	static char *ptr;
	char *temp;
	
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!buf)
		if (!(buf = (char *)malloc(BUFFER_SIZE)))
			return (-1);
	temp = NULL;
	ptr = NULL;
	while (btsread > 0 || (btsread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if ((i = fill_temp(&temp, &buf, btsread)) < 0)
			return (i);
		if (ptr)
			ptr = ft_strjoin_sv(&ptr, &temp);
		else{
			char *sub;
			char *ttemp;
			ttemp = NULL;
			sub = NULL;
			if (!(sub = (char *)malloc(ft_strlen(temp) + 1)))
				return (-1);
			ft_strlcpy(sub, temp, ft_strlen(temp) + 1);
			ttemp = ptr;
			ptr = sub;
			free_mem(1, ttemp);
		}
		*line = ptr;
		int f = fill_tail(i, &btsread, &buf, &ptr);
		if (f == -1)
			return -1;
		else if (f == 1)
		{
			free_mem(1, temp);
			return 1;
		}
	}
	free_mem(3, ptr, temp, buf);
	return (btsread == 0 ? 0 : -1);
}

void free_mem(int argc, ...)
{
	va_list valist;
	char *p;
	int i;

	i = 0;
	va_start(valist, argc);
	while(i < argc)
	{
		i++;
		p = va_arg(valist, char *);
		//if (p != NULL)
		if (p)
		{
			free(p);
			p = NULL;
		}
	}
	va_end(valist);
}