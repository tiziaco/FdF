/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:12:49 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/21 13:13:02 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last && last->next)
		last = last->next;
	last->next = new;
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
	int intValue2 = 66;
	t_list *intNode = ft_lstnew(&intValue);
	t_list *stringNode = ft_lstnew(&intValue2);
	t_list *list = malloc(sizeof(t_list));

	// Print the content of the integer node
	printf("Integer Node Content: %d\n", *(int *)intNode->content);
	printf("String Node Content: %d\n", *(int *)stringNode->content);

	ft_lstadd_back(&list, intNode);
	ft_lstadd_back(&list, stringNode);
	print_list(list);
	// printf("%p\n ", intNode);
	// printf("%p\n ", stringNode);

	// Don't forget to free the memory when you're done with the list
	free(intNode);
	free(stringNode);

	return 0;
} */