/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:38:04 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/15 17:17:35 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdio.h>

ptf		*ft_count_pct(const char *format, ptf *head)
{
	int i;
	int pct_count;
	int	position;
	ptf	*word;
	
// garder un pointeur de tete pour ne pas perdre les words
	i = -1;
	position = 0;
	pct_count = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{		
			position = ft_auscultate(format + i + 1, head);
			if (position != -1)
			{
				pct_count++;
				word = doctor((char*)format + i + 1, pct_count, position, word);
//				printf("word->symptoms%d %s\n", pct_count, word->symptoms);
			}
		}
	}
	printf("format = %s\n", format);
	if (!pct_count)
		return (0);
	return (word);
}

/*
** counts number of valid % 
*/

int		ft_auscultate(const char *patient, ptf *head)
{
	int		i;
	int		j;
	char	needle[11];

	ft_memcpy(needle, "diouxXfcsp", 10);
	i = -1;
	while (patient[i++])
	{
		j = -1;
		while (patient[i] != needle[j++] && patient[i] && needle[j])
		{
			if (patient[i] == needle[j])
				return (i);
			else if (patient[i] == '%')
				return (-1);
		}
	}
	return (-1);
}

ptf	*doctor(char *format, int rank, int position, ptf *word)
{
	int		i;
	int		j;
	char	*symptoms;
	
	i = 0;
//	printf("doctor position = %d\n", position);
	symptoms = ft_strsub(format, i, position);
//	printf("doctor symptoms = %s\n", symptoms);
	word = init_conv(word, rank, symptoms);
	word->conv = format[position];
//	printf("doctor conv = %c\n", word->conv);
//	printf("doctor rank = %d\n", word->rank);
	return (word);
}
