/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:38:48 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 23:43:13 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

static void	ecs_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ecs_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		ecs_putchar_fd(str[i], fd);
		i++;
	}
}

void	ecs_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ecs_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ecs_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n > 9)
		ecs_putnbr_fd(n / 10, fd);
	ecs_putchar_fd((n % 10) + '0', fd);
}
