/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:27:38 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/04 16:20:41 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_str	*ft_getlst(const int fd, t_str *data)
{
	t_str	*ptr;

	if (!data)
	{
		data = (t_str*)malloc(sizeof(t_str));
		data->content = NULL;
		data->fd = 0;
		data->next = NULL;
	}
	ptr = data;
	while (ptr->next && ptr->fd != fd)
	{
		ft_putnbr(ptr->fd);
		ptr = ptr->next;
	}
	if (ptr->fd == 0)
		ptr->fd = fd;
	if (ptr->fd != fd)
	{
		ptr->next = ptr;
		ptr->fd = fd;
	}
	return (ptr);
}

int				get_next_line(const int fd, char **line)
{
	static t_str	*data;
	t_str			*ptr;
	char			*buff;

	buff = malloc(sizeof(char) * BUFF_SIZE);
	if (line == NULL)
		return (-1);
//	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
//		return (-1);
	ptr = ft_getlst(fd, data);
	return (0);
}
