/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/12 21:36:17 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static unsigned int BUFFER_SIZE;

	BUFFER_SIZE = 32;
	size_t i;
	
	char *p;
	size_t btsread;
	//size_t offset;
	//char linebuf[BUFFER_SIZE];
	//char c;
	int row;
	int chr;
	char *ptr;

	//if filedescriptor points to error
	if (fd < 0 || !line)
		return (-1);

	if (!(p = (char*)malloc(BUFFER_SIZE)))
		return (-1);

	printf("fd received = %d\n", fd);
	//count how many bytes were read
	btsread = read(fd, p, BUFFER_SIZE);
	printf("bytes read  = %zu\n", btsread);
	
	row = 0;
	//while there is no read error and we didn't reach end of line -> keep reading
	printf("before while\n");
	while (btsread > 0 && btsread <= BUFFER_SIZE)
	{
		chr = 0;
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (p[i] == (char)'\n')
				break ;
			i++;
		}
		printf("after while, i = %zu\n", i);
		if (!(ptr = (char *)malloc(i + 1)))
			return (-1);

		ft_bzero(ptr, i + 1);
		ft_strlcpy(ptr, p, i + 1);

		printf("after malloc, i = %zu\n", i);
		
			printf("ptr string %s\n", ptr);
		break;
		/* c = p[i];
		printf("char %d = %c\n", i, c);
		
		while (i < btsread && (c != EOF && c != '\n'))
		{
			line[row][chr] = c;
			chr++;
			i++;
		}
		} */
	}
	printf("after while\n");
	if (btsread == 0)
		return (0);
	return (99);
}

