/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:41:34 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/19 14:58:11 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/libft.h"

static int	count_columns(t_raw *raws)
{
	int	count;

	count = 0;
	while (raws->data[count] != NULL)
		count++;
	return (count);
}

static void	check_map(t_mlx_data *data, t_raw *raws)
{
	t_raw	*raw;

	raw = raws;
	if (count_rows(raws) <= 1)
	{
		ft_printf("Number of raws insufficient.\n");
		free_raws(raws);
		destroy_window(data);
	}
	while (raw != NULL && raw->next != NULL)
	{
		if (count_columns(raw) != count_columns(raw->next))
		{
			ft_printf("Number of columns incorrect.\n");
			free_raws(raws);
			destroy_window(data);
		}
		raw = raw->next;
	}
	ft_printf("Map check OK\n");
}

static t_raw	*initialize_map(int fd)
{
	char	*line;
	t_raw	*raws;
	t_raw	*raw;

	raws = NULL;
	line = get_next_line(fd);
	while (line)
	{
		raw = new_raw(ft_split(line, ' '));
		if (raw == NULL)
		{
			free(line);
			exit (EXIT_FAILURE);
		}
		add_raw(&raws, raw);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (raws);
}

t_raw	*read_map(t_mlx_data *data, char *file_path)
{
	int		fd;
	t_raw	*raws;

	fd = open(file_path, O_RDWR);
	if (fd == -1)
	{
		ft_printf("ERROR: please check the file name!");
		close(fd);
		destroy_window(data);
	}
	raws = initialize_map(fd);
	check_map(data, raws);
	return (raws);
}

// Test the read_map function
/* #include <stdio.h>

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
	char	*file_path = "test_maps/42.fdf";
	t_raw	*map;

	map = read_map(file_path);
	print_raws(map);
	printf("\nNumber of raws: %d", count_rows(map));
	printf("\nNumber of columns: %d", count_columns(map));
	free_raws(map);
	
	return (0);
} */