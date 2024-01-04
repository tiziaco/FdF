/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:43:38 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/24 17:00:29 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;

	if (!dest && !src)
		return (0);
	tmp_src = (void *)src;
	tmp_dest = dest;
	if (tmp_dest > tmp_src && tmp_dest < tmp_src + size)
	{
		tmp_dest += size;
		tmp_src += size;
		while (size--)
			*(--tmp_dest) = *(--tmp_src);
	}
	else
	{
		while (size--)
			*(tmp_dest++) = *(tmp_src++);
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int main ()
{
	char src[50] = "This is a test";
	char *dest = src;
	printf("%s\n", dest);
	// Test standard function
	printf("STD function\n");
	strcpy(dest,"Heloooo!!");
	printf("Before memmove dest = %s\n", dest);
	memmove(dest, src, strlen(src)+1);
	printf("After memmove dest = %s\n", dest);

	// Test 42 function
	printf("42 function\n");
	strcpy(dest,"Heloooo!!");
	printf("Before ft_memmove dest = %s\n", dest);
	ft_memmove(dest, src, strlen(src)+1);
	printf("After ft_memmove dest = %s\n", dest);

	return(0);
} */