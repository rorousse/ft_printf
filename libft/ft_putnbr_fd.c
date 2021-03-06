/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 06:25:52 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/16 03:05:47 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char c;
	char neg;

	neg = '-';
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 12);
	}
	else
	{
		if (n < 0)
		{
			write(fd, &neg, 1);
			n = n * (-1);
		}
		c = (n % 10) + 48;
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
}
