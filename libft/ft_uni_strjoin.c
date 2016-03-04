/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:44:14 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/04 10:12:48 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_uni_strjoin(wchar_t *s1, wchar_t *s2)
{
	wchar_t *str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (wchar_t*)malloc((ft_uni_strlen(s1) +
	ft_uni_strlen(s2) + 1) * sizeof(wchar_t));
	ft_bzero(str, (ft_uni_strlen(s1) +
	ft_uni_strlen(s2) + 1) * sizeof(wchar_t));
	if (str == NULL)
		return (NULL);
	ft_uni_strcat(str, s1);
	ft_uni_strcat(str, s2);
	return (str);
}
