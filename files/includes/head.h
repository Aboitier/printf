/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:00:25 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/22 07:18:23 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

#include "../../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct 	s_ftprintf
{
	char 				conv;
	int					rank;
	int					pos;
	char				*options;
	unsigned long		width;
	unsigned long		precision;
	char				*flags;
	char				*symptoms;
	char				*type;
	int					total_pct_count;
	struct s_ftprintf	*next;
}				t_ptf;

/************
*			*
* FUNCTIONS	*
*			*
************/

/* CORE */
int			ft_printf(const char *format, ...);

/* INIT */
t_ptf		*init_head(t_ptf *head);
int			add_pct_pos(t_ptf **percents, int pos);
int			init_conv(t_ptf **percents, int rank, char *symptoms, char conv);
int			ft_auscultate(const char *patient);
int			doctor(char *format, int rank, int position, t_ptf **percents);
t_ptf		*ft_count_pct(const char *format, t_ptf **head);
int			irm(t_ptf **percents, va_list ap);

/* CHECK */
int			blood_test(t_ptf **percents, va_list ap);
int			get_options(t_ptf **percents, int i);
int			get_width(t_ptf **word, int i);
int			get_precision(t_ptf **word, int i);
int			get_flags(t_ptf **word, int i);
int			get_type(t_ptf **word);
int			get_dioux_type(t_ptf **word);

/* PRINT */
int			cure(t_ptf *percents, char *format, va_list ap);
int			check_double_pct(char *format);
int			lobby(t_ptf **word);
int			d_check(t_ptf **word);

/* DEBUG */
void		global_info(t_ptf *percents);
void		word_info(t_ptf *word);

/************
*			*
*  COLORS	*
*			*
************/

# define _RED     	"\x1b[31m"
# define _BRED     	"\x1b[1;31m"
# define _GREEN   	"\x1b[32m"
# define _BGREEN   	"\x1b[1;32m"
# define _YELLOW  	"\x1b[33m"
# define _BLUE    	"\x1b[34m"
# define _BBLUE    	"\x1b[1;34m"
# define _MAGENTA	"\x1b[35m"
# define _BMAGENTA	"\x1b[1;35m"
# define _CYAN   	"\x1b[36m"
# define _END  	 	"\x1b[0m"


#endif
