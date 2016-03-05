/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:04:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/05 15:34:54 by rorousse         ###   ########.fr       */
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

	setlocale(LC_ALL, "en_US.UTF-8");
	ft_printf("%s %C %d %p %x %% %S", "bonjour ", L'è', 42, &free, 42, L"لحم خنزير");
	return (0);
}
