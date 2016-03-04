/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_putchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 13:42:50 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/04 10:48:05 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_remplacement(char *mask, char *bin)
{
	int		i;
	int		y;

	i = ft_strlen(mask) - 1;
	y = ft_strlen(bin) - 1;
	while (i >= 0 && y >= 0)
	{
		if (mask[i] == 'x')
		{
			mask[i] = bin[y];
			y--;
		}
		i--;
	}
	while (*mask)
	{
		if (*mask == 'x')
			*mask = '0';
		mask++;
	}
}

static void	ft_splittage(int taille, char *mask[4], char *bin, char ***splitted)
{
	if (taille <= 7)
    {
        ft_remplacement(mask[0], bin);
        *splitted = ft_strsplit(mask[0], ' ');
    }
    else if (taille <= 11)
    {
        ft_remplacement(mask[1], bin);
        *splitted = ft_strsplit(mask[1], ' ');
    }
    else if (taille <= 16)
    {
        ft_remplacement(mask[2], bin);
        *splitted = ft_strsplit(mask[2], ' ');
    }
    else
    {
        ft_remplacement(mask[3], bin);
        *splitted = ft_strsplit(mask[3], ' ');
    }
}

void		ft_uni_putchar(wchar_t c)
{
	char	*bin;
	char	*mask[4];
	char	**splitted;
	int		taille;

	mask[0] = ft_strdup("0xxxxxxx");
	mask[1] = ft_strdup("110xxxxx 10xxxxxx");
	mask[2] = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
	mask[3] = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	bin = unsigned_itoa_base((unsigned long long int)c, 2);
	taille = ft_strlen(bin);
	ft_splittage(taille, mask, bin, &splitted);
	taille = 0;
	while (splitted[taille] != NULL)
	{
		ft_putchar(ft_atoi_base(splitted[taille], 2));
		taille++;
	}
	free(bin);
	free(mask[0]);
	free(mask[1]);
	free(mask[2]);
	free(mask[3]);
	taille = 0;
	if (splitted != NULL)
	{
		while (splitted[taille] != NULL)
		{
			free(splitted[taille]);
			taille++;
		}
		free(splitted);
	}
}
