/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:41:34 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/09 15:13:02 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/libft.h"

int	count_columns(t_raw *raws)
{
    int	count;

    count = 0;
    while (raws->data[count] != NULL)
        count++;
    return (count);
}

void	check_map(t_raw *raws)
{
	t_raw	*raw;

	raw = raws;
	if (count_rows(raws) <= 1)
	{
		ft_printf("Number of raws insufficient.\n");
		free_raws(raws);
		exit (EXIT_FAILURE);
	}
	while (raw != NULL && raw->next != NULL)
	{
		//ft_printf("ook");
		if (count_columns(raw) != count_columns(raw->next))
		{
			ft_printf("Number of columns incorrect.\n");
			free_raws(raws);
			exit (EXIT_FAILURE);
		}
		raw = raw->next;
	}
	ft_printf("Map check OK");
}

t_raw	*initialize_map(int fd)
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

/* t_matrix	parse_map(t_raw *raws)
{
	t_raw		*raw;
	t_matrix	*parsed_map;
	int			i;

	raw = raws;
	parsed_map = construct_matrix(count_rows(raws), count_columns(raws));
	i = 0;
	while (raw != NULL)
	{
		while (raw->data[i] != NULL)
			if(ft_strchr(raw->data[i], ',') == NULL)
			{

			}
			i++;
		raw = raw->next;
	}
} */

t_raw	*read_map(char *file_path)
{
	int		fd;
	t_raw	*raws;

	fd = open(file_path, O_RDWR);
	if (fd == -1)
	{
		ft_printf("ERROR: please check the file name!");
		close(fd);
		exit (EXIT_FAILURE);
	}
	raws = initialize_map(fd);
	check_map(raws);
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