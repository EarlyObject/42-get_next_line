/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/25 15:20:26 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	char *ptr;
	static char *temp;
	size_t n;
	char *nlp;
	char *ttemp;

	n = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ptr = NULL;
	while (temp || (n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = '\0';
		if (!temp)
			temp = ft_strdup(buf);
		if ((nlp = ft_strchr(temp, '\n')))
		{
			ptr = ptr ? ft_strjoin(ptr, makest(temp, nlp - temp))
				: ft_strdup(makest(temp, nlp - temp));
			ttemp = temp;
			temp = makest(nlp + 1, ft_strlen(temp) - (nlp - temp) - 1);
			free(ttemp);
			ttemp = NULL;
			break;
		}
		else
		{
			ptr = ptr? ft_strjoin(ptr, temp) : makest(temp, ft_strlen(temp));
			free_mem(1, (void **)&temp);
		}
	}
	if (n < 0)
		return (-1);
	*line = ptr;
	return (temp ? 1 : 0);
}

char *makest(char *buf, size_t len)
{
	char *str;
	size_t i;
	
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(str+i) = *(buf + i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
void free_mem(int argc, ...)
{
	va_list valist;
	void **p;
	int i;

	i = 0;
	va_start(valist, argc);
	while(i < argc)
	{
		i++;
		p = va_arg(valist, void **);
		if (*p)
		{
			ft_memset(*p, 0, ft_strlen(*p));
			free(*p);
			p = NULL;
		}
	}
	va_end(valist);
}