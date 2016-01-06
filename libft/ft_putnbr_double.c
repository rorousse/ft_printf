/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:01:02 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/06 12:47:31 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

static double 	trunc(double nombre)
{
	double dec;

	dec = nombre;
	while (dec > 1)
		dec--;
	nombre = nombre - dec;
	return (nombre);
}

static void		affichage(double nombre)
{
	char	c;

	if (nombre != 0)
	{
		affichage(trunc(nombre / 10));
		c = (nombre - ((trunc(nombre / 10)) *  10)) + '0';
		write(1, &c, 1);
	}
}

void			ft_putnbr_double(double nombre)
{
	double	dec;

	if (nombre < 0)
	{
		write(1,"-",1);
		nombre = nombre * (-1);
	}
	dec = nombre;
	while (dec > 1)
		dec--;
	nombre = nombre - dec;
	affichage(nombre);
	write(1, ".", 1);
	while ((dec - (trunc(dec / 1))) != 0)
		   dec = dec * 10;
	affichage(dec);
}
