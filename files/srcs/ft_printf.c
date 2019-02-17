/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:55:34 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/17 05:48:27 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../includes/head.h"

int	ft_printf(const char *format, ...)
{
	int val;
	int i;
	int	pct_count;
	t_ptf *percents;
	va_list ap;

	val = 0;
	i = -1;
	percents = init_head(percents);
	ft_count_pct(format, &percents);
	print_info(percents);
	va_start(ap, format);
	while (i++ < percents->total_pct_count)
		val+= va_arg(ap, int);

	va_end(ap);
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

void	print_info(t_ptf *percents)
{
	percents = percents->next;
	while (percents)
	{
		printf("\t%%"_GREEN"%d"_END" "_BBLUE"%c"_END" conv symptoms "_RED"%s"_END"\n", percents->rank, percents->conv, percents->symptoms);
		percents = percents->next;
	}
}

//int main(void) 
//{
//	//printf("Sum of 10, 20 and 30 = %d\n",  sum(3, 10, 20, 30) );
//	//	printf("Sum of 4, 20, 25 and 30 = %d\n",  
//
//	int i = 3, d = 4, c = 5;
//	sum(4, 4, 20, 25, 30);
//	//	ft_printf("Le temps est %ab11d% beau, %123d%987d, %f, %c", i, d, c); 
//	return 0;
//}