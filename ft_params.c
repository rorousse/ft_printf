/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:27:01 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/04 23:16:55 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

void		ft_gestion_params(void *param, char flag)
{
	if (flag == 's' || flag == 'S')
		ft_putstr((char*)param);
	if (flag == 'd' || flag == 'D')
		ft_putnbr((int)param);
	if (flag == 'c')
		ft_putchar((char)param);
}
