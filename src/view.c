/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:16:22 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/17 13:13:57 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void draw_grid(t_mlx_data *data)
{
	t_matrix *rp;
	t_matrix *rp1;
	t_matrix *dp;
	t_matrix *dp1;

	color_background(data, BACKGROUND_COLOR);
	dp = data->map; 
	while (dp)
	{
		rp = dp;
		while (rp)
		{
			rp1 = rp->right;
			dp1 = rp->down;
			if (rp1)
				plot_line(data, rp, rp1);
			if (dp1)
				plot_line(data, rp, dp1);
			rp = rp1;
		}
		dp = dp->down;
	}
}

void	rotate(t_mlx_data *data, int rot_x, int rot_y, int rot_z)
{
	if (rot_x != 0)
		data->view.rot_x += 2 * rot_x;
	else if (rot_y != 0)
		data->view.rot_y += 2 * rot_y;
	else if (rot_z != 0)
		data->view.rot_z += 2 * rot_z;
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
}
void	zoom(t_mlx_data *data, int direction)
{
	int	zoom_factor;

	zoom_factor = data->view.zoom + 2 * direction;
	if (zoom_factor > 100)
		data->view.zoom = 100;
	else if (zoom_factor < 5)
		data->view.zoom = 5;
	else
		data->view.zoom = zoom_factor;
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
}

void	move(t_mlx_data *data, int tr_x, int tr_y)
{
	if (tr_x != 0)
		data->origin.x0 += 5 * tr_x;
	else if (tr_y != 0)
		data->origin.y0 += 5 * tr_y;
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
}

void	destroy_window(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_matrix(data->map);
	exit (EXIT_SUCCESS);
}
