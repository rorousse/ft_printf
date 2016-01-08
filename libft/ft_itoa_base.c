/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 21:21:32 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/08 11:01:24 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	det_size(int n, int base)
{
	int		count;

	count = 0;
	while (n != 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

static void	ft_calcul_rec(int n, int base, char *str)
{
	if (n != 0)
	{
		ft_calcul_rec(n / base, base, str);
		while (*str)
			str++;
		if (n % base < 10)
			*str = (n % base) + '0';
		else
			*str = (n % base) - 10 + 'A';
	}
}

char		*ft_itoa_base(int n, int base)
{
	int		size;
	char	*str;

	size = det_size(n, base);
	str = (char*)malloc((size + 2) * sizeof(char));
	ft_bzero(str, size + 2);
	if (n >= 0)
		ft_calcul_rec(n, base, str);
	else
	{
		*str = '-';
		ft_calcul_rec((n * -1), base, str);
	}
	return (str);
}