/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:35:37 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/23 13:29:31 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i--;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*string  = "bonjour";
	char	c = 'b';

	printf("42 function: %s\n", ft_strrchr(string, c));
	printf("STD function: %s", strrchr(string, c));
	return (0);
} */
