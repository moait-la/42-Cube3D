/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:53:32 by zqouri            #+#    #+#             */
/*   Updated: 2024/01/18 18:39:44 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	if (line[i])
		i++;
	while (line[i])
	{
		str[j] = line[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (free(line), str);
}

char	*get_line_m(char *line)
{
	int		i;
	char	*str;

	str = NULL;
	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = -1;
	while (line[++i] && line[i] != '\n')
		str[i] = line[i];
	if (line[i] && line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*readed(int fd, char *line)
{
	char	*buffer;
	int		char_read;
	char	*str;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return (free(line), line = NULL, NULL);
	while (!ft_strchr(line, '\n'))
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == 0)
		{
			if (line && !*line)
				return (free(line), line = NULL, free(buffer), NULL);
			else
				return (str = line, line = NULL, free(buffer), str);
		}
		if (char_read == -1)
			return (line = NULL, free(buffer), NULL);
		buffer[char_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0
		|| BUFFER_SIZE >= INT_MAX)
		return (free(line), line = NULL, NULL);
	line = readed(fd, line);
	str = get_line_m(line);
	if (!str || !str[0])
		return (free(line), NULL);
	line = rest_line(line);
	return (str);
}
