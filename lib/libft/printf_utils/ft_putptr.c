/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:28:05 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/28 18:48:12 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putexa(unsigned long long nb)
{
	char		hex_digit;
	int			remainder;
	int			temp;
	static int	len;

	if (nb == 0)
	{
		temp = len;
		len = 0;
		return (temp);
	}
	ft_putexa(nb / 16);
	remainder = nb % 16;
	if (remainder < 10)
		hex_digit = '0' + remainder;
	else
		hex_digit = 'a' + remainder - 10;
	write(1, &hex_digit, 1);
	len++;
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	address;
	int					len;

	len = 0;
	if (ptr == NULL)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	len += ft_putstr("0x");
	address = (unsigned long long)ptr;
	len += ft_putexa(address);
	return (len);
}

/* #include <stdio.h>
int main() {
	int value = 200;
	void *ptr = &value;
	int len;

	//printVoidPointer(ptr);
	printf("%p\n", NULL);
	len = ft_putptr(0);
	printf("\n%d", len);

	return 0;
} */