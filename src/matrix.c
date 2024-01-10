/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:52:53 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/10 20:44:19 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

void print_matrix(t_matrix *head)
{
	t_matrix *rp, *dp = head;
 
	while (dp)
	{
		rp = dp;
		while (rp)
		{
			printf("%d",rp->z);
			rp = rp->right;
		}
		printf("\n");
		dp = dp->down;
	}
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
		data[1] = ft_strdup(BASE_COLOR);
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

static t_matrix	*new_node(int x, int y, char *node_data)
{
	t_matrix	*node;
	char		**parsed_data;

	node = (t_matrix *)malloc(sizeof(t_matrix));
	if (!node)
		return (NULL);
	parsed_data = parse_data_point(node_data);
	node->x = x;
	node->y = y;
	node->z = ft_atoi(parsed_data[0]);
	node->color =  ft_hexstr_int(parsed_data[1]);
	node->right = NULL;
	node->down = NULL;
	free(parsed_data[0]);
	free(parsed_data[1]);
	free(parsed_data);
	return (node);
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

t_matrix *convert_raws_to_matrix(t_raw *raws)
{
	t_matrix *matrix_head = NULL;
	t_matrix *row_head = NULL;
	t_raw *current_row;
	char **raw_data;
	int	x;
	int	y;

	y = 0;
	current_row = raws;
	while (current_row != NULL)
	{
		x = 0;
		raw_data = current_row->data;
		while (raw_data[x] != NULL)
		{
			t_matrix *current_node = new_node(x, y, raw_data[x]);
			if (row_head != NULL)
			{
				row_head->right = current_node;
				row_head = row_head->right;
			} else 
			{
				row_head = current_node;
				matrix_head = row_head;
			}
			x++;
		}
		current_row = current_row->next;
		y++;
	}
	connect_rows(&matrix_head, 1);
	printf("\n***TEST***\n");
	print_matrix(matrix_head);
	return (matrix_head);
}
