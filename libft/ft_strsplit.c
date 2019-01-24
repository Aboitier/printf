/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:37:04 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/20 23:14:47 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count(const char *str, char c)
{
	size_t	words;

	words = 0;
	while (*str)
	{
		if (*str != c)
			words++;
		while (*str != c && *str)
			str++;
		while (*str == c && *str)
			str++;
	}
	return (words);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**splat;
	size_t	word;
	size_t	j;
	size_t	dac;
	size_t	nb_words;

	if (!s)
		return (0);
	nb_words = ft_count(s, c);
	if (!(splat = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (0);
	j = 0;
	word = 0;
	while (word < nb_words)
	{
		while (s[j] == c && s[j])
			j++;
		dac = j;
		while (s[j] != c && s[j])
			j++;
		splat[word++] = ft_strsub(s, dac, j - dac);
	}
	splat[word] = NULL;
	return (splat);
}
