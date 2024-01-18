/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:50:49 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/18 12:07:32 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	display_window(t_mlx_data data)
{
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit (MLX_ERROR);
	data.mlx_win = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr,
												&data.img.bits_per_pixel,
												&data.img.line_len,
												&data.img.endian);
	if (data.mlx_win == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		free_matrix(data.map);
		exit (MLX_ERROR);
	}
	transform_nodes(data.map, data.view, data.origin);
	draw_grid(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, 
							data.img.img_ptr, 200, 0);
	print_instruction(&data);
	mlx_key_hook(data.mlx_win, handle_keyboard_input, &data);
	mlx_mouse_hook(data.mlx_win, handle_mouse_input, &data);
	//mlx_hook(data.mlx_win, 2, 0, handle_keyboard_input, &data);
	mlx_hook(data.mlx_win, 17, 0, handle_close_button, &data);
	mlx_loop(data.mlx_ptr);
}

void	destroy_window(t_mlx_data *data)
{
	ft_printf("Quitting the program... \n\n");
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_matrix(data->map);
	exit (EXIT_SUCCESS);
}

void	print_instruction(t_mlx_data *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->mlx_win;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "FdF - Commands");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move:");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "X-Axis - Lft/Right arrows");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "Y-Axis - Up/Down arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "X-Axis - W/S");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "Y-Axis - A/D");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "Z-Axis - Q/E");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "Parallel: P Key");
}
