/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/14 16:24:31 by rorousse         ###   ########.fr       */
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
		*dst = unsigned_itoa_base(va_arg(*ap,unsigned long long int),16);
	}
	else if (flag == 'u')
	  *dst = unsigned_itoa_base(va_arg(*ap,unsigned int), 10);
	else if (flag == 'o')
		*dst = ft_itoa_base(va_arg(*ap,int),8);
}

void		ft_gestion_flags(char *dst, const char *restrict str)
{
	int		i;

	i = 0;
	while (ft_strchr("diouxXfeEgGcsp%", str[i]) != NULL)
	{
		if (str[i] == '+')
		{
			if (str[0] != '-')
				ft_insert_str(&dst, "+");
		}
		else if(str[i] == '#')
			ft_alternate_form(str,dst);
		i++;
	}
}
