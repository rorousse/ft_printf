/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:15:12 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/05 20:34:47 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

void		ft_printf(const char *restrict format, ...)
{
	va_list		ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_gestion_params(&ap,*format);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
}