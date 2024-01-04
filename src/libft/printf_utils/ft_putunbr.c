/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:28:22 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/28 18:53:25 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 10;
	}
	return (digits);
}

void	prt_putunbr(unsigned int nb)
{
	if (nb > 9)
	{
		prt_putunbr(nb / 10);
		prt_putunbr(nb % 10);
	}
	else
		ft_putchr(nb + 48);
}

int	ft_putunbr(unsigned int nb)
{
	prt_putunbr(nb);
	return (count_digits(nb));
}

/* #include <stdio.h>
int	main(void)
{
	unsigned int	num;
	int len;

	num = 42;
	len = ft_putunbr(-1);
	printf("\nSTD res: %u", -1);
	printf("\nNum len: %d", len);
	return (0);
} */
