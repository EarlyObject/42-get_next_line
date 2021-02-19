/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/19 20:42:11 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t fill_temp(char **temp, char **buf, size_t btsread);
size_t fill_tail(size_t i, size_t *btsread, char **buf, char **ptr);

int get_next_line(int fd, char **line)
{
	static size_t btsread;
	//static char *tail;
	size_t i;
	static char *buf;
	static char *ptr;
	char *temp;

	if (fd < 0 || !line)
		return (-1);
	if (!buf)
		if (!(buf = (char *)malloc(BUFFER_SIZE)))
				return (-1);
	//while (tail || (btsread = read(fd, buf, BUFFER_SIZE)) > 0)
	while (*buf || (btsread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		//if ((i = fill_temp(&temp, tail ? &tail : &buf, btsread)) < 0)
		if ((i = fill_temp(&temp, &buf, btsread)) < 0)
			return (i);
		ptr = ptr ? ft_strjoin(ptr, temp) : temp;
		*line = ptr;

		int f = fill_tail(i, &btsread, &buf, &ptr);
		if (f == -1)
			return -1;
		else if(f == 1)
			return 1;


		/* if (i < btsread)
		{
			if (!(tail = (char *)malloc(btsread - i)))
				return (-1);
			ft_strlcpy(tail, buf + i + 1, btsread - i);
			btsread = (i == 0) ? btsread - 1 : btsread - i;
			ptr = NULL;
			return (1);
		} else
		{
			tail = NULL;
			btsread = 0;
		} */
	}
	return (btsread == 0 ? 0 : -1);
}

size_t fill_tail(size_t i, size_t *btsread, char **buf, char **ptr)
{
	char *tail;
	
	if (i < *btsread)
	{
		if (!(tail = (char *)malloc((*btsread) - i)))
			return (-1);
		ft_strlcpy(tail, (*buf) + i + 1, (*btsread) - i);
		//free(*buf);
		*buf = tail;
		//free(tail);
		*btsread = (i == 0) ? (*btsread) - 1 : (*btsread) - i;
		*ptr = NULL;
		return (1);
	} else
	{
		//tail = NULL;
		buf[0][0] = 0;
		*btsread = 0;
	}
	return (2);
}

size_t fill_temp(char **temp, char **buf, size_t btsread)
{
    size_t i;

    if (!(*temp = (char *)malloc(btsread + 1)))
            return (-1);
    i = 0;
    while (i < btsread)
    {
        if ((*buf)[i] == '\n' || (*buf)[i] == EOF)
            break;
        *(*temp + i) = *(*buf + i);
        i++;
    }
    (*temp)[i] = '\0';
    return (i);
}
