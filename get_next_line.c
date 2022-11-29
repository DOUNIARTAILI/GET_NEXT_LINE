/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:26:41 by drtaili           #+#    #+#             */
/*   Updated: 2022/11/29 17:23:32 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_line(char *sta)
{
	int	len;

	len = 0;
	while (sta[len] != '\0')
	{
		if (sta[len] == '\n')
		{
			len++;
			return (len);
		}
		len++;
	}
	return (len);
}

char	*ft_get_line(char *sta)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen_line(sta);
	if (sta == NULL || ft_strlen(sta) == 0)
		return (NULL);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len && sta[i] != '\0')
	{
		line[i] = sta[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *sta, size_t len_line)
{
	size_t	i;
	char	*ret;
	size_t	len;

	i = 0;
	if (sta == NULL || ft_strlen(sta) == 0)
		return (free(sta), NULL);
	len = ft_strlen(sta) - len_line;
	if (len <= 0)
		return (free(sta), sta = NULL, NULL);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (free(sta), sta = NULL, NULL);
	while (sta[len_line + i])
	{
		ret[i] = sta[len_line + i];
		i++;
	}
	free(sta);
	ret[i] = '\0';
	return (ret);
}

char	*ft_read(char *sta, int fd)
{
	char		*buffer;
	int			len;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			return (free(buffer), free(sta), buffer = NULL, sta = NULL, NULL);
		buffer[len] = '\0';
		if (len == 0)
			break ;
		sta = ft_strjoin(sta, buffer);
		if (ft_find_next_line(sta))
			break ;
	}
	free(buffer);
	return (sta);
}

char	*get_next_line(int fd)
{
	static char	*sta;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sta = ft_read(sta, fd);
	if (!sta)
		return (NULL);
	line = ft_get_line(sta);
	sta = get_rest(sta, ft_strlen(line));
	return (line);
}
