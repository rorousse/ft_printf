/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 21:21:32 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/11 15:03:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	det_size(intmax_t n, int base)
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

static void	ft_calcul_rec(intmax_t n, int base, char *str)
{
	if (n != 0)
	{
		ft_calcul_rec(n / base, base, str);
		while (*str)
			str++;
		if (n % base < 10)
			*str = (n % base) + '0';
		else
			*str = (n % base) - 10 + 'a';
	}
}

char		*ft_itoa_base(intmax_t n, int base)
{
	int		size;
	int		neg;
	char	*str;

	neg = 0;
	if (n == 0)
	{
		str = (char*)malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		if (n < 0)
		{
			n = n * (-1);
			neg = 1;
		}
		size = det_size(n, base);
		str = (char*)malloc((size + 2) * sizeof(char));
		ft_bzero(str, size + 2);
		if (neg == 1)
		{
			str[0] = '-';
			ft_calcul_rec(n, base, str + 1);
		}
		else
			ft_calcul_rec(n, base, str);
	}
	return (str);
}
