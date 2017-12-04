/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:27:38 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/01 03:32:48 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_nwlinecheck(char		*str)
{
	int		i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_str	*data;

	if (fd < 0)
		return (-1);
	data = (t_str*)malloc(sizeof(t_str));
	while (!ft_nwlinecheck(data->str))
	{
		data->ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';

	}
}
