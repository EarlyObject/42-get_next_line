/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/25 19:47:26 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int
	get_next_line(int fd, char **line)
{
	size_t		n;
	char		buf[BUFFER_SIZE + (n = 1)];
	static char	*rdline = NULL;
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	(rdline == NULL) ? rdline = mk_nstr(0) : NULL;
	while (!ft_strchr(rdline, '\n') && (n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = '\0';
		temp = ft_strjoin(rdline, buf);
		free_mem(1, (void **)&rdline);
		rdline = temp;
	}
	if (n < 0)
		return (-1);
	*line = (n == 0) ? ft_strdup(rdline)
		: ft_strdup(mkstr(temp, ft_strchr(temp, '\n') - temp));
	if (n > 0)
		temp = mkstr(ft_strchr(temp, '\n') + 1,
	ft_strlen(temp) - (ft_strchr(temp, '\n') - temp) - 1);
	free_mem(1, (void **)&rdline);
	rdline = temp;
	return (n ? 1 : 0);
}

char
	*mk_nstr(size_t size)
{
	char *p;

	if (!(p = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(p, 0, size + 1);
	return (p);
}

char
	*mkstr(char *buf, size_t len)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(str + i) = *(buf + i);
		i++;
	}
	str[i] = '\0';
	return (str);
}

void
	free_mem(int argc, ...)
{
	va_list	valist;
	void	**p;
	int		i;

	i = 0;
	va_start(valist, argc);
	while (i < argc)
	{
		i++;
		p = va_arg(valist, void **);
		if (*p)
		{
			ft_memset(*p, 0, ft_strlen(*p));
			free(*p);
			*p = NULL;
		}
	}
	va_end(valist);
}
