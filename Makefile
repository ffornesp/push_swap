# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 19:51:17 by ffornes-          #+#    #+#              #
#    Updated: 2023/04/18 17:42:41 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

INCLUDES = include/

###############################################################################
#									SRCS									  #
###############################################################################

SRCS_DIR = srcs/
SRC_FILES =	 push_swap.c parse_input.c input_check.c
SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))

###############################################################################
#									OBJS									  #
###############################################################################

OBJS_DIR =	objs/
OBJ_FILES =	$(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

###############################################################################
#									OTHER									  #
###############################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

###############################################################################
#									RULES									  #
###############################################################################

all: 		$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS) $(LIBFT_DIR) $(LIBFT_FILE)
			$(AR) $@ $(OBJS) ### Implementation of LIBFT pending..

$(OBJS_DIR):		
						@mkdir $@

$(LIBFT_DIR):
						@make -C $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean: 		
			make -C $(LIBFT_DIR) clean
			@$(RM) $(OBJS)

fclean: 	clean
			make -C $(LIBFT_DIR) fclean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
