/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:35:37 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/23 13:29:06 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while ((char)c != *str)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*string  = "bonjour";
	char	c = 'o';

	printf("42 function: %s\n", ft_strchr(string, c));
	printf("STD function: %s\n", strchr(string, c));
	return (0);
} */
