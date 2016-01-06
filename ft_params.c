/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/06 12:18:17 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

void		ft_gestion_params(va_list *ap, char flag)
{
	if (flag == 's')
		ft_putstr(va_arg(*ap, char*));
	else if (flag == 'd' || flag == 'i')
		ft_putnbr(va_arg(*ap,int));
	else if (flag == 'c')
		ft_putchar(va_arg(*ap,int));
	else if (flag == 'p')
	{
		write(1,"0x",2);
		ft_print_hex(va_arg(*ap,unsigned long long int));
	}
	else if (flag == 'u')
		ft_putnbr_unsigned(va_arg(*ap,unsigned int));
	else if (flag == 'o')
		ft_print_octal(va_arg(*ap,int));
	else if (flag == 'f')
		ft_putnbr_double(va_arg(*ap,double));
}
