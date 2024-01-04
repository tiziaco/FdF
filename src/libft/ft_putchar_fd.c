/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:41:23 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/23 13:27:57 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* #include <stdio.h>
int main(void)
{
	int fd;
	
	fd = open("test2.txt", O_RDWR);
	ft_putchar_fd('a', fd);
	printf("Called write function\n");
	close(fd);
	return (0);
} */