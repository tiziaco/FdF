/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:43:56 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/23 13:26:41 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127) 
		return (1);
	else
		return (0);
}

/* # include <stdio.h>
int	main(void)
{
	char	c = 'a';
	
	printf("Character: %c\n", c);
	printf("Is the char in US-ASCII? %d", ft_isascii(c));
	return (0);
}
*/
