/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:41:34 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/07 17:45:47 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/libft.h"

t_raw	*read_map(char *file_path)
{
	int		fd;
	char	*line;
	t_raw	*raws;
	t_raw	*raw;

	raws = NULL;
	fd = open(file_path, O_RDWR);
	if (fd == -1)
	{
		ft_printf("ERROR: please check the file name!");
		close(fd);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		raw = new_raw(ft_split(line, ' '));
		if (raw == NULL)
		{
			free(line);
			return (NULL);
		}
		add_raw(&raws, raw);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (raws);
}

// Test the read_map function
#include <stdio.h>

void print_raw_data(char **buffer)
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

void print_raws(t_raw *head)
{
	while (head != NULL)
	{
		print_raw_data(head->data);
		head = head->next;
	}
}

int	main(void)
{
	char	*file_path = "../test_maps/42.fdf";
	t_raw	*map;

	map = read_map(file_path);
	print_raws(map);
	free_raws(map);
	
	return (0);
}