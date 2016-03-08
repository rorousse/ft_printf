/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:13:18 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/08 11:53:59 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_init_precision(t_var *myvar, int *taille, int *nb)
{
	*nb = myvar->precision;
	*taille = ft_strlen(myvar->data);
	if (*(myvar->data) == '-' || *(myvar->data) == '+')
		*taille = *taille - 1;
}

static void	ft_uni_init_precision(t_var *myvar, int *taille, int *nb, int *i)
{
	*nb = myvar->precision;
	*taille = 0;
	*i = -1;
}

void		ft_precision(t_var *myvar)
{
	int		taille;
	int		nb;

	ft_init_precision(myvar, &taille, &nb);
	if (nb >= 0 && myvar->type != '%' && myvar->type != 'c' && myvar->type != 'f' && myvar->type != 'F')
	{
		if (nb == 0 && *(myvar->data) == '0')
			myvar->data[0] = '\0';
		else if (myvar->type == 's')
			myvar->data[nb] = '\0';
		else
		{
			while (nb > taille)
			{
				if (myvar->type == 'x' || myvar->type == 'X')
					ft_insert_str(0, &(myvar->data), "0");
				else if (*(myvar->data) == '+' || *(myvar->data) == '-')
					ft_insert_str(1, &(myvar->data), "0");
				else
					ft_insert_str(0, &(myvar->data), "0");
				nb--;
			}
		}
	}
}

void		ft_uni_precision(t_var *myvar)
{
	int		taille;
	int		nb;
	int		i;

	ft_uni_init_precision(myvar, &taille, &nb, &i);
	if (nb >= 0 && myvar->type != '%' && myvar->type != 'c')
	{
		if (nb == 0 && *(myvar->unidata) == L'0')
			myvar->unidata[0] = L'\0';
		else if (myvar->type == 'S')
		{
			while (nb >= taille)
			{
				i++;
				taille = taille + ft_uni_size(myvar->unidata[i]);
			}
			myvar->unidata[i] = L'\0';
		}
	}
}
