/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:16:22 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/18 11:52:43 by tiacovel         ###   ########.fr       */
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

void	rotate(t_mlx_data *data, int keysym)
{
	if (keysym == XK_q)
		data->view.rot_z += -1;
	else if (keysym == XK_e)
		data->view.rot_z += 1;
	else if (keysym == XK_w)
		data->view.rot_x += -1;
	else if (keysym == XK_s)
		data->view.rot_x += 1;
	else if (keysym == XK_a)
		data->view.rot_y += -1;
	else if (keysym == XK_d)
		data->view.rot_y += 1;
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

void	move(t_mlx_data *data, int keysym)
{
	if (keysym == XK_Up)
		data->origin.y0 += 5;
	else if (keysym == XK_Down)
		data->origin.y0 -= 5;
	else if (keysym == XK_Right)
		data->origin.x0 += 5;
	else if (keysym == XK_Left)
		data->origin.x0 -= 5;
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
}
