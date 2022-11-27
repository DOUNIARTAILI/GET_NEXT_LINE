/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:26:41 by drtaili           #+#    #+#             */
/*   Updated: 2022/11/27 05:56:28 by drtaili          ###   ########.fr       */
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
        return (NULL);
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
	size_t i;
	char *ret;
    size_t  len;

	i = 0;
    if (sta == NULL || ft_strlen(sta) == 0)
        return (NULL);
    len = ft_strlen(sta) - len_line;
    if (len <= 0)
       { free(sta);
       sta = NULL;
        return (NULL);}
    // printf("-->sta:%zu\tlen_line:%zu\n", ft_strlen(sta) ,len_line);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (sta[len_line + i])
	{
		ret[i] = sta[len_line + i];
		i++;
	}
	free(sta);
	ret[i] = '\0';
	return (ret);
}

char *get_next_line(int  fd)
{
    char        *buffer;
    static char *sta[1024];
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
        sta[fd] = ft_strjoin(sta[fd], buffer);
        if (ft_find_next_line(sta[fd]))
            break;
    }
	free(buffer);
	line = get_line(sta[fd]);
	sta[fd] = get_rest(sta[fd], ft_strlen(line));
	//printf("%s\n",sta);
	return (line);
}

// int main()
// {
// 	int fd = open("test3.txt", O_RDONLY);
//     char *str[1024];
//     int i = 0;
    
//     // str = get_next_line(fd);
//     // while (str != NULL)
//     // {
// 	//     printf("%s", str);
//     //     str = get_next_line(fd);
//     // }
//     while(i < 10475)
// 	{    printf("%s", get_next_line(fd));
//         i++;
//     }
//     close(fd);

// }