/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 14:37:58 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/22 16:15:25 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	det_precision(const char *restrict str, int *i, t_var *myvar)
{
	*i = *i + 1;
	if (ft_isdigit(str[*i]) == 1)
		myvar->precision = ft_atoi(str + *i);
	else
		myvar->precision = 0;
	while (ft_isdigit(str[*i]) == 1)
		*i = *i + 1;
}

int			ft_extension(t_var *myvar, const char *restrict str)
{
	int		i;

	i = 0;
	while (str[i] != myvar->type)
	{
		if (str[i] == '.')
			det_precision(str, &i, myvar);
		else if (ft_isdigit(str[i]) == 1)
		{
			if (str[i] == '0')
			{
				myvar->flag_largeur = 1;
				myvar->largeur = ft_atoi(str + i + 1);
			}
			else
				myvar->largeur = ft_atoi(str + i);
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
		else
			i++;
	}
	return (0);
}
