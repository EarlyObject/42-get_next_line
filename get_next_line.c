/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/16 09:09:34 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	printf("FUNCTION CALLED\n");
	static unsigned int BUFFER_SIZE;
	BUFFER_SIZE = 32;
	size_t i;
	size_t btsread;
	char *p;
	char *ptr;
	char *temp;
	static size_t offset;
	
	if (fd < 0 || !line)
		return (-1);
	if (!(p = (char*)malloc(BUFFER_SIZE)))
		return (-1);

	//offset = 0;
	int linend;
	linend = 0;
	int templen;
	templen = 0;
	int filend;
	filend = 0;

	ptr = NULL;
	temp = NULL;
	free(ptr);
	free(temp);
	while (linend != 1 && filend != 1)
	{
		printf("in while\n");
		if ((btsread = pread(fd, p, BUFFER_SIZE, offset)) == 0)
		{
			filend = 1;
			break;
		}
		
			//return (0) ;
		i = 0;
		while (i < btsread)
		{
			i++;
			if (p[i] == EOF ){
				printf("EOF REACHED\n");
				filend = 1;
				break ;
			}
				
			if (p[i] == '\n' )
			{
				linend = 1;
				break;
			}
		}
		if (btsread < BUFFER_SIZE)
		{
			linend = 1;
		}
		printf("bites read = %zu, i = %zu, templen = %d, linend = %d, filend = %d\n", btsread, i, templen, linend, filend);
		offset += ((linend == 1 || filend == 1) ? i + 1 : i);
		printf("offset = %zu\n", offset);
		
		temp = ptr;
		if (!(ptr = (char *)malloc(templen + i + ((linend == 1 || filend == 1)? 1 : 0))))
			return (-1);
		printf("content of temp%s\n", temp);
		strncpy(ptr, temp, templen);
		free(temp);
		strncpy(ptr + templen, p, i);
		ft_bzero(p, BUFFER_SIZE);
		//free(p);
		templen += i;
		printf("before zero termination, templen = %d\n", templen);
		if (linend == 1 || filend == 1)
			ptr[templen] = '\0';

		
	}
	//освободить!
	free(p);
	*line = ptr;
	printf("BEFORE EXIT:\n%s\n\n", ptr);
	free(ptr);
	if (filend == 1)
		return (0);
	return(1);
}

