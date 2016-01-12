/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/12 13:54:58 by rorousse         ###   ########.fr       */
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
	{
		printf("start\n");
		*dst = unsigned_itoa_base(va_arg(*ap,unsigned long long int),16);
		printf("end\n");
	}
	else if (flag == 'u')
	  *dst = unsigned_itoa_base(va_arg(*ap,unsigned int), 10);
	else if (flag == 'o')
		*dst = ft_itoa_base(va_arg(*ap,int),8);
}
