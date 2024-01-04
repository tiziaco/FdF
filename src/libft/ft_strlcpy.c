/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:18:52 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/22 13:39:48 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] != '\0' && i < (size - 1)) 
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}

/* # include <stdio.h>
# include <string.h>

int	main(void)
{
	char	src[20] = "Hello";
	char	dest42[20] = " world";
	char	destSTD[20];
	size_t size1;
	size_t size2;

	size1 = ft_strlcpy(dest42, src, 4);
	size2 = strlcpy(destSTD, src, 4);
	printf("42 function: %s | Src size: %d", dest42, size1);
	printf("\nSTD function: %s | Src size: %d", destSTD, size2);
	return (0);
} */
