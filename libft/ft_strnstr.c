/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:19:57 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/09 18:12:49 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t n)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (n == 0)
		return (NULL);
	if (ft_strcmp(aiguille, "") == 0)
		return ((char*)meule_de_foin);
	while (meule_de_foin[i] && i < (int)n)
	{
		if (aiguille[y] == meule_de_foin[i])
		{
			while (aiguille[y] == meule_de_foin[i + y]
			&& aiguille[y] && (i + y) < (int)n)
			{
				y++;
			}
			if (aiguille[y] == '\0')
				return ((char*)(meule_de_foin + i));
			y = 0;
		}
		i++;
	}
	return (NULL);
}
