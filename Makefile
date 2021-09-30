# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/25 20:20:38 by florianhame       #+#    #+#              #
#    Updated: 2021/09/28 12:16:45 by fhamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME		=	philo

D_INCLUDES	=	includes/

D_OBJS		=	objs/

D_SRCS		=	srcs/

_SRC_		=	action.c \
				error.c \
				fork.c \
				init.c \
				main.c \
				philo.c \
				thread.c \
				time.c \
				utils.c \
				watch.c \

SRCS		=	$(addprefix $(D_SRCS), $(_SRC_))

OBJS		=	$(addprefix $(D_OBJS), $(_SRC_:.c=.o))

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

FSANITIZE	=	-g -fsanitize=address

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

all	: $(D_OBJS) $(LIBFT) $(NAME)

bonus : $(D_OBJS) $(LIBFT) $(NAME_B)

compiling_start_m :
	@python -c 'print u"\033[0;33m\u2192 " + "\033[0;33mCompiling \033[0;34m$(NAME)\033[0;33m sources..."'

compiling_end_m :
	@python -c 'print u"\033[0;32mCompiling successful \u2713 \033[0m"'

compiling_start_b :
	@python -c 'print u"\033[0;33m\u2192 " + "\033[0;33mCompiling \033[0;34m$(NAME)\033[0;33m bonus sources..."'

compiling_end_b :
	@python -c 'print u"\033[0;32mCompiling successful \u2713 \033[0m"'

$(D_OBJS) :
	@mkdir -p $@

$(D_OBJS)%.o : $(D_SRCS)%.c
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes

$(NAME) : compiling_start_m $(OBJS) compiling_end_m
	@python -c 'print u"\033[0;33m\u2192 " + "Linking objects for \033[0;34m$(NAME)\033[0;33m... \033[0m"'
	@$(CC) $(OBJS) -o $(NAME)
	@python -c 'print u"\033[0;32mLinking successful \u2713 \033[0m"'

clean :
	@rm -rf $(D_OBJS)
	@python -c 'print u"\033[0;33mObjects deleted \u2713 \033[0m"'

fclean : clean
	@rm -rf $(NAME)
	@python -c 'print u"\033[0;34m$(NAME) \033[0;33mdeleted \u2713 \033[0m"'

re : fclean all
