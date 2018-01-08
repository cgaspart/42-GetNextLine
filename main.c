/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:34:31 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/08 10:57:00 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		free(line);
		i++;
	}
	i = 0;
	while (get_next_line(fd2, &line))
	{
		free(line);
		i++;
	}
	return (0);
}
