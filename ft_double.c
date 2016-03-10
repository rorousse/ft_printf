/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 11:36:16 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/10 16:53:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft/libft.h"

static void	roundup(double *decimale)
{
	double	temp;
	int		entier;

	if (*decimale < 0)
		*decimale = *decimale * (-1);
	temp = *decimale;
	entier = (int)temp;
	temp = temp - entier;
	temp = (int)(temp * 10);
	*decimale = (int)*decimale;
	if (temp >= 6)
		*decimale = *decimale + 1;
}

void		ft_gestion_double(va_list *ap, t_var *myvar)
{
	double			nb;
	long long int	entiere;
	double			decimale;
	char			*temp;

	nb = va_arg(*ap, double);
	entiere = (long long int)nb;
	decimale = nb - entiere;
	temp = ft_itoa(entiere);
	myvar->data = ft_strjoin(temp, ".");
	free(temp);
	entiere = myvar->precision;
	if (entiere == -1)
		entiere = 6;
	while (entiere > 0)
	{
		decimale = decimale * (double)10;
		entiere--;
	}
	roundup(&decimale);
	temp = ft_itoa((long long int)decimale);
	ft_free_strjoin(&(myvar->data), temp);
	free(temp);
	if (myvar->data == NULL)
		myvar->data = ft_strdup("(null)");
}
