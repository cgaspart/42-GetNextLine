/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:51:42 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/11 07:24:16 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		my_lstadd(t_data **alst, t_data *new)
{
	new->next = (*alst);
	(*alst) = new;
}

static t_data	*ft_getlst(const int fd, t_data **data)
{
	t_data	*ptrdata;
	t_data	*tmp;

	ptrdata = *data;
	while (ptrdata)
	{
		if ((int)ptrdata->content_size == fd)
			return (ptrdata);
		ptrdata = ptrdata->next;
	}
	tmp = (t_data*)malloc(sizeof(t_data));
	tmp->content = NULL;
	tmp->content_size = fd;
	tmp->here = 0;
	ptrdata = tmp;
	my_lstadd(data, ptrdata);
	return (ptrdata);
}

static char		*ft_aloc(char *line)
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

static char		*ft_endl(t_data *glist)
{
	int		i;
	char	*buffer;
	char	*res;

	i = 0;
	buffer = ft_strdup((char*)glist->content);
	while (buffer[glist->here + i] != '\n' && buffer[glist->here + i] != '\0')
		i++;
	res = malloc(sizeof(char) * i + 1);
	i = 0;
	while (buffer[glist->here + i] != '\n' && buffer[glist->here + i] != '\0')
	{
		res[i] = buffer[glist->here + i];
		i++;
	}
	glist->here = glist->here + i + 1;
	res[i] = '\0';
	free(buffer);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static t_data	*data;
	t_data			*glist;
	char			*buff;
	int				len;

	buff = malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	glist = ft_getlst(fd, &data);
	while ((len = read(fd, buff, BUFF_SIZE)))
	{
		buff[len] = '\0';
		glist->content = ft_aloc((char*)glist->content);
		glist->content = ft_strjoin((char*)glist->content, buff, 1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	if (glist->here >= (int)ft_strlen(glist->content))
		return (0);
	*line = ft_endl(glist);
	return (1);
}
