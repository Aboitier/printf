/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:18:44 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/17 05:11:29 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

//pct		

t_ptf		*init_head(t_ptf *head)
{
	t_ptf *percents;
	
	if (!(percents = (t_ptf*)malloc(sizeof(t_ptf))))
		return (0);
	percents->options = NULL;
	percents->precision = NULL;
	percents->symptoms = NULL;
	percents->total_pct_count = 0;
	percents->rank = 0;
	percents->next = NULL;
	return (percents);
}

int		init_conv(t_ptf **percents, int rank, char *symptoms, char conv)
{
	t_ptf *word;

	word = (*percents)->next;
	while (word->next != NULL)
		word = word->next;
	if (!((word->next) = (t_ptf*)malloc(sizeof(t_ptf))))
		return (0);
	word = word->next;
	word->conv = conv;
	if (symptoms)
	{
		word->symptoms = (char*)ft_memalloc(ft_strlen(symptoms) + 1);
		word->symptoms = ft_strcpy(word->symptoms, symptoms);
	}
	word->rank = rank;
	word->next = NULL;
	return (0);
}
