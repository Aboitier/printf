/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:55:34 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/15 17:20:48 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "head.h"

int	ft_printf(const char *format, ...)
{
	int val;
	int i;
	int	pct_count;
	ptf *percents;
	va_list ap;

	val = 0;
	i = -1;
	percents = init_head(percents);
	percents = ft_count_pct(format, percents);
	//printf("%d\n", pct_count);
	va_start(ap, format);
	pct_count = 6;
	while (i++ < pct_count)
		val+= va_arg(ap, int);
	
	va_end(ap);
	printf("coucou\n");
	return (0);
}

int sum(int num_args, ...) 
{
	int val = 0;
	va_list ap;
	int i;

	va_start(ap, num_args);

	va_end(ap);

	return val;
}

int main(void) 
{
	//printf("Sum of 10, 20 and 30 = %d\n",  sum(3, 10, 20, 30) );
	//	printf("Sum of 4, 20, 25 and 30 = %d\n",  

	int i = 3, d = 4, c = 5;
	sum(4, 4, 20, 25, 30);
	ft_printf("Le temps est %ab11d% beau, %d%d, %d, %c", i, d, c); 
	printf("hey\n");
	return 0;
}
