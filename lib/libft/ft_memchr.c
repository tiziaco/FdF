/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:43:38 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/24 17:00:15 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*tmp_str;

	tmp_str = (unsigned char *)str;
	while (n-- > 0)
	{
		if (*tmp_str == (unsigned char)c)
			return ((void *)tmp_str);
		tmp_str++;
	}
	return (NULL);
}

/* #include<string.h>
#include<stdio.h>
int main(void) {
	const char *test_str = "Hello, World!";
	char target_char = 'W';

	// Using your my_memchr function
	void *result_my_memchr = ft_memchr(test_str, target_char, strlen(test_str));

	if (result_my_memchr != NULL) {
		printf("my_memchr: Character '%c' found at position: %ld\n", 
		target_char, (char *)result_my_memchr - test_str);
	} else {
		printf("my_memchr: Character '%c' not found in the string.\n", target_char);
	}

	// Using the standard memchr function
	void *result_memchr = memchr(test_str, target_char, strlen(test_str));

	if (result_memchr != NULL) {
		printf("memchr: Character '%c' found at position: %ld\n", 
		target_char, (char *)result_memchr - test_str);
	} else {
		printf("memchr: Character '%c' not found in the string.\n", target_char);
	}

	// Compare the results
	if (result_my_memchr == result_memchr) {
		printf("Results match!\n");
	} else {
		printf("Results do not match.\n");
	}

	return 0;
} */