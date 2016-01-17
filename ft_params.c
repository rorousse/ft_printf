/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/17 17:43:52 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

void		ft_gestion_params(va_list *ap, var_t *myvar, char flag)
{
	if (flag == 's')
		myvar->data = va_arg(*ap, char*);
	else if (flag == 'd' || flag == 'i')
		myvar->data = ft_itoa(va_arg(*ap,int));
	else if (flag == 'c')
	{
		myvar->data  = (char*)malloc(2 * sizeof(char));
		myvar->data[0] = (va_arg(*ap,int));
		myvar->data[1] = '\0';
	}
	else if (ft_strchr("pxX", flag) != NULL)
		myvar->data = unsigned_itoa_base(va_arg(*ap,unsigned long long int),16);
	else if (flag == 'u')
	  myvar->data = unsigned_itoa_base(va_arg(*ap,unsigned int), 10);
	else if (flag == 'o')
		myvar->data = ft_itoa_base(va_arg(*ap,int),8);
}

void		ft_gestion_flags(var_t *myvar, const char *restrict str)
{
	int		i;

	i = 0;
	while (str[i] != myvar->type)
	{
		if (str[i] == '+')
		{
			if (str[0] != '-')
				ft_insert_str(&(myvar->data), "+");
		}
		else if(str[i] == '#')
			ft_alternate_form(str,myvar);
		i++;
	}
}
