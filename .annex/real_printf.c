/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:03:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/01/24 21:15:13 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../head.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("that was not correct, make an effort to input a valid nb of args\n");
		return (0);
	}
	else
		printf(_GREEN"REAL PRINTF\n");
		printf(_END"NO FLAGS ---> "_GREEN"%s\n", av[1]);
	return (0);
}
