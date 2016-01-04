/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <rorousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 23:21:20 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/09 23:22:18 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
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
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	nb = nb * neg;
	return (nb);
}
