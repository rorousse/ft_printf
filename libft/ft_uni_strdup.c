/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:40:40 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/02 11:31:18 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_uni_strdup(wchar_t *str)
{
	int		i;
	int		taille;
	wchar_t	*new;

	i = 0;
	taille = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != L'\0')
	{
		i++;
		taille++;
	}
	new = (wchar_t*)malloc((taille + 1) * sizeof(wchar_t));
	i = 0;
	while (str[i] != L'\0')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = L'\0';
	return (new);
}
