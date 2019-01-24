/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:03:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/01/24 23:25:25 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf_files/head.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("that was not correct, make an effort to input a valid argsnb\n");
		return (0);
	}
	else
		printf(_END"STR NO_FLAGS 		---> "_BGREEN"%s\n", av[1]);
		printf(_END"INT option +		---> "_BGREEN"%+d\n", ft_atoi(av[1]));
		printf(_END"INT option ' ' 		---> "_BGREEN"% d\n", ft_atoi(av[1]));
	return (0);
}
