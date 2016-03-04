/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:09:19 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/04 10:09:39 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_uni_putstr(wchar_t *str)
{
	int	i;

	i = 0;
	while (str[i] != L'\0')
	{
		if ((unsigned long int)str[i] > 127)
			ft_uni_putchar(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
