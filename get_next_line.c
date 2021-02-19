/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/19 11:06:40 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t fill_temp(char **temp, char **buf, size_t btsread);

int get_next_line(int fd, char **line)
{
	static size_t btsread;
	static size_t flag;
	static char *tail;
	size_t i;
	char *buf;
	static char *ptr;
	char *temp;

	if (fd < 0 || !line || !(buf = (char *)malloc(BUFFER_SIZE)))
		return (-1);
	while (flag || (btsread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (flag)
			buf = tail;

		//i = fill_temp(&temp, &buf, btsread);
		if (!(temp = (char *)malloc(btsread + 1)))
			return (-1);
		i = 0;
		while (i < btsread)
		{
			if (buf[i] == '\n' || buf[i] == EOF)
				break;
			*(temp + i) = *(buf + i);
			i++;
		}
		temp[i] = '\0';
		ptr = ptr ? ft_strjoin(ptr, temp) : temp;
		*line = ptr;
		if (i < btsread)
		{
			if (!(tail = (char *)malloc(btsread - i)))
				return (-1);
			ft_strlcpy(tail, buf + i + 1, btsread - i);
			flag = 1;
			btsread = (i == 0) ? btsread - 1 : btsread - i;
			ptr = NULL;
			return (1);
		} else
		{
			flag = 0;
			btsread = 0;
		}
	}
	return (btsread == 0 ? 0 : -1);
}
