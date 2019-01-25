# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboitier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 19:51:24 by aboitier          #+#    #+#              #
#    Updated: 2019/01/25 05:12:25 by aboitier         ###   ########.fr        #
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

.PHONY: ptest2

ptest : 
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(A_PATH)/real_printf.c -o $(REAL)
	@echo "$(GREEN)REAL PRINTF$(END)" 
	@./$(REAL) "$(t)"
	@#./$(NAME) $(1)

ifeq (ptest2,$(firstword $(MAKECMDGOALS)))
  PTEST_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
 	 $(eval $(PTEST_ARGS):;@:)
endif

ptest2 :
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LIBFT) $(A_PATH)/real_printf.c -o $(REAL)
	@echo "$(GREEN)REAL PRINTF$(END)" 
	@./$(REAL) "$(PTEST_ARGS)"
	@#./$(NAME) $(1)

chgf : re 
	@$(MAKE) -C $(LIB_PATH) 
	@#$(CC) $(CFLAGS) $(LIBFT) $(A_PATH)/modify/res_flags.c -o test
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




