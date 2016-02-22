/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/22 11:18:52 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

static void	ft_gestion_integer(va_list *ap, t_var *myvar)
{
	char		c;
	short int	n;

	if (ft_strcmp(myvar->treatment, "z") == 0)
		myvar->data = ft_itoa_base(va_arg(*ap, unsigned long long int), 10);
	else if (ft_strcmp(myvar->treatment, "hh") == 0)
	{
		c = va_arg(*ap, int);
		myvar->data = ft_itoa_base(c, 10);
	}
	else if (ft_strcmp(myvar->treatment, "h") == 0)
	{
		n = va_arg(*ap, int);
		myvar->data = ft_itoa_base(n, 10);
	}
	else if (ft_strcmp(myvar->treatment, "l") == 0)
		myvar->data = ft_itoa_base(va_arg(*ap, long int), 10);
	else if (ft_strcmp(myvar->treatment, "ll") == 0)
		myvar->data = ft_itoa_base(va_arg(*ap, long long int), 10);
	else if (ft_strcmp(myvar->treatment, "j") == 0)
		myvar->data = ft_itoa_base(va_arg(*ap, intmax_t), 10);
	else
		myvar->data = ft_itoa_base(va_arg(*ap, int), 10);
}

static void	ft_gestion_hexa(va_list *ap, t_var *myvar)
{
	int			i;

	i = 0;
	if (ft_strcmp(myvar->treatment, "l") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long int), 16);
	else if (ft_strcmp(myvar->treatment, "ll") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long long), 16);
	else if (ft_strcmp(myvar->treatment, "j") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, uintmax_t), 16);
	else
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned int), 16);
	if (myvar->type == 'X')
		while (myvar->data[i])
		{
			myvar->data[i] = ft_toupper(myvar->data[i]);
			i++;
		}
}

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
	if (ft_strcmp(myvar->treatment, "l") == 0)
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
	else if (myvar->type == 'd' || myvar->type == 'i')
		ft_gestion_integer(ap, myvar);
	else if (myvar->type == 'c')
		ft_gestion_char(ap, myvar);
	else if (myvar->type == 'p')
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long long int),
		16);
	else if (ft_strchr("xX", myvar->type) != NULL)
		ft_gestion_hexa(ap, myvar);
	else if (myvar->type == 'u')
		ft_gestion_unsigned(ap, myvar);
	else if (myvar->type == 'U')
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long), 10);
	else if (myvar->type == 'o')
		myvar->data = ft_itoa_base(va_arg(*ap, int), 8);
	else
	{
		myvar->data = (char*)malloc(2 * sizeof(char));
		ft_bzero(myvar->data, 2);
		myvar->data[0] = myvar->type;
	}
	if (myvar->data == NULL)
		myvar->data = ft_strdup("(null)");
}
