/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseragio <dseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:53:32 by dseragio          #+#    #+#             */
/*   Updated: 2025/11/13 17:42:37 by dseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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
	static char	*rest_str[4096];
	char		*final_line;

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest_str[fd])
	{
		rest_str[fd] = ft_strdup("");
		if (!rest_str[fd])
			return (NULL);
	}
	rest_str[fd] = fill_line(fd, rest_str[fd]);
	if (!rest_str[fd])
		return (NULL);
	final_line = ft_get_line(rest_str[fd]);
	if (!final_line)
	{
		free(rest_str[fd]);
		rest_str[fd] = NULL;
		return (NULL);
	}
	rest_str[fd] = clean_rest(rest_str[fd]);
	return (final_line);
}
