/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:00:46 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/03 22:18:02 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int pos;

	i = 0;
	pos = -1;
	while (s[i])
	{
		if (s[i] == c)
			pos = i;
		i++;
	}
	if (s[i] == c)
		pos = i;
	if (pos != (-1))
		return ((char*)s + pos);
	return (NULL);
}
