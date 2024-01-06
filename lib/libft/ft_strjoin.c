/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:59:06 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/22 14:17:06 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

/* #include <stdio.h>
int main(void)
{
	char 	*strs[] = {"How", "are", "you"};
	char	*sep = " ";
	int		strNum;
	char	*str;

	strNum = sizeof(strs) / sizeof(strs[0]);
	printf("Number of strings: %d\n", strNum);
	printf("String length: %d\n", 
			calculate_total_str_length(strs, strNum, ft_strlen(sep)));

	str = ft_strjoin(strNum, strs, sep);
	printf("%s\n", str);
	free(str);
	return (0);
} */