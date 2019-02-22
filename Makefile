# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboitier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 19:51:24 by aboitier          #+#    #+#              #
#    Updated: 2019/02/22 05:27:24 by aboitier         ###   ########.fr        #
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

A_PATH = ./.annex

LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a

SRCS_PATH = ./files/srcs
SRCS = $(SRCS_PATH)/check.c $(SRCS_PATH)/init.c $(SRCS_PATH)/ft_printf.c $(SRCS_PATH)/get_type.c #$(SRCS_PATH)/cure.c 

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

run : 
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(SRCS) $(LIBFT) $(MAIN_TEST) -o $(NAME)
	@clear
	@echo "\t$(BBLUE)O$(END)U$(RED)T$(END)$(BBLUE)P$(END)U$(RED)T$(END)"
	@./$(NAME)

#############
#			#
#   TEST 	#
# 			#
#############

REAL = printf
MINE = ft_printf

MAIN_TEST = $(A_PATH)/main_test.c

trandom :
	@sh .annex/modify/pct_conv.sh $(nb)	
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(LIBFT) $(MAIN_TEST) -o $(REAL)
	@echo "$(GREEN)\tREAL PRINTF$(END)" 
	@./$(REAL)

ifeq (ptest2,$(firstword $(MAKECMDGOALS)))
  PTEST_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
 	 $(eval $RGS):;@:)
endif

tdiff : trandom
	@sed -i '' 's/printf/ft_printf/g' $(MAIN_TEST)
	@$(CC) $(LIBFT) $(SRCS) $(MAIN_TEST) -o $(MINE)
	@echo "$(BBLUE)\t MY PRINTF$(END)"
	@./$(MINE)

catmain :
	@cat $(MAIN_TEST) | sed 's/\"_BBLUE\"//g' | sed 's/\"_RED\"//g' | sed 's/\"_END\"//g' | sed 's/\"_MAGENTA\"//g' | sed 's/\"_CYAN\"//g' | grep printf

removecol :
	@sed -i '' 's/\"_BBLUE\"//g' 	.annex/main_test.c
	@sed -i '' 's/\"_RED\"//g'		.annex/main_test.c
	@sed -i '' 's/\"_END\"//g'		.annex/main_test.c
	@sed -i '' 's/\"_MAGENTA\"//g'	.annex/main_test.c
	@sed -i '' 's/\"_CYAN\"//g'		.annex/main_test.c

greppct:
	@grep -o -E "%.{1,6}" $(MAIN_TEST)

toftptf:
	@sed -i '' 's/printf/ft_printf/g' $(MAIN_TEST)
toptf:
	@sed -i '' 's/ft_printf/printf/g' $(MAIN_TEST)


#############
#			#
#  COLORS	#
#			#
#############

RED     = \x1b[31m
GREEN   = \x1b[32m
YELLOW  = \x1b[33m
BLUE	= \x1b[34m
BBLUE	= \x1b[1;34m
MAGENTA	= \x1b[35m
CYAN	= \x1b[36m
END     = \x1b[0m

.PHONY: all clean fclean re randomt diff
