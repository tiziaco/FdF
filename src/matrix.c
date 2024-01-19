/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:52:53 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/19 16:46:44 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* void print_matrix(t_matrix *head)
{
	t_matrix *rp;
	t_matrix *dp ;
	
	dp = head; 
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
} */

/* void print_color(t_matrix *head)
{
	t_matrix *rp;
	t_matrix *dp ;
	
	dp = head; 
	while (dp)
	{
		rp = dp;
		while (rp)
		{
			printf("%d\t",rp->color);
			rp = rp->right;
		}
		printf("\n");
		dp = dp->down;
	}
	printf("\n");
} */

static char	**parse_data_point(char *node_data)
{
	char	**data;
	char	**buffer;

	data = (char **)malloc(2 * sizeof(char *));
	if (!data)
		return (NULL);
	if (ft_strchr(node_data, ',') == NULL)
	{
		data[0] = ft_strdup(node_data);
		if (ft_atoi(data[0]) > 0)
			data[1] = ft_strdup(BASE_COLOR_UP);
		else if (ft_atoi(data[0]) < 0)
			data[1] = ft_strdup(BASE_COLOR_DOWN);
		else
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
	node->color = ft_hexstr_int(parsed_data[1]);
	node->right = NULL;
	node->down = NULL;
	free(parsed_data[0]);
	free(parsed_data[1]);
	free(parsed_data);
	return (node);
}

static void	connect_rows(t_matrix **head, int m)
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

static t_matrix	*create_row(char **row_data, int y, t_matrix **mainhead)
{
	t_matrix	*row_head;
	t_matrix	*right_temp;
	t_matrix	*new_ptr;
	int			x;

	row_head = NULL;
	right_temp = row_head;
	x = 0;
	while (row_data[x] != NULL) 
	{
		new_ptr = new_node(x, y, row_data[x]);
		if (!(*mainhead))
			(*mainhead) = new_ptr;
		if (!row_head)
			row_head = new_ptr;
		else
			right_temp->right = new_ptr;
		right_temp = new_ptr;
		x++;
	}
	return (row_head);
}

void	import_map(t_mlx_data *data, char *file_path)
{
	t_matrix	**head;
	t_matrix	*matrix_head;
	t_raw		*current_row;
	t_raw		*raws;
	int			y;

	data->map = NULL;
	raws = read_map(data, file_path);
	head = (t_matrix **)malloc(count_rows(raws) * sizeof(t_matrix *));
	if (!head)
		destroy_window(data);
	y = 0;
	matrix_head = NULL;
	current_row = raws;
	while (current_row != NULL)
	{
		head[y] = create_row(current_row->data, y, &matrix_head);
		y++;
		current_row = current_row->next;
	}
	connect_rows(head, y);
	free_raws(raws);
	free(head);
	data->map = matrix_head;
}
