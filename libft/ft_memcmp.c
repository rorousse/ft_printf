/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:25:44 by rorousse          #+#    #+#             */
/*   Updated: 2015/11/30 23:30:50 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		if (*((unsigned char*)s1) != *((unsigned char*)s2))
			return (*((unsigned char*)s1) - *((unsigned char*)s2));
		i++;
		s1++;
		s2++;
	}
	return (0);
}
