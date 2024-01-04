/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:19:22 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/04 17:03:33 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_case(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchr(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), 'X'));
	else if (c == '%')
		return (ft_putchr('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			count += print_case(*(str + 1), args);
			str += 2;
		}
		else
		{
			count += ft_putchr(*str);
			str++;
		}
	}
	va_end(args);
	return (count);
}

/* #include <stdio.h>
#include <limits.h>
int main(void)
{
	int len = 0, len2 = 0;

	ft_printf("Char printed: %d\n\n", len);
	len = ft_printf("Test integer: %i\n",21);
	ft_printf("Char printed: %d\n\n", len);
	len = ft_printf("Test decimal: %d\n",42);
	ft_printf("Char printed: %d\n\n", len);
	len = ft_printf("Test un int: %u\n",4242);
	ft_printf("Char printed: %d\n\n", len);
	len = ft_printf("Test hexa low: %x\n", 0);
	ft_printf("Char printed: %d\n\n", len);
	len = ft_printf("Test hexa up: %X\n",4242);
	ft_printf("Char printed: %d\n\n", len);
	len = ft_printf("Test pct: %%\n");
	ft_printf("Char printed: %d\n\n", len);

	// Test STD printf
	printf("STD function:\n");
	len = printf(" %lx\n", LONG_MIN);
	printf("%d\n", len);

	printf("42 function:\n");
	len2 = ft_printf(" %x\n", LONG_MIN);
	printf("%d\n", len2);
	return (0);
} */

/* #include <stdio.h>
#include <limits.h>
int main(void)
{
	int len, len2;

	// Test STD printf
	printf("STD function:\n");
	len = printf(" %x\n", 0);
	printf("%d\n", len);

	printf("42 function:\n");
	len2 = ft_printf(" %x\n", 0);
	printf("%d\n", len2);
	return (0);
} */