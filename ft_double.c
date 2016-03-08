/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 11:36:16 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/08 15:21:06 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft/libft.h"

void	ft_gestion_double(va_list *ap, t_var *myvar)
{
	double	nb;
	int		entiere;
	double	decimale;
	char	*temp;

	nb = va_arg(*ap, double);
	entiere = (int)nb;
	decimale = nb - entiere;
	temp = ft_itoa(entiere);
	myvar->data = ft_strjoin(temp, ".");
	free(temp);
	entiere = myvar->precision;
	if (entiere == -1)
		entiere = 6;
	while (entiere > 0)
	{
		decimale = decimale * 10;
		entiere--;
	}
	temp = ft_itoa((long long int)decimale);
	ft_free_strjoin(myvar->data, temp);
	free(temp);
}
	
