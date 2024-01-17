/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:39:27 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/17 15:32:07 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	color_pixel(t_mlx_data *data, int x, int y, int color)
{
	int	offset;

	if ((x < IMG_WIDTH && y < IMG_HEIGHT) && (x > 0 && y > 0))
	{
		offset = (data->img.line_len * y) + (x * (data->img.bits_per_pixel / 8));	
		*((unsigned int *)(offset + data->img.img_pixels_ptr)) = color;
	}
}

void	color_background(t_mlx_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < IMG_HEIGHT)	
	{
		x = 0;
		while (x < IMG_WIDTH)
		{
			color_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

static t_node_bi	get_delta(t_node_bi p1, t_node_bi p2)
{
	t_node_bi	delta;
	delta.x = abs(p2.x - p1.x);
	delta.y = -abs(p2.y - p1.y);
	return (delta);
}

static t_node_bi	get_direction(t_node_bi p1, t_node_bi p2)
{
	t_node_bi	dir;
	if (p1.x < p2.x)
		dir.x = 1;
	else
		dir.x = -1;
	if (p1.y < p2.y)
		dir.y = 1;
	else
		dir.y = -1;
	return (dir);
}

void plot_line(t_mlx_data *data, t_matrix *p1, t_matrix *p2)
{
	t_node_bi	delta;
	t_node_bi	dir;
	t_node_bi	cur;
	int			err;
	int			e2;

	cur = p1->pj_cor;
	delta = get_delta(p1->pj_cor, p2->pj_cor);
	dir = get_direction(p1->pj_cor, p2->pj_cor);
	err = delta.x + delta.y;
	while (!(cur.x == p2->pj_cor.x && cur.y == p2->pj_cor.y))
	{
		color_pixel(data, cur.x, cur.y, get_color(p1, p2, cur));
		e2 = 2 * err;
		if (e2 >= delta.y)
		{
			err += delta.y;
			cur.x += dir.x;
		}
		if (e2 <= delta.x)
		{
			err += delta.x;
			cur.y += dir.y;
		}
	}
}
