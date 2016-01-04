/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:00:26 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/16 02:47:35 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len != 0)
	{
		if (dst <= src)
			return (ft_memcpy(dst, src, len));
		while (len > 0)
		{
			len--;
			*(char *)(dst + len) = *(char *)(src + len);
		}
	}
	return (dst);
}
