/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:43:38 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/24 17:00:20 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*tmp_str1;
	unsigned char	*tmp_str2;

	tmp_str1 = (unsigned char *)str1;
	tmp_str2 = (unsigned char *)str2;
	while (n-- > 0)
	{
		if (*tmp_str1 != *tmp_str2)
			return (*tmp_str1 - *tmp_str2);
		tmp_str1++;
		tmp_str2++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main (void) 
{
	char str1[15];
	char str2[15];
	int ret;

	memcpy(str1, "abcdef", 6);
	memcpy(str2, "ABCDEF", 6);

	ret = ft_memcmp(str1, str2, 5);

	if(ret > 0) {
		printf("str2 is less than str1");
	} else if(ret < 0) {
		printf("str1 is less than str2");
	} else {
		printf("str1 is equal to str2");
	}

	return(0);
} */