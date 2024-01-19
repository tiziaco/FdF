/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:33:14 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/19 16:33:56 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
//#include <stdio.h>

static int	char_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (10 + (c - 'a'));
	else if (c >= 'A' && c <= 'F')
		return (10 + (c - 'A'));
	else
		return (-1);
}

int	ft_hexstr_int(const char *hexstr)
{
	int	digit_value;
	int	result;

	if (hexstr == NULL || hexstr[0] == '\0')
	{
		printf("Error: Invalid hex string\n");
		return (-1);
	}
	if (hexstr[0] == '0' && (hexstr[1] == 'x' || hexstr[1] == 'X'))
		hexstr += 2;
	result = 0;
	while (*hexstr != '\0' && *hexstr != '\n')
	{
		digit_value = char_int(*hexstr);
		if (digit_value == -1)
		{
			printf("Error: Invalid hex character '%c'\n", *hexstr);
			return (-1);
		}
		result = (result << 4) | digit_value;
		hexstr++;
	}
	return (result);
}

float	deg_to_rad(float degrees)
{
	return (degrees * (M_PI / 180.0));
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

/* int main() {
	const char *hexstr = "0x000fff";
	int result = hexstr_int(hexstr);

	if (result != -1) {
		printf("Hex: %s, Int: %d\n", hexstr, result);
	}

	return 0;
} */