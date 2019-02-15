/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:00:25 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/15 17:20:10 by aboitier         ###   ########.fr       */
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
	struct s_ftprintf	*next;
}				ptf;

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

int		ft_auscultate(const char *patient, ptf *head);
ptf		*ft_count_pct(const char *format, ptf *head);
ptf		*init_head(ptf *head);
ptf		*init_conv(ptf *pct, int rank, char *symptoms);
ptf		*doctor(char *format, int rank, int position, ptf *word);

int		ft_printf(const char *format, ...);


#endif
