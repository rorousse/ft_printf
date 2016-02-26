/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:03:02 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/24 15:15:45 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uni_strlen(wchar_t *str)
{
	int taille;

	taille = 0;
	while(str[taille] != L'\0')
		taille++;
	return (taille);
}
