/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:03:02 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/02 11:06:59 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uni_strlen(wchar_t *str)
{
	int		i;
	int		taille;
	int		sizebin;
	char	*bin;

	taille = 0;
	i = 0;
	while(str[i] != L'\0')
	{
		bin = unsigned_itoa_base((unsigned long long int)str[i], 2);
		sizebin = ft_strlen(bin);
		if (sizebin <= 7)
			taille = taille + 1;
		else if (sizebin <= 11)
			taille = taille + 2;
		else if (sizebin <= 16)
			taille = taille + 3;
		else
			taille = taille + 4;
		free(bin);
		i++;
	}
	return (taille);
}
