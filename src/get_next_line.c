/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseragio <dseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:53:32 by dseragio          #+#    #+#             */
/*   Updated: 2025/11/13 11:41:38 by dseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*clean_rest(char *buffer)
{
	int		i;
	char	*new_rest;
	size_t	len_rest;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	len_rest = ft_strlen(buffer);
	new_rest = ft_substr(buffer, i + 1, len_rest);
	free(buffer);
	return (new_rest);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	size_t	len;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	len = i;
	if (buffer[i] == '\n')
		len++;
	return (ft_substr(buffer, 0, len));
}

char	*fill_line(int fd, char *rest_str)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(rest_str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), free(rest_str), NULL);
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		rest_str = ft_strjoin(rest_str, buffer);
		if (!rest_str)
			return (free(buffer), NULL);
	}
	return (free(buffer), rest_str);
}

char	*get_next_line(int fd)
{
	static char	*rest_str;
	char		*final_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest_str)
	{
		rest_str = ft_strdup("");
		if (!rest_str)
			return (NULL);
	}
	rest_str = fill_line(fd, rest_str);
	if (!rest_str)
		return (NULL);
	final_line = ft_get_line(rest_str);
	if (!final_line)
	{
		free(rest_str);
		rest_str = NULL;
		return (NULL);
	}
	rest_str = clean_rest(rest_str);
	return (final_line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
        int fd = open("get_next_line.h", O_RDONLY);
        char    *line;
        int     i = 0;
        while ((line = get_next_line(fd)))
        {
                printf("%s", line);
                free(line);
                i++;
        }
        close(fd);
}
*/
