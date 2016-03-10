/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:27:50 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/10 16:36:03 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_affichage(t_var *myvar)
{
	int		value;

	value = 0;
	if (myvar->char_null == 0)
	{
		value = ft_strlen(myvar->data);
		ft_putstr(myvar->data);
	}
	else
	{
		while (myvar->data[value])
		{
			if (myvar->data[value] == 'a')
				ft_putchar('\0');
			else
				ft_putchar(myvar->data[value]);
			value++;
		}
	}
	free(myvar->data);
	return (value);
}

int	ft_uni_affichage(t_var *myvar)
{
	int		value;

	value = 0;
	if (myvar->char_null == 0)
	{
		value = ft_uni_strlen(myvar->unidata);
		ft_uni_putstr(myvar->unidata);
	}
	else
	{
		while (myvar->unidata[value] != L'\0')
		{
			if (myvar->unidata[value] == L'a')
				ft_uni_putchar(L'\0');
			else
				ft_uni_putchar(myvar->unidata[value]);
			value++;
		}
	}
	free(myvar->unidata);
	return (value);
}
