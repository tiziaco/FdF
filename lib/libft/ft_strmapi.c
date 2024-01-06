/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:04:38 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/20 17:11:53 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}

/* // TEST
#include <stdio.h>
char capitalize(unsigned int index, char c)
{
	index += 1;
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	else
		return c;
}

int main()
{
	const char originalString[] = "Hello, World!";
	char *capitalizedString = ft_strmapi(originalString, &capitalize);

	// Print the original and capitalized strings
	printf("Original String: %s\n", originalString);
	printf("Capitalized String: %s\n", capitalizedString);

	// Free the allocated memory
	free(capitalizedString);

	return 0;
} */