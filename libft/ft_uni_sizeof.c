/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_sizeof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:27:51 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/03 14:36:58 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_uni_sizeof(wchar_t c)
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
