/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/18 23:12:07 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

void		ft_detection_completion(var_t *myvar, const char *restrict str)
{
	myvar->completion = 'r';
	while (*str != myvar->type)
	{
		if (*str == '-')
			myvar->completion = 'l';
		str++;
	}
}

void		ft_gestion_params(va_list *ap, var_t *myvar)
{
	int		i;

	i = 0;
	if (myvar->type == 's')
		myvar->data = ft_strdup(va_arg(*ap, char*));
	else if (myvar->type == 'd' || myvar->type == 'i')
		myvar->data = ft_itoa_base(va_arg(*ap,int),10);
	else if (myvar->type == 'c')
	{
		myvar->data  = (char*)malloc(2 * sizeof(char));
		myvar->data[0] = (va_arg(*ap,int));
		myvar->data[1] = '\0';
	}
	else if (ft_strchr("pxX", myvar->type) != NULL)
	{
		myvar->data = unsigned_itoa_base(va_arg(*ap,unsigned long long int),16);
		if (myvar->type == 'X')
		{
			while (myvar->data[i])
			{
				myvar->data[i] = ft_toupper(myvar->data[i]);
				i++;
			}
		}
	}
	else if (myvar->type == 'u')
	  myvar->data = unsigned_itoa_base(va_arg(*ap,unsigned int), 10);
	else if (myvar->type == 'o')
		myvar->data = ft_itoa_base(va_arg(*ap,int),8);
	else if (myvar->type == '%')
		myvar->data = ft_strdup("%");
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
			ft_alternate_form(myvar);
		i++;
	}
}
