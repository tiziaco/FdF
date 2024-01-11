/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:38:11 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/11 13:22:58 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_raw	*new_raw(char **data)
{
	t_raw	*node;

	node = (t_raw *)malloc(sizeof(t_raw));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	add_raw(t_raw **raws, t_raw *new_node)
{
	t_raw	*last;

	if (!new_node)
		return ;
	if (!*raws)
	{
		*raws = new_node;
		return ;
	}
	last = *raws;
	while (last && last->next)
		last = last->next;
	last->next = new_node;
}

static void	free_raw_data(char **data)
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

void	free_raws(t_raw *raws)
{
	t_raw	*temp;

	while (raws != NULL)
	{
		temp = raws;
		raws = raws->next;
		free_raw_data(temp->data);
		free(temp);
	}
	free(raws);
}

/* int	count_rows(t_raw *lst)
{
	int		size;
	t_raw	*ptr;

	size = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
} */