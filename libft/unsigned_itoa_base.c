/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 21:35:45 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/28 16:50:10 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	det_size(uintmax_t n, int base)
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

static void	ft_calcul_rec(uintmax_t n, int base, char *str)
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

char		*unsigned_itoa_base(uintmax_t n, int base)
{
	int		size;
	char	*str;

	if (n == 0)
	{
		str = (char*)malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		size = det_size(n, base);
		str = (char*)malloc((size + 2) * sizeof(char));
		ft_bzero(str, size + 2);
		ft_calcul_rec(n, base, str);
	}
	return (str);
}
