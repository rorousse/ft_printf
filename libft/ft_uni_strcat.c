/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_strcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:48:58 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/24 12:52:36 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_uni_strcat(wchar_t *dest, wchar_t *src)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (dest[i] != 0)
		i++;
	while (src[y] != 0)
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = 0;
	return (dest);
}
