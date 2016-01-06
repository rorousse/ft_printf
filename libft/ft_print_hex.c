/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:25:14 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/06 12:32:47 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned long long int nombre)
{
	char	c;

	if (nombre != 0)
	{
		ft_print_hex(nombre / 16);
		if (nombre % 16 < 10)
			c = (nombre % 16) + '0';
		else if (nombre % 16 == 10)
			c = 'a';
		else if (nombre % 16 == 11)
			c = 'b';
		else if (nombre % 16 == 12)
			c = 'c';
		else if (nombre % 16 == 13)
			c = 'd';
		else if (nombre % 16 == 14)
			c = 'e';
		else if (nombre % 16 == 15)
			c = 'f';
		write(1, &c, 1);
	}
}
