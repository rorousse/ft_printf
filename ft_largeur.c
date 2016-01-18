/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largeur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 18:11:34 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/18 16:33:57 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void ft_largeur(var_t *myvar, int nb)
{
	int		taille;

	taille = (int)ft_strlen(myvar->data);
	if (nb == 0)
		nb = 1;
	if (nb > taille )
	{
		while (nb > taille)
		{
			ft_insert_str(&(myvar->data)," ");
			nb--;
		}
	}
	else
		myvar->data[nb] = '\0';
}

void ft_largeur_comp(var_t *myvar, int nb)
{
	int		taille;

	taille = (int)ft_strlen(myvar->data);
	if (nb == 0)
		nb = 1;
	if (nb > taille )
	{
		while (nb > taille)
		{
			ft_insert_str(&(myvar->data),"0");
			nb--;
		}
	}
	else
		myvar->data[taille] = '\0';
}

void ft_precision(var_t *myvar, int nb)
{
	ft_largeur(myvar, nb);
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
				ft_precision(myvar, ft_atoi(str + i));
			else
				ft_precision(myvar,0);
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
		else if (ft_isdigit(str[i]) == 1)
		{
			if (str[i] == '0')
				ft_largeur_comp(myvar, ft_atoi(str + i + 1));
			else
				ft_largeur(myvar, ft_atoi(str + i));
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
		else
			i++;
	}
	return (0);
}
