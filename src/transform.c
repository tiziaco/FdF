/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:20:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/15 18:48:15 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void print_matrix_uv(t_matrix *head)
{
	t_matrix	*rp;
	t_matrix	*dp ;
	
	dp = head;
	while (dp)
	{
		rp = dp;
		while (rp)
		{
			printf("%d,%d\t",rp->proj_coordinates.x, rp->proj_coordinates.y);
			rp = rp->right;
		}
		printf("\n");
		dp = dp->down;
	}
}

typedef struct {
	float **m;
} t_tr_matrix;

t_tr_matrix allocate_tr_matrix()
{
	t_tr_matrix	matrix;
	int			i;

	matrix.m = (float **)malloc(3 * sizeof(float *));
	if (matrix.m == NULL) {
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < 3) {
		matrix.m[i] = (float *)malloc(3 * sizeof(float));
		if (matrix.m[i] == NULL) {
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return matrix;
}

static float	deg_to_rad(float degrees)
{
	return (degrees * (M_PI / 180.0));
}

void free_tr_matrix(t_tr_matrix matrix)
{
    int i = 0;

    while (i < 3)
	{
        free(matrix.m[i]);
        i++;
    }
    free(matrix.m);
}

static t_tr_matrix	get_perspective_matrix(float pitch, float yaw, float roll)
{
	t_tr_matrix	matrix;

	matrix = allocate_tr_matrix();
	pitch = deg_to_rad(pitch);
	yaw = deg_to_rad(yaw);
	roll = deg_to_rad(roll);
	matrix.m[0][0] = cos(yaw) * cos(roll) + sin(pitch) * sin(yaw) * sin(roll);
	matrix.m[0][1] = -cos(pitch) * sin(roll);
	matrix.m[0][2] = sin(yaw) * cos(roll) - sin(pitch) * cos(yaw) * sin(roll);
	matrix.m[1][0] = cos(yaw) * sin(roll) - sin(pitch) * sin(yaw) * cos(roll);
	matrix.m[1][1] = cos(pitch) * cos(roll);
	matrix.m[1][2] = sin(yaw) * sin(roll) + sin(pitch) * cos(yaw) * cos(roll);
	matrix.m[2][0] = cos(pitch) * sin(yaw);
	matrix.m[2][1] = sin(pitch);
	matrix.m[2][2] = cos(pitch) * cos(yaw);
	return (matrix);
}

static void	get_projected_coord(t_matrix *matrix, t_view view, t_origin origin)
{
	t_tr_matrix	transformation_matrix;
	t_node_tri	new_node;

	transformation_matrix = get_perspective_matrix(view.rot_x, view.rot_y, view.rot_z);
	new_node.x = matrix->x * view.zoom;
	new_node.y = matrix->y * view.zoom;
	new_node.z = matrix->z * view.zoom * 0.5;
	matrix->proj_coordinates.x = new_node.x * transformation_matrix.m[0][0] + new_node.y * transformation_matrix.m[0][1] + new_node.z * transformation_matrix.m[0][2];
	matrix->proj_coordinates.y = new_node.x * transformation_matrix.m[1][0] + new_node.y * transformation_matrix.m[1][1] + new_node.z * transformation_matrix.m[1][2];
	matrix->proj_coordinates.x += origin.x0;
	matrix->proj_coordinates.y += origin.y0;
	free_tr_matrix(transformation_matrix);
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
	printf("\n*** Screen coordinates ***\n");
	print_matrix_uv(matrix);
}
