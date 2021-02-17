/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/17 15:45:56 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	printf("FUNCTION CALLED\n");
	static unsigned int BUFFER_SIZE;
	BUFFER_SIZE = 32;
	size_t i;
	static size_t btsread;
	char *buf;
	static char *tail;
	char *ptr;
	char *temp;
	static size_t offset;
	
	if (fd < 0 || !line)
		return (-1);
	if (!(buf = (char*)malloc(BUFFER_SIZE)))
		return (-1);

	ptr = NULL;
	temp = NULL;
	//free(ptr);
	//free(temp);

	while (offset || (btsread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (offset)
		{
			buf = tail;
		}
		if (!(temp = (char *)malloc(btsread)))
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
		//stick ptr and temp
		ptr = ptr ? ft_strjoin(ptr, temp) : temp;
		*line = ptr;
		if (i < btsread)
		{
			//создаем с размером учитывая что не нужна ячейка для символа переноса строки
			if (!(tail = (char *)malloc(btsread - i)))
				return (-1);
			//добавляем 1, так как надо проскочить перенос строки
			ft_strlcpy(tail, buf + i + 1, btsread - i);
			offset = i;
			btsread = btsread - i;
			i = 0;
			return (1);
		} else
		{
			offset = 0;
			i = 0;
			btsread = 0;
		}
	}
	return (btsread == 0 ? 0 : -1);
}
