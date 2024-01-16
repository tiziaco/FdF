/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:39:27 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/15 17:19:40 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	color_pixel(t_mlx_data *data, int x, int y, int color)
{
	int	offset;

	offset = (data->img.line_len * y) + (x * (data->img.bits_per_pixel / 8));	
	*((unsigned int *)(offset + data->img.img_pixels_ptr)) = color;
}

void	color_background(t_mlx_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)	
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			color_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

static void	plot_line_low(t_mlx_data *data, t_node_bi point_a, int dx, int dy, int D)
{
	int	yi;
	int	y;
	int	x;

	x = point_a.x;
	y = point_a.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	while (x <= (point_a.x + abs(dx)))
	{
		if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
			color_pixel(data, x, y, 0xffffff);
		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy - dx));
		} else
			D = D + 2 * dy;
		x++;
	}
}

static void	plot_line_high(t_mlx_data *data, t_node_bi point_a, int dx, int dy, int D)
{
	int	xi;
	int	x;
	int	y;

	x = point_a.x;
	y = point_a.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	while (y <= (point_a.y + abs(dy)))
	{
		if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
			color_pixel(data, x, y, 0xffffff);
		if (D > 0)
		{
			x = x + xi;
			D = D + (2 * (dx - dy));
		} else
			D = D + 2 * dx;
		y++;
	}
}

void	plot_line(t_mlx_data *data, t_node_bi point_a, t_node_bi point_b)
{
	int	dx;
	int	dy;
	int	D;

	dx = point_b.x - point_a.x;
	dy = point_b.y - point_a.y;
	D = (2 * dx) - dy;
	if (abs(point_b.y - point_a.y) < abs(point_b.x - point_a.x))
	{
		if (point_a.x > point_b.x)
			plot_line_low(data, point_a, dx, dy, D);
		else
			plot_line_low(data, point_a, dx, dy, D);
	} else
	{
		if (point_a.y > point_b.y)
			plot_line_high(data, point_a, dx, dy, D);
		else
			plot_line_high(data, point_a, dx, dy, D);
	}
}
