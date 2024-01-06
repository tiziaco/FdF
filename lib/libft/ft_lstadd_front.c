/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:12:49 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/20 18:41:48 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/* #include<stdio.h>
// Function to print the content of each node in the list
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%p ", lst->content);
        lst = lst->next;
    }
    printf("\n");
}

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

int main(void)
{
	int intValue = 42;
	char stringValue[] = "Hello";
	t_list *intNode = ft_lstnew(&intValue);
	t_list *stringNode = ft_lstnew(stringValue);
	t_list *list;

	// Print the content of the integer node
	printf("Integer Node Content: %d\n", *(int *)intNode->content);
	printf("String Node Content: %s\n", (char *)stringNode->content);

	ft_lstadd_front(&list, intNode);
	ft_lstadd_front(&list, stringNode);

	print_list(list);

	// Don't forget to free the memory when you're done with the list
	free(intNode);
	free(stringNode);

	return 0;
} */