/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:33:16 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/19 17:20:05 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_mlx_data	*init_mlx(void)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	if (data == NULL)
		exit (MLX_ERROR);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free(data);
		exit (MLX_ERROR);
	}
	data->mlx_win = NULL;
	data->img.img_ptr = NULL;
	data->img.img_pixels_ptr = NULL;
	data->map = NULL;
	return (data);
}

void	init_window(t_mlx_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (data->mlx_win == NULL)
		destroy_window(data);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	if (data->img.img_ptr == NULL)
		destroy_window(data);
	data->img.img_pixels_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
	if (data->img.img_pixels_ptr == NULL)
		destroy_window(data);
	mlx_key_hook(data->mlx_win, handle_keyboard_input, data);
	mlx_hook(data->mlx_win, 17, 0, handle_close_button, data);
	mlx_mouse_hook(data->mlx_win, handle_mouse_input, data);
}

void	init_camera(t_mlx_data *data)
{
	data->view.projection = PARALLEL;
	data->view.rot_x = -45;
	data->view.rot_y = -20;
	data->view.rot_z = 20;
	data->view.zoom = 30;
	data->origin.x0 = 100;
	data->origin.y0 = 100;
	data->view.z_factor = 1;
	print_instruction(data);
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, 
		data->img.img_ptr, 200, 0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	*data;

	if (argc != 2)
	{
		ft_printf("ERROR: please check input arguments!");
		return (EXIT_FAILURE);
	}
	data = init_mlx();
	init_window(data);
	import_map(data, argv[1]);
	init_camera(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

/* int	main(void)
{
	t_mlx_data	*data;
	char *path;

	path = "/Users/tizianoiacovelli/42berlin/core_curriculum/FdF/test_maps/42.fdf"

	data = init_mlx();
	init_window(data);
	//import_map(data, path);
	import_map(data, "/home/tiacovel/core_curriculum/FdF/test_maps/elem-fract.fdf");
	init_camera(data);
	mlx_loop(data->mlx_ptr);
	return (0);
} */
