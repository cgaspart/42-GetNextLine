/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:19:43 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/04 15:43:43 by cgaspart         ###   ########.fr       */
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
	ft_putnbr(fd);
	if (fd == -1)
		ft_putstr("Error");
	get_next_line(fd, &line);
	get_next_line(4, &line);
	get_next_line(5, &line);
}
