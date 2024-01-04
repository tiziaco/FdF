/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:03:42 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/23 13:22:09 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (is_num(str[i])))
	{
		if (is_num(str[i]))
			result = result * 10 + (str[i] - '0');
		else
			return (result *= sign);
		i++;
	}
	return (result *= sign);
}

/* #include <stdlib.h>
#include <stdio.h>
int main() 
{
	char *test_strings[] = {
		"12345",       // Positive number
		" +-678",        // Negative number
		" +++678",
		"++0",           // Zero
		"  +-987",       // Leading spaces
		"+42",         // Leading plus sign
		"  -123abc",   // Ignore non-numeric characters after digits
		"123abc",      // Stop at non-numeric characters
		"-2147483648", // Minimum signed int value
		"2147483647",  // Maximum signed int value
		"  -++-+ 998",  // Larger than maximum signed int value
		"-9999999999", // Smaller than minimum signed int value
		" ++-+++---1234aa52",
		" aa-+++---1554aa52",
	};

	int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

	for (int i = 0; i < num_tests; i++) 
	{
		printf("String: \"%s\"\nSTD: %d, 42: %d\n", 
				test_strings[i], atoi(test_strings[i]), ft_atoi(test_strings[i]));
	}
	return 0;
}
 */