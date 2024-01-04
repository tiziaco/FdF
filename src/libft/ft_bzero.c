/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:43:38 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/23 13:26:19 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*tmp;

	tmp = str;
	if (n == 0)
		return ;
	while (n-- > 0)
	{
		*tmp = 0;
		tmp++;
	}
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
	// Test the ft_bzero function
	ft_bzero(arr, n*sizeof(arr[0])); 
	printf("ft_bzero()\n");
	i = 0;
	while(i < n) {
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	
	// Compare it with the standard function
	bzero(arr2, n*sizeof(arr2[0])); 
	printf("std_bzero()\n");
	i = 0;
	while(i < n) {
		printf("%d ", arr2[i]);
		i++;
	}
	printf("\n");

	// Test with STRINGS
	// Test the ft_bzero function
	i = 0;
	ft_bzero(arr3, 4); 
	printf("ft_bzero()\n");
	printf("%s\n", arr3);

	// Compare with the standard function
	i = 0;
	bzero(arr4, 4); 
	printf("std_bzero()\n");
	printf("%s", arr3);

	return (0); 
} */