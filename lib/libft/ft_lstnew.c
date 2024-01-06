/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:12:49 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/20 14:26:26 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* #include<stdio.h>
int main(void)
{
	// Example with an integer
	int intValue = 42;
	t_list *intNode = ft_lstnew(&intValue);

	// Example with a string
	char stringValue[] = "Hello";
	t_list *stringNode = ft_lstnew(stringValue);

	// Print the content of the integer node
	printf("Integer Node Content: %d\n", *(int *)intNode->content);

	// Print the content of the string node
	printf("String Node Content: %s\n", (char *)stringNode->content);

	// Don't forget to free the memory when you're done with the list
	free(intNode);
	free(stringNode);

	return 0;
} */