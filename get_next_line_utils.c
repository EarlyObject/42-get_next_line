/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:33 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/25 15:05:22 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t
	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

size_t
	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	i;
	size_t			result;

	i = 0;
	if (!src)
		return (0);
	result = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[i] != '\0' && (i < dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (result);
}

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total;
	size_t	original;

	original = dstsize;
	total = ft_strlen(dst) + ft_strlen(src);
	while (*dst != 0 && dstsize > 0)
	{
		dst++;
		dstsize--;
	}
	if (dstsize == 0)
		return (ft_strlen(src) + original);
	while (*src != 0 && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (total);
}

char
	*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char
	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	total;
	char	*p;

	if (!s1)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total = len1 + len2 + 1;
	p = (char *)malloc(total * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, total);
	ft_strlcat(p, s2, total);
	return (p);
}

char
	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*p;

	len = ft_strlen(s1) + 1;
	p = (char *)malloc(len * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, len);
	return (p);
}

void
	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;

	dest = b;
	if (!b)
		return (NULL);
	while (len > 0)
	{
		*dest = (unsigned char)c;
		dest++;
		len--;
	}
	return (b);
}