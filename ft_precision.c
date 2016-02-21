/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:13:18 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/21 14:22:18 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_init_precision(var_t *myvar, int *taille, int *nb)
{
	*nb = myvar->precision;
	*taille = ft_strlen(myvar->data);
	if (*(myvar->data) == '-' || *(myvar->data) == '+')
		*taille = *taille - 1;
}

void		ft_precision(var_t *myvar)
{
	int		taille;
	int		nb;

	ft_init_precision(myvar, &taille, &nb);
	if (nb >= 0 && myvar->type != '%' && myvar->type != 'c')
	{
		if (nb == 0 && *(myvar->data) == '0')
			myvar->data[0] = '\0';
		else if (myvar->type == 's')
			myvar->data[nb] = '\0';
		else
		{
			while (nb > taille)
			{
				if ((myvar->type == 'x' || myvar->type == 'X')
				&& myvar->alternate == 1)
					ft_insert_str(2, &(myvar->data), "0");
				else if (*(myvar->data) == '+' || *(myvar->data) == '-')
					ft_insert_str(1, &(myvar->data), "0");
				else
					ft_insert_str(0, &(myvar->data), "0");
				nb--;
			}
		}
	}
}
