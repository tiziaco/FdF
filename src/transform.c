/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:20:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/18 21:54:28 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* void print_matrix_uv(t_matrix *head)
{
	t_matrix	*rp;
	t_matrix	*dp ;
	
	dp = head;
	while (dp)
	{
		rp = dp;
		while (rp)
		{
			printf("%d,%d\t",rp->pj_cor.x, rp->pj_cor.y);
			rp = rp->right;
		}
		printf("\n");
		dp = dp->down;
	}
} */

static void rotate_nodes(t_node_tri *coor, float alpha, float beta, float gamma)
{
	int previous_x;
	int previous_y;

	previous_y = coor->y;
	if (alpha != 0)
	{
		coor->y = previous_y * cos(alpha) + coor->z * sin(alpha);
		coor->z = -previous_y * sin(alpha) + coor->z * cos(alpha);
	}
	previous_x = coor->x;
	if (beta != 0)
	{
		coor->x = previous_x * cos(beta) + coor->z * sin(beta);
		coor->z = -previous_x * sin(beta) + coor->z * cos(beta);
	}
	previous_x = coor->x;
	previous_y = coor->y;
	if (gamma != 0)
	{
		coor->x = previous_x * cos(gamma) - previous_y * sin(gamma);
		coor->y = previous_x * sin(gamma) + previous_y * cos(gamma);
	}
}

static void	iso_projection(t_node_tri *coor)
{
	int previous_x;
	int previous_y;

	previous_x = coor->x;
	previous_y = coor->y;
	coor->x = (previous_x - previous_y) * cos(0.523599);
	coor->y = -coor->z + (previous_x + previous_y) * sin(0.523599);
}

static void	get_projected_coord(t_matrix *matrix, t_view view, t_origin origin)
{
	t_node_tri	new_node;

	new_node.x = matrix->x * view.zoom;
	new_node.y = matrix->y * view.zoom;
	new_node.z = matrix->z * view.zoom * view.z_factor;
	rotate_nodes(&new_node, deg_to_rad(view.rot_x), deg_to_rad(view.rot_y), deg_to_rad(view.rot_z));
	if (view.projection == ISO)
		iso_projection(&new_node);
	matrix->pj_cor.x = new_node.x + origin.x0;
	matrix->pj_cor.y = new_node.y + origin.y0;
}

void	transform_nodes(t_matrix *matrix, t_view view, t_origin origin)
{
	t_matrix	*rp;
	t_matrix	*dp;

	dp = matrix;
	while (dp)
	{
		rp = dp;
		while (rp)
		{
			get_projected_coord(rp, view, origin);
			rp = rp->right;
		}
		dp = dp->down;
	}
	//Fprintf("\n*** Screen coordinates ***\n");
	//print_matrix_uv(matrix);
}
