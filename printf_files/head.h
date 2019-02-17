/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:00:25 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/17 04:51:54 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct 	s_ftprintf
{
	char 				conv;
	int					rank;
	char				*options;
	int					width;
	char				*precision;
	char				*symptoms;
	int					total_pct_count;
	struct s_ftprintf	*next;
}				t_ptf;

/************
*			*
*  COLORS	*
*			*
*************
*/

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

int		ft_auscultate(const char *patient);
t_ptf		*ft_count_pct(const char *format, t_ptf **head);
t_ptf		*init_head(t_ptf *head);
int		init_conv(t_ptf **percents, int rank, char *symptoms, char conv);
int		doctor(char *format, int rank, int position, t_ptf **percents);

int		ft_printf(const char *format, ...);


#endif
