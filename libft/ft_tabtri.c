/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 21:06:25 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/09 21:37:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabtri(int *tab, int size)
{
	int	*temp;
	int	i;
	int	y;
	int	min;
	int	pos;

	y = 0;
	temp = (int*)malloc(size * sizeof(int));
	while (y < size)
	{
		min = INT_MAX;
		i = -1;
		while (i < size && i++)
		{
			if (tab[i] <= min)
			{
				min = tab[i];
				pos = i;
			}
		}
		temp[y] = tab[pos];
		tab[pos] = 0;
		y++;
	}
	free(temp);
}
