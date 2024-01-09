/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:39:27 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/09 19:08:26 by tiacovel         ###   ########.fr       */
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
        if (D > 0)
		{
            x = x + xi;
            D = D + (2 * (dx - dy));
        } else
            D = D + 2 * dx;
        color_pixel(data, x, y, 0xffffff);
        y++;
    }
}

void	plot_line(t_mlx_data *data, int x0, int y0, int x1, int y1)
{
    if (abs(y1 - y0) < abs(x1 - x0))
	{
        if (x0 > x1) {
            plot_line_low(data, x1, y1, x0, y0);
        } else {
            plot_line_low(data, x0, y0, x1, y1);
        }
    } else
	{
        if (y0 > y1) {
            plot_line_high(data, x1, y1, x0, y0);
        } else {
            plot_line_high(data, x0, y0, x1, y1);
        }
    }
}

