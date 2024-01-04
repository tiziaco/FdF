/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:43:38 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/24 17:00:33 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = str;
	if (n == 0)
		return (str);
	while (n-- > 0)
	{
		*tmp = (unsigned char)c;
		tmp++;
	}
	return (str);
}

/* #include <stdio.h>
#include <string.h>
int main() 
{
	int i;
	int n = 10; 
	int arr[n];
	int arr2[n];
	char arr3[] = "aaaaa";
	char arr4[] = "aaaaa";

	// Test with INTEGERS
	// Test the ft_memset function
	ft_memset(arr, 0, n*sizeof(arr[0])); 
	printf("ft_memset()\n");
	i = 0;
	while(i < n) {
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	
	// Compare it with the standard function
	memset(arr2, 0, n*sizeof(arr2[0])); 
	printf("std_memset()\n");
	i = 0;
	while(i < n) {
		printf("%d ", arr2[i]);
		i++;
	}
	printf("\n");

	// Test with STRINGS
	// Test the ft_memset function
	i = 0;
	ft_memset(arr3, '#', 4); 
	printf("ft_memset()\n");
	printf("%s\n", arr3);

	// Compare with the standard function
	i = 0;
	memset(arr4, '#', 4); 
	printf("std_memset()\n");
	printf("%s", arr3);

	return (0); 
}  */