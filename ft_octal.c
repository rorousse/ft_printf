/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:37:29 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/05 15:23:07 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <inttypes.h>

void	ft_gestion_octal(va_list *ap, t_var *myvar)
{
	unsigned char		c;
	unsigned short		n;

	if (ft_strcmp(myvar->treatment, "l") == 0 || myvar->type == 'O')
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long int), 8);
	else if (ft_strcmp(myvar->treatment, "z") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, size_t), 8);
	else if (ft_strcmp(myvar->treatment, "ll") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long long), 8);
	else if (ft_strcmp(myvar->treatment, "j") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, uintmax_t), 8);
	else if (ft_strcmp(myvar->treatment, "h") == 0)
	{
		n = va_arg(*ap, int);
		myvar->data = unsigned_itoa_base(n, 8);
	}
	else if (ft_strcmp(myvar->treatment, "hh") == 0)
	{
		c = va_arg(*ap, int);
		myvar->data = unsigned_itoa_base(c, 8);
	}
	else
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned int), 8);
}
