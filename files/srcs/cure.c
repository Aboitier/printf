/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:12:21 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/19 00:10:26 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"
#include <stdarg.h>

int		cure(t_ptf *percents, char *format, va_list ap)
{
	t_ptf 	*word;
	char 	*tmp;
	int 	i;

	i = 0;
	word = percents->next;
	while (word)
	{
		if (check_double_pct(format + i) == 1)		
		{
			tmp = ft_strsub(format, i, word->pos - i);
			write(1, (char*)tmp, ft_strlen(tmp));
			//insert function for dispatch
			lobby(&word);			
			i = word->pos + (int)ft_strlen(word->symptoms) + 2;	
			printf("\ni = %d\n", i);
//			free(tmp);
		}
//	envoyer le current word (conv, symptomes) associe a l'arg du meme nombre (rank) a une fonction qui check et qui l'ecrira
		word = word->next;
	}
	//return nb printed
	return (1);
}

//function to get nth variable (based on word->rank)

int		lobby(t_ptf	**word)
{
	char nurse[8];
	int j;

	ft_memcpy(nurse, "diouxXf", 8);
	j = -1;
	while (nurse[++j])
		if (nurse[j] = (*word)->conv)
			//call a function managing 'diouxXf' sending current word;
	ft_memcpy(nurse,"csp", 4);
	j = -1;
	while (nurse[++j])
		if (nurse[j] = (*word)->conv)
			//call a function to manage 'csp' sending current word;


	conv_check(&word);
	return (0);	
}

int		d_check(t_ptf **word)
{
	printf("hey\n");
	return (0);
}
int		check_double_pct(char *format)
{
	int i;

	i = -1;
	while (format[++i])
		if (format[i] == '%' && format[i + 1] == '%')
			return (-1);	
		else if (format[i] == '%' && format[i + 1] != '%')
			return (1);
	return (1);
}
