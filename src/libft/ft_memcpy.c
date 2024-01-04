/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:43:38 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/24 17:00:25 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;
	size_t			i;

	if (!dest && !src)
		return (0);
	i = 0;
	tmp_src = (void *)src;
	tmp_dest = dest;
	while (i < n)
	{
		*tmp_dest = *tmp_src;
		tmp_src++;
		tmp_dest++;
		i++;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int main ()
{
	const char src[50] = "This is a test";
	char dest[50];

	// Test standard function
	printf("STD function\n");
	strcpy(dest,"Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);

	// Test 42 function
	printf("42 function\n");
	strcpy(dest,"Heloooo!!");
	printf("Before ft_memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, strlen(src)+1);
	printf("After ft_memcpy dest = %s\n", dest);

	return(0);
} */