/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:21:07 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/09 21:37:39 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(char *str)
{
	int		i;
	char	temp;

	i = 0;
	while (i < (int)ft_strlen(str) / 2)
	{
		temp = str[i];
		str[i] = str[ft_strlen(str) - (i + 1)];
		str[ft_strlen(str) - (i + 1)] = temp;
		i++;
	}
}
