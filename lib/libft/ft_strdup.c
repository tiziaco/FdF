/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:06:04 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/24 15:51:03 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* #include<string.h>
#include<stdio.h>
int main()
{
    char source[] = "Hello world";

    char* targetSTD = strdup(source);
	char* target42 = ft_strdup(source);

    printf("STD function: %s\n", targetSTD);
	printf("42 function: %s\n", target42);
	free(targetSTD);
	free(target42);
    return 0;
} */
