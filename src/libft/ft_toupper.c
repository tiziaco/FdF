/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:43:56 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/23 13:29:53 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* # include <stdio.h>
int	main(void)
{
	char	c = '0';
	
	printf("Character: %c\n", c);
	printf("Uppercase: %c", ft_toupper(c));
	return (0);
}
*/