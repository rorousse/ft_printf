/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:25:36 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/09 18:14:16 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	int		i;
	int		y;
	size_t	sizedest;

	i = 0;
	y = 0;
	sizedest = ft_strlen(dest);
	while (dest[i])
	{
		i++;
	}
	while (src[y] && i < (int)n - 1)
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	if (n < sizedest)
		return (n + ft_strlen(src));
	return (sizedest + ft_strlen(src));
}
