/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:22:29 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/10 12:38:18 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_matrix	*new_node()
{
	t_matrix	*node;

	node = (t_matrix *)malloc(sizeof(t_matrix));
	if (!node)
		return (NULL);
	node->z = 0;
	node->color = ft_strdup("#ffffff");
	node->right = NULL;
	node->down = NULL;
	return (node);
}

static t_matrix	*create_row(int n, t_matrix **mainhead)
{
	t_matrix	*row_head;
	t_matrix	*right_temp;
	t_matrix	*new_ptr;
	int			j;

	row_head = NULL;
	j = 0;
	while (j < n)
	{
		new_ptr = new_node();
		if (!(*mainhead))
			(*mainhead) = new_ptr;
		if (!row_head)
			row_head = new_ptr;
		else
			right_temp->right = new_ptr;
		right_temp = new_ptr;
		j++;
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

t_matrix	*construct_matrix(int m, int n)
{
	t_matrix	*mainhead;
	t_matrix	*head[m];
	int			i;

	mainhead = NULL;
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