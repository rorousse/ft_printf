/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 19:28:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/05 19:32:23 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_gestion_decimal(va_list *ap, t_var *myvar)
{
	double						nb;
	unsigned long long int		entier;

	nb = va_arg(*ap, double);
	entier = (unsigned long long int)nb;
	nb = nb - (double)entier;
	
