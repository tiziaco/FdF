/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:53:20 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/24 12:32:20 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return ((char *)s1);
	if (set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > 0 && ft_strchr(set, s1[j - 1]))
		j--;
	trim = (char *)s1 + i;
	return (ft_substr(trim, 0, j - i));
}

/* #include <stdio.h>
int	main(void)
{
	char s1[] = " lorem ipsum dolor sit amet";
	char set[] = "l ";
	char *trimmed = ft_strtrim(s1, set);

	printf("Trimmed string: %s\n", trimmed);
	return (0);
} */
