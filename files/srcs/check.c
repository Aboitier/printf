/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:38:04 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/17 05:15:55 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"
#include <stdio.h>

t_ptf		*ft_count_pct(const char *format, t_ptf **head)
{
	int i;
	int pct_count;
	int	position;
	t_ptf	*word;
	
	i = -1;
	position = 0;
	pct_count = 0;
	while (format[++i])
		if (format[i] == '%')
			if ((position = ft_auscultate(format + i + 1)) != -1)
				doctor((char*)format + i + 1, ++pct_count, position, head);
	if (!pct_count)
		return (0);
	(*head)->total_pct_count = pct_count;
	return (word);
}

/*
** counts number of valid % 
*/

int		ft_auscultate(const char *patient)
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

/*
**	inits t_ptf struct once a valid % has been found
**
*/

int		doctor(char *format, int rank, int position, t_ptf **percents)
{
	int		i;
	int		j;
	char	*symptoms;
	
	i = 0;

	symptoms = ft_strsub(format, i, position);
	if ((*percents)->next == NULL)
 	{
	      if (!((*percents)->next = (t_ptf*)malloc(sizeof(t_ptf))))
		          return (0);
	     (*percents)->next->rank = rank;
	     (*percents)->next->symptoms = symptoms;
	     (*percents)->next->conv = format[position];
	     (*percents)->next->next = NULL;
	     return (1);
	}
	else
		init_conv(percents, rank, symptoms, format[position]);
	return (1);
}