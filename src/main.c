/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:33:16 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/18 21:53:42 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_default_view(t_mlx_data *data)
{
	data->view.projection = PARALLEL;
	data->view.rot_x = -45;
	data->view.rot_y = -20;
	data->view.rot_z = 20;
	data->view.zoom = 30;
	data->origin.x0 = 100;
	data->origin.y0 = 100;
	data->view.z_factor = 1;
}

/* int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc != 2)
	{
		ft_printf("ERROR: please check input arguments!");
		return (EXIT_FAILURE);
	}
	data.map = convert_raws_to_matrix(argv[1])
	set_default_view(&data);
	display_window(data);
	return (0);
} */

int	main()
{
	t_mlx_data	data;

	data.map = import_map("/Users/tizianoiacovelli/42berlin/core_curriculum/FdF/test_maps/42.fdf");
	//data.map = convert_raws_to_matrix("/home/tiacovel/core_curriculum/FdF/test_maps/42.fdf");
	set_default_view(&data);
	display_window(&data);
	return (0);
}
