/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:33:16 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/02 14:00:24 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
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

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc != 2)
	{
		printf("ERROR: please check input arguments!");
		return (EXIT_FAILURE);
	}
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 
								WIN_WIDTH,
								WIN_HEIGHT,
								"My first window!");
	if (data.mlx_win == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}
	read_map(argv[1]);
	mlx_key_hook(data.mlx_win, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}