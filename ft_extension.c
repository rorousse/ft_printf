/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 14:37:58 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/05 13:55:22 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	det_precision(const char *restrict str, int *i, t_var *myvar, va_list *ap)
{
	*i = *i + 1;
	if (ft_isdigit(str[*i]) == 1)
		myvar->precision = ft_atoi(str + *i);
	else if (str[*i] == '*')
		myvar->precision = va_arg(*ap, long long int);
	else
		myvar->precision = 0;
	while ((ft_isdigit(str[*i]) == 1) || str[*i] == '*')
		*i = *i + 1;
}

static void	check_negative_flag(t_var *myvar)
{
	if (myvar->largeur < 0)
	{
		myvar->largeur = myvar->largeur * (-1);
		myvar->completion = 'r';
		myvar->negation = 1;
	}
}

int			ft_extension(t_var *myvar, const char *restrict str, va_list *ap)
{
	int		i;

	i = 0;
	while (str[i] != myvar->type)
	{
		if (str[i] == '.')
			det_precision(str, &i, myvar, ap);
		else if ((ft_isdigit(str[i]) == 1) || str[i] == '*')
		{
			if (str[i] == '0')
			{
				myvar->flag_largeur = 1;
				if (str[i + 1] == '*')
					myvar->largeur = va_arg(*ap, int);
				else
					myvar->largeur = ft_atoi(str + i + 1);
			}
			else if (str[i] == '*')
				myvar->largeur = va_arg(*ap, int);
			else
				myvar->largeur = ft_atoi(str + i);
			if (ft_isdigit(str[i]) == 1)
				while ((ft_isdigit(str[i]) == 1))
					i++;
			else
				i++;
		}
		else
			i++;
	}
	check_negative_flag(myvar);
	return (0);
}
