/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:28:22 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/28 18:36:16 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits += 1;
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

void	prt_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchr('-');
		nb = nb * -1;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchr(nb + 48);
}

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
		return (11);
	}
	else
	{
		prt_putnbr(nb);
		return (count_digits(nb));
	}
}

/* #include <stdio.h>
int	main(void)
{
	int	num;
	int len;

	num = -42885;
	len = ft_putnbr(num);
	printf("\n%d", len);
	return (0);
} */
