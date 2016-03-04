/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 10:21:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/04 10:24:07 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_uni_size(wchar_t c)
{
	int		sizebin;
	int		taille;
	char	*bin;

	taille = 0;
	bin = unsigned_itoa_base((unsigned long long int)c, 2);
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
	return (taille);
}
