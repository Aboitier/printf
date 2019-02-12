/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:18:44 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/12 19:21:40 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

//pct		

ptf		*init_head(ptf head)
{
	ptf percents;
	
	if (!(percents = (ptf)malloc(sizeof(ptf))))
		return (0);
	percents->options = NULL;
	percents->precision = NULL;
	percents->symptomes = NULL;
	percents->next = NULL;
	return (percents)
}

ptf		*init_conv(ptf percents, size_t len)
{
	ptf word;
	while (percents->next != NULL)
		percents->next = percents->next->next;
	word = percents->next;	
	if (!(word = (ptf)malloc(sizeof(ptf))))
		return (0);
	word->conv = '\0';
	word->symptomes = (ptf)ft_memalloc(len);
	word->rank = rank;
	word->next = NULL;

}

// tester si on se trouve sur la bonne structure
// tester le rank 
