/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 07:00:00 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/06 13:12:31 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_aloc(char	*line)
{
	char	*buff;

	if (line == NULL)
		line = malloc(sizeof(char) * BUFF_SIZE + 1);
	else
	{
		buff = ft_strdup(line);
		free(line);
		line = malloc(sizeof(char) * ft_strlen(buff) + BUFF_SIZE + 1);
		line = ft_strcpy(line, buff);
		free(buff);
	}
	return (line);
}

char	*ft_endl(char *line)
{
	char	*save;
	int		i;
	int		j;
	int		check;

	save = ft_strdup(line);
	i = 0;
	j = 0;
	while (save[i] != '\n')
		i++;
	check = i;
	while (save[i + j] != '\0')
	{
		j++;
		if (save[i + j] == '\n')
			check = j + i;
	}
	save[check] = '\0';
	return (save);
}

char	*ft_getline(const int fd)
{
	static char		*line;
	char			*buff;
	int				len;

	buff = malloc(sizeof(char) * BUFF_SIZE + 1);
	while (!ft_strchr(buff, '\n'))
	{
		line = ft_aloc(line);
		len = read(fd, buff, BUFF_SIZE);
		if (len == 0)
			return (NULL);
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (ft_endl(line));
}

char	*ft_pure(char	*buffer)
{
	char	*buffer2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	while (buffer[i + j] != '\0')
		j++;
	buffer2 = malloc (sizeof(char) * i + j + 1);
	j = 0;
	while (buffer[i + j] != '\0')
	{
		buffer2[j] = buffer[i + j];
		j++;
	}
	buffer2[j] = '\0';
	free(buffer);
	return (buffer2);
}

int		get_next_line(const int fd, char **line)
{
	char buff[1];

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	*line = ft_getline(fd);
	if (*line == NULL)
		return (0);
	while (ft_strchr(*line, '\n'))
	{
		*line = ft_pure(*line);
	}
	return (1);
}
