/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:11:48 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/09 18:01:54 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int i;

	i = 0;
	while (src[i] && (int)n != i)
	{
		dst[i] = src[i];
		i++;
	}
	while ((int)n != i)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
