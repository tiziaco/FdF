/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:20:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/12 11:40:34 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

typedef struct {
    float x, y, z;
} t_node_tri;

typedef struct {
    int x, y;
} t_node_bi;

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

/* void calculate_screen_coordinates(t_matrix *node, int distance)
{
    node->u = (int)((node->x - node->y) * distance / sqrt(2.0));
    node->v = (int)(((node->x + node->y - 2 * node->z) * distance) / sqrt(6.0));
} */

t_node_tri scale_node(t_matrix *node, float scale)
{
	t_node_tri	result;

    result.x = node->x * scale;
    result.y = node->y * scale;
    result.z = node->z * scale;
	return (result);
}

t_node_tri translate_node(t_matrix *node, int translateX, int translateY, int translateZ)
{
	t_node_tri	result;

    result.x += translateX;
    result.y += translateY;
    result.z += translateZ;
	(void)node;
	return (result);
}

t_node_tri rotate_nodeX(t_matrix *node, float angle)
{
	t_node_tri	result;

    result.y = node->y * cos(angle) - node->z * sin(angle);
    result.z = node->y * sin(angle) + node->z * cos(angle);
	(void)node;
	return (result);
}

// Function to rotate a node around the y-axis
t_node_tri rotate_nodeY(t_matrix *node, float angle)
{
	t_node_tri	result;

    result.x = node->x * cos(angle) + node->z * sin(angle);
    result.z = -node->x * sin(angle) + node->z * cos(angle);
	(void)node;
	return (result);

}

// Function to rotate a node around the z-axis
t_node_tri rotate_nodeZ(t_matrix *node, float angle)
{
	t_node_tri	result;

    result.x = node->x * cos(angle) - node->y * sin(angle);
    result.y = node->x * sin(angle) + node->y * cos(angle);
	(void)node;
	return (result);
}

void calculate_screen_coordinates(t_matrix *node)
{
	//t_node_bi	screen_coordinates;
	t_node_tri	transformed_coordinates;
	float		isometricAngle = M_PI / 6.0;  // 30 degrees in radians

	transformed_coordinates = scale_node(node, 50);

    node->u = transformed_coordinates.x - transformed_coordinates.z * cos(isometricAngle);
    node->v = transformed_coordinates.y - transformed_coordinates.z * sin(isometricAngle);
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
			calculate_screen_coordinates(rp);
			rp = rp->right;
		}
		dp = dp->down;
	}
	print_matrix_uv(matrix);
}