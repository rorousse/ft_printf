/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 21:21:32 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/18 21:45:38 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int n, int base)
{
	unsigned long long int	nbis;
	char					*str;
	char					*temp;

	if (n < 0)
	{
		nbis = n * (-1);
		temp = unsigned_itoa_base(nbis, base);
		str = ft_strjoin("-", temp);
		free(temp);
	}
	else
	{
		nbis = n;
		str = unsigned_itoa_base(nbis, base);
	}
	return (str);
}
