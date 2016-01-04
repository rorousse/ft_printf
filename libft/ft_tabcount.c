/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:56:12 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/09 21:01:01 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tabcount(char **tab)
{
	int max;
	int i;

	max = 0;
	i = 0;
	while (tab[i])
	{
		if ((int)ft_strlen(tab[i]) > max)
			max = ft_strlen(tab[i]);
		i++;
	}
	return (i);
}
