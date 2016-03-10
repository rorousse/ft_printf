/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:15:12 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/10 17:27:31 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

static void	color_case(char **format, int *value)
{
	if (coloration(*format + 1) == 1)
	{
		while (**format != '}')
			*format = *format + 1;
	}
	else
	{
		write(1, *format, 1);
		*value = *value + 1;
	}
}

static void	bouclage(const char *restrict format, int *value, va_list *ap)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'n')
				*(va_arg(*ap, int*)) = *value;
			else
			{
				*value = *value + ft_lecture(format, ap);
				while ((ft_strchr("-+ #.*hlLjz", *format) != NULL
					|| ft_isdigit(*format)) && *format)
					format++;
			}
		}
		else if (*format == '{')
			color_case((char**)(&format), value);
		else
		{
			write(1, format, 1);
			*value = *value + 1;
		}
		if (*format)
			format++;
	}
}

int			ft_printf(const char *restrict format, ...)
{
	int			value;
	va_list		ap;

	value = 0;
	va_start(ap, format);
	bouclage(format, &value, &ap);
	va_end(ap);
	return (value);
}
