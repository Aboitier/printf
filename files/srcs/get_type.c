/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 07:11:25 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/22 07:18:26 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * 	unsigned int X;
 *	+ with X gives undefined behavior
 *	hh with X gives unsigned char
 *	h with X gives unsigned short
 *	ll with X gives unsigned long long
 *	L with X gives unsigned long long
 *	l with X gives unsigned long
 *	
 *	unsigned int x;
 *	l with x gives unsigned long
 *	ll with x gives unsigned long long
 *	hh with x gives unsigned char
 *
 * 	int i;
 *	L with i gives long long
 *	ll with i gives long long
 *	h with i gives short
 *
 * 	unsigned int u;
 *	l with u gives long
 *	ll with u gives unsigned long long
 *	h with u gives unsigned short
 *
 * 	int d; 
 *	l with d gives long	
 *	ll with d gives long long
 *	hh with d gives char
 *	L with d gives long long
 *
 * 	unsigned int o;
 *	l with o gives unsigned long
 *	
 *	double f;
 *
 */

#include "../includes/head.h"

int		blood_test(t_ptf **percents, va_list ap)
{
	t_ptf	*word;	
	int		i;

	word = (*percents)->next;
	while (word)
	{
		i = 0;
		// send &word and update: width, type, options, 
		if ((i = get_options(&word, i - 1)) == -1)
			return (0);
		if ((i = get_width(&word, i - 1)) == -1)
			return (0);
		if ((i = get_precision(&word, i - 1)) == -1)
			return (0);
		if ((i = get_flags(&word, i - 1)) == -1)
			return (0);
		word_info(word);
		word = word->next;
	}
	return (0);
}

int		get_type(t_ptf **word)
{
		if ((*word)->conv == 'c')
			(*word)->type = ft_memcpy((*word)->type, "char", 5);
		else if ((*word)->conv == 'p')
			(*word)->type = ft_memcpy((*word)->type, "void *", 7);
		else if ((*word)->conv == 's')
			((*word)->type = ft_memcpy((*word)->type, "char *", 7);
		else if ((*word)->conv == 'f')
			((*word)->conv = ft_memcpy((*word)->type, "float", 6);
		else if ((*word)->conv == 'd' || (*word)->conv == 'i' || (*word)->conv == 'o' 
			|| (*word)->conv == 'u' ||  (*word)->conv == 'x' || (*word)->conv == 'X')
			get_dioux_type(&word);
	return (0);
}

int		get_dioux_type(t_ptf **word)
{
		
}
int		get_options(t_ptf **word, int i)
{
	if ((*word)->symptoms)
		while (((*word)->symptoms[++i] == '#' || (*word)->symptoms[i] == ' ' || (*word)->symptoms[i] == '+' 
			|| (*word)->symptoms[i] == '-' || (*word)->symptoms[i] == '0') && (*word)->symptoms)
			if (!((*word)->options = ft_addonechar(&(*word)->options, (*word)->symptoms[i])))
				return (-1);
	return (i);
}

int		get_width(t_ptf **word, int i)
{	
	unsigned long		width;

	width = 0;
	if ((*word)->symptoms)
		while (((*word)->symptoms[++i] >= '0' && (*word)->symptoms[i] <= '9') && (*word)->symptoms[i])
				width = (width * 10) + ft_atoi(&(*word)->symptoms[i]);
	if (width > 10)
		width = width / 10;
	(*word)->width = width;
	return (i);
}

int		get_precision(t_ptf **word, int i)
{
	unsigned long	precision;

	precision = 0;
	if (!((*word)->symptoms[++i] == '.'))
		return (i);
	while ((*word)->symptoms[++i] && ((*word)->symptoms[i] >= '0' && (*word)->symptoms[i] <= '9'))
		precision = (precision * 10) + ft_atoi(&(*word)->symptoms[i]);
	if (precision > 10)
		precision = precision / 10;
	(*word)->precision = precision;
	return (i);
}

int		get_flags(t_ptf **word, int i)
{
	while ((*word)->symptoms[++i] && ((*word)->symptoms[i] == 'h' || (*word)->symptoms[i] == 'l' || (*word)->symptoms[i] == 'L'))
		if (!((*word)->flags = ft_addonechar(&(*word)->flags, (*word)->symptoms[i])))
			return (-1);
	return (1);
}	
