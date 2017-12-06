/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:19:43 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/06 12:11:57 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int		main()
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open("test.file", O_RDONLY);
	get_next_line(fd, &line);
	ft_putstr(line);
	free(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	free(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	free(line);
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr(line);
	free(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	free(line);
}
