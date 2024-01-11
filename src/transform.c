/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:20:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/11 16:42:06 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void print_matrix_uv(t_matrix *head)
{
	t_matrix *rp;
	t_matrix *dp ;
	
	dp = head; 
	while (dp)
	{
		rp = dp;
		while (rp)
		{
			printf("%d,%d\t",rp->u, rp->v);
			rp = rp->right;
		}
		printf("\n");
		dp = dp->down;
	}
}

void calculate_screen_coordinates(t_matrix *node, int distance)
{
    node->u = (int)((node->x - node->y) * distance / sqrt(2.0));
    node->v = (int)(((node->x + node->y - 2 * node->z) * distance) / sqrt(6.0));
}

void	transform_nodes(t_matrix *matrix)
{
	t_matrix	*rp;
	t_matrix	*dp;

	dp = matrix;
	while (dp)
	{
		rp = dp;
		while (rp)
		{
			calculate_screen_coordinates(rp, 50);
			rp = rp->right;
		}
		dp = dp->down;
	}
	print_matrix_uv(matrix);
}