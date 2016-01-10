/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/10 13:53:48 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

void		ft_gestion_params(va_list *ap, char **dst, char flag)
{
	if (flag == 's')
		*dst = va_arg(*ap, char*);
	else if (flag == 'd' || flag == 'i')
		*dst = ft_itoa(va_arg(*ap,int));
	else if (flag == 'c')
		**dst = (va_arg(*ap,int));
	else if (ft_strchr("pxX", flag) != NULL)
		*dst = ft_itoa_base(va_arg(*ap,unsigned long long int),16);
	else if (flag == 'u')
		*dst = ft_itoa(va_arg(*ap,unsigned int));
	else if (flag == 'o')
		*dst = ft_itoa_base(va_arg(*ap,int),8);
}
