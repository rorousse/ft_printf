/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 22:47:58 by rorousse          #+#    #+#             */
/*   Updated: 2015/11/30 23:22:12 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		*((char*)dst) = *((char*)src);
		if (*((char*)dst) == c)
			return (dst + 1);
		dst++;
		src++;
		i++;
	}
	return (NULL);
}
