/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largeur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 18:11:34 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/05 15:52:38 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	init_function(int *nb, int *taille, t_var *myvar, int mode)
{
	*nb = myvar->largeur;
	if (mode == 1)
		*taille = (int)ft_strlen(myvar->data);
	else
		*taille = (int)ft_uni_strlen(myvar->unidata);
}

void		ft_largeur(t_var *myvar)
{
	int		taille;
	int		nb;

	init_function(&nb, &taille, myvar, 1);
	if (*(myvar->data) == '\0' && myvar->type == 'c')
		taille++;
	if (nb > taille)
	{
		while (nb > taille)
		{
			if (myvar->completion == 'l')
				ft_insert_str(0, &(myvar->data), " ");
			else
				ft_insert_end(&(myvar->data), " ");
			nb--;
		}
	}
}

void		ft_largeur_comp(t_var *myvar)
{
	int		taille;
	int		nb;

	init_function(&nb, &taille, myvar, 1);
	if (nb == 0)
		nb = 1;
	if (nb > taille)
		while (nb > taille)
		{
			if (myvar->completion == 'l')
				if (((myvar->type == 'x' || myvar->type == 'X')
					&& myvar->alternate == 1) || myvar->type == 'p')
					ft_insert_str(2, &(myvar->data), "0");
				else if (*(myvar->data) == '+' || *(myvar->data) == '-' ||
						myvar->flag == ' ')
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

void		ft_uni_largeur(t_var *myvar)
{
	int		taille;
	int		nb;

	init_function(&nb, &taille, myvar, 0);
	if (*(myvar->unidata) == L'\0' && myvar->type == 'c')
		taille++;
	if (nb > taille)
	{
		while (nb > taille)
		{
			if (myvar->completion == 'l')
				ft_uni_insert_str(0, &(myvar->unidata), L" ");
			else
				ft_uni_insert_end(&(myvar->unidata), L" ");
			nb--;
		}
	}
}

void		ft_uni_largeur_comp(t_var *myvar)
{
	int		taille;
	int		nb;

	init_function(&nb, &taille, myvar, 0);
	if (nb == 0)
		nb = 1;
	if (nb > taille)
		while (nb > taille)
		{
			if (myvar->completion == 'l')
				if ((myvar->type == 'x' || myvar->type == 'X')
					&& myvar->alternate == 1)
					ft_uni_insert_str(2, &(myvar->unidata), L"0");
				else if (*(myvar->unidata) == '+' || *(myvar->unidata) == '-')
					ft_uni_insert_str(1, &(myvar->unidata), L"0");
				else
					ft_uni_insert_str(0, &(myvar->unidata), L"0");
			else
				ft_uni_insert_end(&(myvar->unidata), L"0");
			nb--;
		}
	else
		myvar->unidata[taille] = L'\0';
}
