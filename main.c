/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:19:43 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/30 23:10:00 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int		main()
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(test.file, O_RDONLY);
	while (i < 4)
	{
		get_next_line(fd, &line);
		ft_putstr(line);
		i++;
	}
}
