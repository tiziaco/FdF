/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:16:22 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/19 16:38:25 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

void	zoom(t_mlx_data *data, int keysym)
{
	if (keysym == XK_1)
		data->view.zoom -= 2;
	else if (keysym == XK_2)
		data->view.zoom += 2;
	if (data->view.zoom > 100)
		data->view.zoom = 100;
	else if (data->view.zoom < 2)
		data->view.zoom = 2;
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
}

void	move(t_mlx_data *data, int keysym)
{
	if (keysym == XK_Up)
		data->origin.y0 -= 5;
	else if (keysym == XK_Down)
		data->origin.y0 += 5;
	else if (keysym == XK_Right)
		data->origin.x0 += 5;
	else if (keysym == XK_Left)
		data->origin.x0 -= 5;
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
}

void	z_scale(t_mlx_data *data, int keysym)
{
	if (keysym == XK_l)
		data->view.z_factor -= 0.1;
	else if (keysym == XK_h)
		data->view.z_factor += 0.1;
	if (data->view.z_factor < 0.1)
		data->view.z_factor = 0.1;
	else if (data->view.z_factor > 10)
		data->view.z_factor = 10;
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
}

void	change_projection(t_mlx_data *data, int keysym)
{
	data->view.rot_x = 0;
	data->view.rot_y = 0;
	data->view.rot_z = 0;
	if (keysym == XK_i)
		data->view.projection = ISO;
	else if (keysym == XK_p)
		data->view.projection = PARALLEL;
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
}
