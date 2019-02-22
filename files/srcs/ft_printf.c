/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:55:34 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/22 05:57:01 by aboitier         ###   ########.fr       */
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
	va_start(ap, format);
	blood_test(&percents, ap);
	// add function to input va_arg into struct
	//cure(percents, (char *)format, ap);
	//global_info(percents);
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

void	word_info(t_ptf *word)
{
	printf("rank = %d conv = %c\n", word->rank, word->conv);
	printf("symptoms =%s\n", word->symptoms);
	printf("options = %s\n", word->options);
	printf("width = %lu\n", word->width);
	printf("precision = %lu\n", word->precision);
	printf("flags = %s\n", word->flags);
	printf("\n");
}

void	global_info(t_ptf *percents)
{
	percents = percents->next;
	printf("\n");
	while (percents)
	{
		printf("\t%%"_GREEN"%d"_END"", percents->rank);
		printf("  conv: "_BBLUE"%c"_END, percents->conv);
		printf(" -pos '%%' dans format: "_YELLOW"%d"_END"  \n", percents->pos);
		printf("\tsymptoms:"_RED"%s "_END, percents->symptoms);
	   	printf("\toptions:"_RED"'%s'\n"_END, percents->options);	
	   	printf("\twdith:"_RED"'%lu'\n"_END, percents->width);	
		printf("\tprecision:"_RED"'%lu\n"_END, percents->precision);
		printf("\tflags:"_RED"'%s\n\n"_END, percents->flags);
		
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
