/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 03:53:37 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/16 00:42:21 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fuck_norminette(int *a, int *b, int mode)
{
	if (mode == 1)
	{
		*a = 0;
		*b = -1;
	}
	else
	{
		(*a)++;
		(*b)++;
	}
}

static int	ft_count_words(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

static int	*ft_size_words(char const *s, char c)
{
	int	*tab;
	int i;
	int y;
	int index;

	ft_fuck_norminette(&i, &index, 1);
	if (!(tab = (int*)malloc(ft_count_words(s, c) * sizeof(int)))
	|| ft_count_words(s, c) == 0)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			y = 0;
			index++;
			while (s[i] != c && s[i])
			{
				ft_fuck_norminette(&i, &y, 2);
			}
			i--;
			tab[index] = y;
		}
		i++;
	}
	return (tab);
}

static void	ft_fill(const char *s, char c, char **table)
{
	int i;
	int y;
	int index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			y = 0;
			while (s[i] != c && s[i])
			{
				table[index][y] = s[i];
				y++;
				i++;
			}
			table[index][y] = '\0';
			index++;
			i--;
		}
		i++;
	}
	table[index] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		*nb;
	char	**table;

	i = 0;
	table = NULL;
	if (s == NULL)
		return (NULL);
	nb = ft_size_words(s, c);
	if (!(table = malloc((ft_count_words(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (i < ft_count_words(s, c) && nb != NULL)
	{
		if (!(table[i] = (char*)malloc((nb[i] + 1) * sizeof(char))))
			return (NULL);
		i++;
	}
	ft_fill(s, c, table);
	free(nb);
	return (table);
}
