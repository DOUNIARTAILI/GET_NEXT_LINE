/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 01:44:23 by drtaili           #+#    #+#             */
/*   Updated: 2022/11/27 01:44:26 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
    if (!s)
        return (len);
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	ret;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (!dstsize)
		return (slen);
	len = ft_strlen(dst);
	ret = len + slen;
	if (dstsize <= len)
		return (slen + dstsize);
	while (src[i] && len < dstsize - 1)
	{
		dst[len] = src[i];
		len++;
		i++;
	}
	dst[len] = '\0';
	return (ret);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (!dstsize)
		return (slen);
	while (i < slen && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*s;

	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len1 + len2 + 1);
	ft_strlcat(s, s2, len1 + len2 + 1);
	return (s);
}


char	*ft_strchr(char *s, int c)
{
	char	chr;
	size_t	len;
	size_t	i;

	chr = (char)c;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
		i++;
	}
	return (NULL);
}
