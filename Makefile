# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboitier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 19:51:24 by aboitier          #+#    #+#              #
#    Updated: 2019/02/06 00:09:48 by aboitier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

CC = gcc

CFLAGS= -Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
		 -O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
		 -Werror-implicit-function-declaration -Wmain -Wparentheses -Wsequence-point\
		 -Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas\
		 -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast\
		 -Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return\
		 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations\
		 -Wmissing-noreturn -Wformat -Wmissing-format-attribute\
		 -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs\
		 -Winline -Wlong-long -Wunreachable-code

#CFLAGS = $(DFLAGS)

LIB_PATH = ./libft
A_PATH = ./.annex

LIBFT = $(LIB_PATH)/libft.a

###################
#				  #
#      BASIC	  #
#				  #
###################

all : $(NAME)
	
$(NAME) : $(HEAD)
			@$(MAKE) -C $(LIB_PATH)
			
clean :
		@$(MAKE) clean -C $(LIB_PATH)
		#@rm -f

fclean : clean
	@$(MAKE) fclean -C $(LIB_PATH)
	@echo "$(GREEN)$(NAME)$(END)\t has been\t\t$(CYAN) $@\$(END)"
	@rm -rf $(NAME)

re : fclean all

#############
#			#
#   TEST 	#
# 			#
#############

REAL = printf


ptest : 
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LIBFT) $(A_PATH)/real_printf.c -o $(REAL)
	@echo "$(GREEN) REAL PRINTF $(END)" 
	@./$(REAL) "$(t)"
	@#./$(NAME) $(1)

ifeq (ptest2,$(firstword $(MAKECMDGOALS)))
  PTEST_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
 	 $(eval $RGS):;@:)
endif

ptest2 :
	@sh .annex/modify/pct_conv.sh
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LIBFT) $(A_PATH)/real_printf.c -o $(REAL)
	@echo "$(GREEN)REAL PRINTF$(END)" 
	@./$(REAL)
	@#./$(NAME) $(1)

chgf : re 
	@$(MAKE) -C $(LIB_PATH) 
	@sh .annex/modify/flags.sh $(f)
	#@./test $(A_PATH)/real_printf.c

#############
#			#
#  COLORS	#
#			#
#############

RED     = \x1b[31m
GREEN   = \x1b[32m
YELLOW  = \x1b[33m
BLUE	= \x1b[34m
MAGENTA	= \x1b[35m
CYAN	= \x1b[36m
END     = \x1b[0m

.PHONY: ptest2
