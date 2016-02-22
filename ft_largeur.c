/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largeur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 18:11:34 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/21 16:21:29 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void							ft_largeur(t_var *myvar)
{
	int							taille;
	unsigned long long int		nb;

	nb = myvar->largeur;
	taille = (int)ft_strlen(myvar->data);
	if (*(myvar->data) == '\0' && myvar->type == 'c')
		taille++;
	if (nb > (unsigned long long int)taille)
	{
		while (nb > (unsigned long long int)taille)
		{
			if (myvar->completion == 'l')
				ft_insert_str(0, &(myvar->data), " ");
			else
				ft_insert_end(&(myvar->data), " ");
			nb--;
		}
	}
}

void							ft_largeur_comp(t_var *myvar)
{
	int							taille;
	unsigned long long int		nb;

	nb = myvar->largeur;
	taille = (int)ft_strlen(myvar->data);
	if (nb == 0)
		nb = 1;
	if (nb > (unsigned long long int)taille)
		while (nb > (unsigned long long int)taille)
		{
			if (myvar->completion == 'l')
				if ((myvar->type == 'x' || myvar->type == 'X')
					&& myvar->alternate == 1)
					ft_insert_str(2, &(myvar->data), "0");
				else if (*(myvar->data) == '+' || *(myvar->data) == '-')
					ft_insert_str(1, &(myvar->data), "0");
				else
					ft_insert_str(0, &(myvar->data), "0");
			else
				ft_insert_end(&(myvar->data), "0");
			nb--;
		}
	else
		myvar->data[taille] = '\0';
}
