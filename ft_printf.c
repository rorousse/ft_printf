/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:15:12 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/21 13:27:39 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

int		ft_printf(const char *restrict format, ...)
{
	int			value;
	va_list		ap;

	value = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			value = value + ft_lecture(format, &ap);
			while ((ft_strchr("-+ #.*hlLjz", *format) != NULL
			|| ft_isdigit(*format)) && *format)
				format++;
		}
		else
		{
			write(1, format, 1);
			value++;
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (value);
}
