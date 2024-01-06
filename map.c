/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:41:34 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/06 12:19:14 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "include/libft.h"

void	free_buffer(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

int	read_map(char *file)
{
	int		fd;
	char	*line;
	char	**buffer;
	int		i;

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
		{
			buffer = ft_split(line, ' ');
			print_buffer(buffer);
			free_buffer(buffer);
		}
		free(line);
	}
	close(fd);
	return(0);
}

// Test the read_map function
#include <stdio.h>

void print_buffer(char **buffer)
{
	int	i;

	i = 0;
	if (buffer != NULL)
    {
        while (buffer[i] != NULL)
        {
            printf("%s", buffer[i]);
			i++;
        }
		printf("\n");
	}
}

int	main(void)
{
	char *file_path = "test_maps/42.fdf";

	read_map(file_path);
	return (0);
}