/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:19:32 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/29 15:20:07 by tiacovel         ###   ########.fr       */
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

void	free_split(char **data)
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
