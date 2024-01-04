/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:03:42 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/24 17:01:12 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert_number(char *s, unsigned int number, int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}

static int	number_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				len;
	unsigned int	number;

	len = number_length(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s))
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		s[0] = '-';
	}
	else
		number = n;
	s = convert_number(s, number, len);
	return (s);
}

/* #include <stdlib.h>
#include <stdio.h>
int main(void) 
{
	int test_numbers[] = {
		12345,
		+678,
		-679,
		0,
		1,
		-3
	};

	int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);
	// printf("%d", num_tests);
	
	for (int i = 0; i < num_tests; i++) 
	{
		printf("Number: %d - str: %s\n", 
				test_numbers[i], ft_itoa(test_numbers[i]));
		// printf("Digits: %d\n", count_digits(test_numbers[i]));
	}

	return 0;
} */
