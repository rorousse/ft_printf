/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 06:11:08 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/16 00:50:18 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fuck_norminette(int *a, int *b)
{
	*a = (*a) / 10;
	(*b)++;
}

static void	check_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*neg = 1;
		*n = *n * (-1);
	}
	else
		*neg = 0;
}

static int	ft_intlen(int n)
{
	int		i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_alloc(int len, int neg)
{
	char	*str;

	str = NULL;
	if (neg == 1)
		len = len + 2;
	else
		len++;
	str = (char*)malloc((len) * sizeof(char));
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		neg;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	check_neg(&n, &neg);
	if ((str = ft_alloc(ft_intlen(n), neg)) == NULL)
		return (NULL);
	while (n > 9)
	{
		str[i] = ((n % 10) + '0');
		ft_fuck_norminette(&n, &i);
	}
	str[i] = n + '0';
	i++;
	if (neg == 1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	ft_swap(str);
	return (str);
}
