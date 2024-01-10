/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:22:29 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/10 17:34:36 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_matrix	*new_node(int x, int y, char **node_data)
{
	t_matrix	*node;

	node = (t_matrix *)malloc(sizeof(t_matrix));
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	node->z = node_data[0];
	node->color = node_data[1];
	node->right = NULL;
	node->down = NULL;
	return (node);
}

void	add_node_right(t_matrix **raws, t_matrix *new_node)
{
	t_matrix	*last;

	if (!new_node)
		return ;
	if (!*raws)
	{
		*raws = new_node;
		return ;
	}
	last = *raws;
	while (last && last->right)
		last = last->right;
	last->right = new_node;
}

static void	free_split(char **data)
{
	int	i;

	i = 0;
	while (data[i] != NULL)
	{
		free(data[i]);
		i++;
	}
	free(data);
}


char	**parse_data_point(char *node_data)
{
	char	**data;
	char	**buffer;

	data = (char **)malloc(2 * sizeof(char *));
    if (!data)
        return NULL;
	if(ft_strchr(node_data, ',') == NULL)
	{
		data[0] = ft_strdup(node_data);
		data[1] = BASE_COLOR;
	}
	else
	{
		buffer = ft_split(node_data, ',');
		data[0] = ft_strdup(buffer[0]);
		data[1] = ft_strdup(buffer[1]);
		free_split(buffer);
	}
	return (data);
}

t_matrix	*create_row(int i, char **line, t_matrix **mainhead)
{
	t_matrix	*row_head;
	t_matrix	*right_temp;
	t_matrix	*new_ptr;
	char		**node_data;
	int			n;

	row_head = NULL;
	n = 0;
	while (line[n] != NULL)
	{
		node_data = parse_point_data(line[n]);
		new_ptr = new_node(i, n, node_data);
		if (!(*mainhead))
			(*mainhead) = new_ptr;
		if (!row_head)
			row_head = new_ptr;
		else
			right_temp->right = new_ptr;
		right_temp = new_ptr;
		n++;
	}
	return (row_head);
}

static void	connect_rows(t_matrix *head[], int m)
{
	t_matrix	*temp1;
	t_matrix	*temp2;
	int			i;

	i = 0;
	while (i < m - 1) 
	{
		temp1 = head[i];
		temp2 = head[i + 1];
		while (temp1 && temp2)
		{
			temp1->down = temp2;
			temp1 = temp1->right;
			temp2 = temp2->right;
		}
		i++;
	}
}

t_matrix	*construct_matrix(t_raw **raws)
{
	t_matrix	*mainhead;
	t_matrix	**head;
	int			i;

	mainhead = NULL;
	head = (t_matrix **)malloc(m * sizeof(t_matrix *));
	i = 0;
	while (i < m)
	{
		head[i] = create_row(n, &mainhead);
		i++;
	}
	connect_rows(head, m);
	return (mainhead);
}

void	free_matrix(t_matrix *matrix)
{
	t_matrix	*row;
	t_matrix	*current_row;
	t_matrix	*current;
	t_matrix	*next;

	row = matrix;
	while (row != NULL)
	{
		current_row = row;
		row = row->down;
		current = current_row;
		while (current != NULL) 
		{
			next = current->right;
			free(current);
			current = next;
		}
	}
}

// Test the above function
/* #include <stdio.h>

void display(t_matrix *head)
{
	t_matrix *rp, *dp = head;
 
	while (dp)
	{
		rp = dp;
		while (rp)
		{
			printf("%d ",rp->z);
			rp = rp->right;
		}
		printf("\n");
		dp = dp->down;
	}
}

int main()
{
	int m = 3;
	int n = 3;
    int **mat;

	mat = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
    }

    // Initialize matrix data
    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
    mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;

	t_matrix *head = construct_matrix(mat, m, n);
	display(head);
	free_matrix(head);
	// Freeing the memory allocated for the matrix data
    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);

	return 0;
} */