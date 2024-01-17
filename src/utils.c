/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:33:14 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/17 16:01:24 by tiacovel         ###   ########.fr       */
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

int ft_hexstr_int(const char *hexstr)
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

/* int main() {
	const char *hexstr = "0x000fff";
	int result = hexstr_int(hexstr);

	if (result != -1) {
		printf("Hex: %s, Int: %d\n", hexstr, result);
	}

	return 0;
} */