/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 22:29:09 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/05 22:33:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_octal(int nb)
{
	char	c;

	if (nb != 0)
	{
		ft_print_octal(nb / 8);
		c = (nb % 8) + '0';
		write(1, &c, 1);
	}
}
