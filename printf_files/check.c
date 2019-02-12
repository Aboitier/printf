/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 01:50:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/12 19:21:38 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdio.h>

int		ft_count_pct(const char *format, ptf head)
{
	int i;
	int pct_count;
	
	i = 0;
	pct_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			if (ft_auscultate(format + i) == 1)
				pct_count++;
		i++;
	}
	return (pct_count);
}

int		ft_auscultate(const char *patient, ptf head)
{
	int i;
	int j;
	char 	*needle[20];
	char	*symptoms;

	ft_memcpy(needle, "diouxXfcsp", 15);
	symptoms = NULL;
//	printf("patient = %s\n", patient);
	i = 0;
	while ()
	{	
		while (patient[i] != needle[j] && needle[j] && patient[i])
		{	
			if (patient[i] == needle[j])
				return (1);
			j++;
		}
		symptoms = ft_strjoin(symptoms, (char*)patient[i]);
		i++;
	}
	return (1);
}
