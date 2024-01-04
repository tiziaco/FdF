/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:28:22 by tiacovel          #+#    #+#             */
/*   Updated: 2023/12/05 11:12:08 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
} */

static int	count_digits(unsigned int nb)
{
	int	digits;

	digits = 0;
	while (nb != 0)
	{
		digits ++;
		nb /= 16;
	}
	return (digits);
}

static void	prt_hexa(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		prt_hexa(nb / 16, format);
		prt_hexa(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchr((nb + '0'));
		else
		{
			if (format == 'x')
				ft_putchr((nb - 10 + 'a'));
			if (format == 'X')
				ft_putchr((nb - 10 + 'A'));
		}
	}
}

int	ft_puthexa(unsigned int nb, const char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	prt_hexa(nb, format);
	return (count_digits(nb));
}

/* #include <stdio.h>
int	main(void)
{
	unsigned int	num;
	int len, len2;

	num = 42;
	len = ft_putexa(num, 'x');
	len2 = printf("\n%x", num);
	printf("\nNum len: %d %d", len, len2);
	return (0);
} */
