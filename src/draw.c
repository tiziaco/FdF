/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:39:27 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/15 14:21:29 by tiacovel         ###   ########.fr       */
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

static void	plot_line_low(t_mlx_data *data, int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	int D = (2 * dy) - dx;
	int y = y0;
	int x = x0;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	while (x <= x1)
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

static void	plot_line_high(t_mlx_data *data, int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	int D = (2 * dx) - dy;
	int x = x0;
	int y = y0;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	while (y <= y1)
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
	if (abs(point_b.y - point_a.y) < abs(point_b.x - point_a.x))
	{
		if (point_a.x > point_b.x) {
			plot_line_low(data, point_b.x, point_b.y, point_a.x, point_a.y);
		} else {
			plot_line_low(data, point_a.x, point_a.y, point_b.x, point_b.y);
		}
	} else
	{
		if (point_a.y > point_b.y) {
			plot_line_high(data, point_b.x, point_b.y, point_a.x, point_a.y);
		} else {
			plot_line_high(data, point_a.x, point_a.y, point_b.x, point_b.y);
		}
	}
}

/* void draw_grid(t_mlx_data *data)
{
	t_matrix *rp;
	t_matrix *rp1;
	t_matrix *dp;
	t_matrix *dp1;
	
	color_background(data, 0x000000);
	dp = data->map; 
	while (dp)
	{
		rp = dp;
		while (rp)
		{
			rp1 = rp->right;
			dp1 = rp->down;
			if (rp1)
				plot_line(data, rp->proj_coordinates,  rp1->proj_coordinates);
			if (dp1)
				plot_line(data, rp->proj_coordinates, dp1->proj_coordinates);
			rp = rp1;
		}
		dp = dp->down;
	}
} */
