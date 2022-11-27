/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:26:41 by drtaili           #+#    #+#             */
/*   Updated: 2022/11/27 04:34:51 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *sta)
{
	char *line;
	int i;
    int len;

	i = 0;
    len = 0;
    if (sta == NULL || ft_strlen(sta) == 0)
        return (free(sta), NULL);
	while (sta[len] != '\0')
	{
        if (sta[len] == '\n')
        {
            len++;
            break;
        }
        len++;
    }
    // printf("len_line:%d\n",len);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len && !sta)
	{
		line[i] = sta[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *sta, size_t len_line)
{
	size_t i;
	char *ret;
    size_t  len;

	i = 0;
    if (sta == NULL || ft_strlen(sta) == 0)
        return (NULL);
    len = ft_strlen(sta) - len_line;
    if (len <= 0)
        return (free (sta),NULL);
    // printf("-->sta:%zu\tlen_line:%zu\n", ft_strlen(sta) ,len_line);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = sta[len_line + i];
		i++;
	}
	ret[i] = '\0';
	free(sta);
	return (ret);
}

char *get_next_line(int  fd)
{
    char        *buffer;
    static char *sta;
    char        *line;
    int         len;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    while (1)
    {
        len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
		{
            free(buffer);
        	return (NULL);
        }
        buffer[len] = '\0';
		if (len == 0)
            break;
        sta = ft_strjoin(sta, buffer);
        if (ft_strchr(sta, '\n') != NULL)
            break;
    }
	free(buffer);
	line = get_line(sta);
	sta = get_rest(sta, ft_strlen(line));
	//printf("%s\n",sta);
	return (line);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
//     char *str;
    
//     // str = get_next_line(fd);
//     // while (str != NULL)
//     // {
// 	//     printf("%s", str);
//     //     str = get_next_line(fd);
//     // }
// 	printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
// }