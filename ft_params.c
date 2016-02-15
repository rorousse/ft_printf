/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/15 11:59:00 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

void		ft_check_treatment(var_t *myvar, const char *restrict str)
{
	int		i;
	int		taille;

	i = 0;
	taille = 0;
	myvar->treatment = (char*)malloc(sizeof(char));
	myvar->treatment[0] = '\0';
	while (str[i] != myvar->type && str[i])
	{
		if (ft_strchr("jhlLz",str[i]))
			taille++;
		i++;
	}
	i = 0;
	if (taille > 0)
	{
		free(myvar->treatment);
		myvar->treatment = (char*)malloc(taille * sizeof(char) + 1);
		ft_bzero(myvar->treatment, taille + 1);
	}
	taille = 0;
	while (str[i] != myvar->type && str[i])
    {
		if (ft_strchr("jhlLz",str[i]))
		{
            myvar->treatment[taille] = str[i];
			taille++;
		}
		i++;
    }
}
		
void		ft_check_completion(var_t *myvar, const char *restrict str)
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
	{
		if (ft_strcmp(myvar->treatment,"z") == 0)
			myvar->data = ft_itoa_base(va_arg(*ap,unsigned long long int),10);
		else
			myvar->data = ft_itoa_base(va_arg(*ap,int),10);
	}
	else if (myvar->type == 'c')
	{
		myvar->data  = (char*)malloc(2 * sizeof(char));
		myvar->data[0] = (va_arg(*ap,int));
		myvar->data[1] = '\0';
		if (myvar->data[0] == 0)
			myvar->data[0] = '\0';
	}
	else if (myvar->type == 'p')
		myvar->data = unsigned_itoa_base(va_arg(*ap,unsigned long long int),16);
	else if (ft_strchr("xX", myvar->type) != NULL)
	{
		if (ft_strcmp(myvar->treatment,"l") == 0)
			myvar->data = unsigned_itoa_base(va_arg(*ap,unsigned long int),16);
		else if (ft_strcmp(myvar->treatment,"ll") == 0)
			myvar->data = unsigned_itoa_base(va_arg(*ap,unsigned long long int),16);
		else if (ft_strcmp(myvar->treatment,"j") == 0)
            myvar->data = unsigned_itoa_base(va_arg(*ap,uintmax_t),16);
		else
		{
            myvar->data = unsigned_itoa_base(va_arg(*ap,unsigned int),16);
		}
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
	else
	{
		myvar->data = (char*)malloc(2 * sizeof(char));
		ft_bzero(myvar->data,2);
		myvar->data[0] = myvar->type;
	}
	if (myvar->data == NULL)
		myvar->data = ft_strdup("(null)");
}

void		ft_gestion_flags(var_t *myvar, const char *restrict str)
{
	int		i;

	i = 0;
	while (str[i] != myvar->type)
	{
		if (str[i] == '+')
		{
			if (*(myvar->data) != '-')
				ft_insert_str(&(myvar->data), "+");
		}
		else if(str[i] == '#')
			ft_alternate_form(myvar);
		i++;
	}
}
