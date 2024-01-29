/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:33:14 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/29 16:51:55 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
		ft_printf("Error: Invalid hex string\n");
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
			ft_printf("Error: Invalid hex character '%c'\n", *hexstr);
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

t_matrix *get_last_node(t_matrix *head)
{
	t_matrix	*current;

	current = head;
	while (current->right != NULL)
		current = current->right;
	while (current->down != NULL)
		current = current->down;
	return (current);
}

int	calculate_zoom_factor(t_mlx_data *data)
{
	t_matrix	*last;
	int			max;
	int			zoom;

	last = get_last_node(data->map);
	max = last->y;
	if (last->x > last->y)
		max = last->x;
	zoom = WIN_WIDTH / (max + 2);
	if (zoom < 3)
		return (3);
	return (zoom);
}

/* int main() {
	const char *hexstr = "0x000fff";
	int result = hexstr_int(hexstr);

	if (result != -1) {
		printf("Hex: %s, Int: %d\n", hexstr, result);
	}

	return 0;
} */
