/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:11:21 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/20 17:26:08 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* // TEST
#include <stdio.h>
void capitalize(unsigned int index, char *c)
{
	index += 1;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 'a' + 'A';
}

int main()
{
	char originalString[] = "Hello, ciao!";

	// Print the original and capitalized strings
	printf("Original String: %s\n", originalString);

	ft_striteri(originalString, &capitalize);
	printf("Capitalized String: %s\n", originalString);

	return 0;
} */