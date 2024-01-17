/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:00:30 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/17 15:07:38 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static float	calculate_pct(t_node_bi current, t_node_bi start, t_node_bi end)
{
	float	dot_product;
	float	length_squared;

	dot_product = (current.x - start.x) * (end.x - start.x) + (current.y - start.y) * (end.y - start.y);
	length_squared = (end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y);
	return (dot_product / length_squared);
}

static int	interpolate_color(int color1, int color2, float t)
{
	t_color	col1;
	t_color	col2;
	t_color	color;
	int		result;

	col1.r = (color1 >> 16) & 0xFF;
	col1.g = (color1 >> 8) & 0xFF;
	col1.b = color1 & 0xFF;
	col2.r = (color2 >> 16) & 0xFF;
	col2.g = (color2 >> 8) & 0xFF;
	col2.b = color2 & 0xFF;
	color.r = (int)((1.0 - t) * col1.r + t * col2.r);
	color.g = (int)((1.0 - t) * col1.g + t * col2.g);
	color.b = (int)((1.0 - t) * col1.b + t * col2.b);
	result = (color.r << 16) | (color.g << 8) | color.b;
	return (result);
}

int	get_color(t_matrix *p1, t_matrix *p2, t_node_bi	cur) 
{
	float	t;
	int		color;
	
	t = calculate_pct(cur, p1->pj_cor, p2->pj_cor);
	if (t < 0.0)
		t = 0.0;
	else if (t > 1.0)
		t = 1.0;
	color = interpolate_color(p1->color, p2->color, t);
	return (color);
}

/* int main() {
	int a = 10;
	int b = 20;

	// Interpolate between a and b with t in the range [0, 1]
	float t = 2;
	int result = lerp(a, b, t);

	printf("Linear interpolation between %d and %d at t=%f is: %d\n", a, b, t, result);

	return 0;
} */
