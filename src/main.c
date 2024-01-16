/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:33:16 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/15 18:50:43 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	print_instruction(t_mlx_data data)
{
	int		x;
	int		y;
	int		i;
	char	*text;
	char	**buffer;

	x = 10;
	y = 20;
	// Assuming you want to display the text "Hello, MiniLibX!"
	text = "FdF Instructions:$   Left/Right arrow: move X\
	$   Up/Down arrow: move Y$   A/D: rotate around X$   W/S: rotate around Y\
	X$   Q/E: rotate around Z";
	buffer = ft_split(text, '$');
	i = 0;
	while (buffer[i] != NULL)
	{
		mlx_string_put(data.mlx_ptr, data.mlx_win, x, y, 0xFF0000, buffer[i]);
		y += 20;
		i++;
	}
	free_split(buffer);
}

void	display_window(t_mlx_data data)
{
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit (MLX_ERROR);
	data.mlx_win = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
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
							data.img.img_ptr, 150, 0);
	print_instruction(data);
	mlx_key_hook(data.mlx_win, handle_keyboard_input, &data);
	mlx_mouse_hook(data.mlx_win, handle_mouse_input, &data);
	//mlx_hook(data.mlx_win, 2, 0, handle_keyboard_input, &data);
	mlx_hook(data.mlx_win, 17, 0, handle_close_button, &data);
	mlx_loop(data.mlx_ptr);
}

/* int	main(int argc, char **argv)
{
	t_mlx_data	data;
	t_matrix	*map;

	if (argc != 2)
	{
		ft_printf("ERROR: please check input arguments!");
		return (EXIT_FAILURE);
	}
	data.map = read_map(argv[1]);
	map = convert_raws_to_matrix(data.map);
	free_matrix(map);
	display_window(data);
	(void)map;
	return (0);
} */

int	main()
{
	t_mlx_data	data;

	data.map = convert_raws_to_matrix("/Users/tizianoiacovelli/42berlin/core_curriculum/FdF/test_maps/elem-col.fdf");
	data.view.rot_x = -45;
	data.view.rot_y = -20;
	data.view.rot_z = 20;
	data.view.zoom = 50;
	data.origin.x0 = 300;
	data.origin.y0 = 300;
	display_window(data);
	return (0);
}
