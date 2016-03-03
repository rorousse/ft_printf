/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:21:25 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/03 18:13:04 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <inttypes.h>

void	ft_gestion_integer(va_list *ap, t_var *myvar)
{
	char		c;
	short int	n;

	if (ft_strcmp(myvar->treatment, "l") == 0 || myvar->type == 'D')
        myvar->data = ft_itoa_base(va_arg(*ap, long int), 10);
	else if (ft_strcmp(myvar->treatment, "z") == 0)
		myvar->data = ft_itoa_base(va_arg(*ap, unsigned long long int), 10);
	else if (ft_strcmp(myvar->treatment, "hh") == 0)
	{
		c = va_arg(*ap, int);
		myvar->data = ft_itoa_base(c, 10);
	}
	else if (ft_strcmp(myvar->treatment, "h") == 0)
	{
		n = va_arg(*ap, int);
		myvar->data = ft_itoa_base(n, 10);
	}
	else if (ft_strcmp(myvar->treatment, "ll") == 0)
		myvar->data = ft_itoa_base(va_arg(*ap, long long int), 10);
	else if (ft_strcmp(myvar->treatment, "j") == 0)
		myvar->data = ft_itoa_base(va_arg(*ap, intmax_t), 10);
	else
		myvar->data = ft_itoa_base(va_arg(*ap, int), 10);
}
