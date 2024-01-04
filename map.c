/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:41:34 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/04 17:15:47 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "include/fdf.h"
#include "include/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	read_map(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDWR);
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
	return(0);
}

// Test the read_map function
int	main(void)
{
	char *file_path = "test_maps/42.fdf";

	read_map(file_path);
	return (0);
}