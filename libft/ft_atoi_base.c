/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:04:36 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/17 15:13:24 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, int base)
{
	int nb;
	int neg;
	int i;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
	|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = nb * base;
		if (str[i] >= '0' && str[i] <= '9' )
			nb = nb + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'z')
			nb = nb + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			nb = nb + (str[i] - 'A' + 10);
		i++;
	}
	nb = nb * neg;
	return (nb);
}
