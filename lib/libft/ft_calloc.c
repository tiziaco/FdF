/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:52:09 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/27 10:29:18 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}

/* #include <stdio.h>
#include <stdint.h>
int main()
{
	// Test case 1: Allocate memory for an array of 5 integers
	int* arr1 = (int*)ft_calloc(5, sizeof(int));
	if (arr1 != NULL) {
		for (int i = 0; i < 5; ++i) {
			printf("%d ", arr1[i]);  // Should print 0 0 0 0 0
		}
		printf("\n");

		free(arr1);
	}

	// Test case 2: Allocate memory for an array of 3 doubles
	double* arr2 = (double*)ft_calloc(3, sizeof(double));
	if (arr2 != NULL) {
		for (int i = 0; i < 3; ++i) {
			printf("%lf ", arr2[i]);  // Should print 0.000000 0.000000 0.000000
		}
		printf("\n");

		free(arr2);
	}

	// Test case 3: Try to allocate an excessively large array
	char* arr3 = (char*)ft_calloc(SIZE_MAX, sizeof(char));
	if (arr3 == NULL)
		printf("Memory allocation failed for arr3\n");

	return (0);
} */