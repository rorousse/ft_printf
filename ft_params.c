/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/06 20:20:04 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

t_params	*init_params()
{
	t_params *new;
	if (!(new = (t_params*)malloc(sizeof(t_params))))
		return (NULL);
	if (!(new->flag = (char*)malloc(2 * sizeof(char))))
		return (NULL);
	if (!(new->precision = (char*)malloc(3 *sizeof(char))))
		return (NULL);
	if (!(new->largeur = (char*)malloc(3 *sizeof(char))))
		return (NULL);
	if (!(new->modificateur = (char*)malloc(2 *sizeof(char))))
		return (NULL);
	if (!(new->type = (char*)malloc(2 *sizeof(char))))
		return (NULL);
	return (new);
}
	
void		ft_gestion_params(va_list *ap, char **dst, char flag)
{
	if (flag == 's')
		*dst = va_arg(*ap, char*));
	else if (flag == 'd' || flag == 'i')
		*dst = ft_atoi((va_arg(*ap,int));
	else if (flag == 'c')
		**dst = (va_arg(*ap,int));
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
