/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:04:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/08 13:04:10 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include "ft_printf.h"
#include <locale.h>
#include "libft/libft.h"

int main()
{
	ft_printf("{%f}{%F}\n", 1.42, 1.42);
	printf("{%f}{%F}\n", 1.42, 1.42);
	return (0);
}
