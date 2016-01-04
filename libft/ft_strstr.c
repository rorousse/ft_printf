/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:19:57 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/05 22:04:36 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (ft_strcmp(aiguille, "") == 0)
		return ((char*)meule_de_foin);
	while (meule_de_foin[i])
	{
		if (aiguille[y] == meule_de_foin[i])
		{
			while (aiguille[y] == meule_de_foin[i + y] && aiguille[y])
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
