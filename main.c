/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:04:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/02 14:08:25 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include "ft_printf.h"
#include <locale.h>

int main()
{
	int	tailleor;
	int	taillemine;

	setlocale(LC_ALL, "en_US.UTF-8");
	tailleor = printf("%+O\n", 0);
	taillemine = ft_printf("%+O\n", 0);
	printf("original %d mien %d\n",tailleor,taillemine);
	return (0);
}
