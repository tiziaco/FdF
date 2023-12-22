/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:33:16 by tiacovel          #+#    #+#             */
/*   Updated: 2023/12/22 12:40:05 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc != 2)
	{
		printf("ERROR: please check input arguments!");
		return (1);
	}
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		printf("ERROR: please check the file name!");
		close(fd);
		return(1);
	}
	while (line)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}