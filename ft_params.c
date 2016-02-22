/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/22 17:51:24 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <inttypes.h>

static void	ft_gestion_char(va_list *ap, t_var *myvar)
{
	myvar->data = (char*)malloc(2 * sizeof(char));
	myvar->data[0] = (va_arg(*ap, int));
	myvar->data[1] = '\0';
	if (myvar->data[0] == 0)
	{
		myvar->data[0] = 'a';
		myvar->char_null = 1;
	}
}

static void	ft_gestion_unsigned(va_list *ap, t_var *myvar)
{
	if (ft_strcmp(myvar->treatment, "l") == 0 || myvar->type == 'U')
		myvar->data = unsigned_itoa_base(va_arg(*ap, long unsigned), 10);
	else if (ft_strcmp(myvar->treatment, "ll") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, long long unsigned), 10);
	else if (ft_strcmp(myvar->treatment, "j") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, uintmax_t), 10);
	else
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned int), 10);
}

void		ft_gestion_params(va_list *ap, t_var *myvar)
{
	if (myvar->type == 's')
		myvar->data = ft_strdup(va_arg(*ap, char*));
	else if (myvar->type == 'd' || myvar->type == 'i' || myvar->type == 'D')
		ft_gestion_integer(ap, myvar);
	else if (myvar->type == 'c')
		ft_gestion_char(ap, myvar);
	else if (myvar->type == 'p')
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long long int),
		16);
	else if (ft_strchr("xX", myvar->type) != NULL)
		ft_gestion_hexa(ap, myvar);
	else if (myvar->type == 'u' || myvar->type == 'U')
		ft_gestion_unsigned(ap, myvar);
	else if (myvar->type == 'o' || myvar->type == 'O')
		ft_gestion_octal(ap, myvar);
	else
	{
		myvar->data = (char*)malloc(2 * sizeof(char));
		ft_bzero(myvar->data, 2);
		myvar->data[0] = myvar->type;
	}
	if (myvar->data == NULL)
		myvar->data = ft_strdup("(null)");
}
