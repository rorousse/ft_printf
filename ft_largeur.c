/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largeur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 18:11:34 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/15 16:56:05 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void ft_largeur(var_t *myvar)
{
	int							taille;
	unsigned long long int		nb;

	nb = myvar->largeur;
	taille = (int)ft_strlen(myvar->data);
	if (nb > (unsigned long long int)taille && !(myvar->type =='c' && *(myvar->data) == '\0'))
	{
		while (nb > (unsigned long long int)taille)
		{
			if (myvar->completion == 'r')
				ft_insert_str(0,&(myvar->data)," ");
			else
				ft_insert_end(&(myvar->data)," ");
			nb--;
		}
	}
}

void ft_largeur_comp(var_t *myvar)
{
	int		taille;
	unsigned long long int		nb;

	nb = myvar->largeur;
	taille = (int)ft_strlen(myvar->data);
	if ((myvar->type == 'x' || myvar->type == 'X') && myvar->alternate == 1)
        taille =  taille + 2;
	if (nb == 0)
		nb = 1;
	if (nb > (unsigned long long int)taille)
	{
		while (nb > (unsigned long long int)taille)
		{
			if (myvar->completion == 'r')
			{
				if ((myvar->type == 'x' || myvar->type == 'X') && myvar->alternate == 1)
					ft_insert_str(2,&(myvar->data), "0");
				else
					ft_insert_str(0,&(myvar->data),"0");
			}
			else
				ft_insert_end(&(myvar->data),"0");
			nb--;
		}
	}
	else
		myvar->data[taille] = '\0';
}

void ft_precision(var_t *myvar)
{
	int		i;
	int		nb;

	nb = myvar->precision;
	i = 0;
	if (nb > 0)
	{
		if (myvar->type == 's')
			myvar->data[nb] = '\0';
	}
}

int		ft_extend(var_t *myvar, const char *restrict str)
{
	int		i;

	i = 0;
	while (str[i] != myvar->type)
	{
		if (str[i] == '.')
		{
			i++;
			if (ft_isdigit(str[i]) == 1)
				myvar->precision = ft_atoi(str + i);
			else
				myvar->precision = 0;
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
		else if (ft_isdigit(str[i]) == 1)
		{
			if (str[i] == '0')
			{
				myvar->flag_largeur = 1;
				myvar->largeur = ft_atoi(str + i + 1);
			}
			else
				myvar->largeur = ft_atoi(str + i);
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
		else
			i++;
	}
	return (0);
}
