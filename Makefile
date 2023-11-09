# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 12:50:23 by kde-la-c          #+#    #+#              #
#    Updated: 2023/07/09 12:50:35 by kde-la-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_DBG	= dbg
SRC			= so_long.c\
			input.c\
			output.c\
			check_map.c\
			start_game.c\
			events.c\
			play_game.c\
			movement.c
OBJS		= $(SRC:%.c=%.o)
INCLUDE		= so_long.h\
			macros.h\
			structs.h
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
# MLFLAGS		= -lmlx -framework OpenGL -framework AppKit
# MLFLAGS		= -lm -lbsd -lmlx -lXext -lX11
RM			= rm
RFLAGS		= -rf

LIBNAME		= libft.a
LIBPATH		= libft/

UNAME		:= $(shell uname)

ifeq ($(UNAME), Darwin)
  MLFLAGS := -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME), Linux)
  MLFLAGS := -lm -lbsd -lmlx -lXext -lX11
endif

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE) $(LIBNAME)
			$(CC) $(CFLAGS) $(OBJS) $(MLFLAGS) -o $(NAME) $(LIBNAME)
	$(RM) $(RFLAGS) $(OBJS)
	@echo "\033[0;31m--- RELINK ---\033[0m"
			@echo "\033[0;32m--- $(NAME) compiled successfully! ---\033[0m"

l:			$(OBJS) $(INCLUDE) $(LIBNAME)
			$(CC) $(CFLAGS) -fsanitize=leak -g3 $(OBJS) $(MLFLAGS) -o $(NAME) $(LIBNAME)
			$(RM) $(RFLAGS) $(OBJS)
			@echo "\033[0;32m--- $(NAME) compiled successfully! ---\033[0m"

m:			$(OBJS) $(INCLUDE) $(LIBNAME)
			$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) $(MLFLAGS) -o $(NAME) $(LIBNAME)
			$(RM) $(RFLAGS) $(OBJS)
			@echo "\033[0;32m--- $(NAME) compiled successfully! ---\033[0m"

debug:		$(NAME_DBG)

$(NAME_DBG): $(LIBNAME) $(SRC)
			$(CC) $(CFLAGS) $(MLFLAGS) -fdiagnostics-color=always -g3 $(SRC) $(LIBNAME) -o $@

$(LIBNAME):
			$(MAKE) -C $(LIBPATH)
			cp $(LIBPATH)$(LIBNAME) .
			$(MAKE) -C $(LIBPATH) fclean

clean:
			$(RM) $(RFLAGS) $(OBJS)
			@echo "\033[0;32m--- Objects cleaned successfully! ---\033[0m"

fclean:		clean
			$(RM) $(RFLAGS) $(NAME) $(LIBNAME)
			@echo "\033[0;32m--- Archive cleaned successfully! ---\033[0m"

re:			fclean all

.PHONY:		all clean fclean re debug m l
