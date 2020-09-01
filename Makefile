# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trponess <trponess@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 11:59:50 by trponess          #+#    #+#              #
#    Updated: 2019/10/03 12:37:11 by trponess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker
SRC = src/main.c src/util.c src/program_util.c\
	src/operation.c src/check_args.c src/checker.c\
	src/push_swap.c src/stack_util2.c src/programs.c\
	src/program_util2.c src/stack_util.c src/operation2.c
	
	
OBJ =  $(subst src/, objects/, $(SRC:.c=.o))
LIBFT = libft/libft.a
CFLAGS = -g -Wall -Wextra -Werror
HEADER_FLAGS = -I .
CC = clang
HEADER = inc/push_swap.h

all: $(NAME) $(NAME2)

$(NAME): $(LIBFT) $(OBJ)  
	$(CC) $(CFLAGS) $(OBJ) $(HEADER_FLAGS) $(LIBFT) -o $(NAME)
objects/%.o: src/%.c $(HEADER)
	mkdir -p objects/
	$(CC) $(CFLAGS) $(HEADER_FLAGS) -c $< -o $@

$(NAME2): $(LIBFT) $(OBJ)  
	$(CC) $(CFLAGS) $(OBJ) $(HEADER_FLAGS) $(LIBFT) -o $(NAME2)
objects/%.o: src/%.c $(HEADER)
	mkdir -p objects/
	$(CC) $(CFLAGS) $(HEADER_FLAGS) -c $< -o $@

$(LIBFT): FORCE
	$(MAKE) -C libft/

FORCE : 

clean:
	$(RM) -rf objects/ && \
	$(MAKE) -C libft/ clean

fclean: clean
	$(RM) $(NAME) && \
	$(RM) $(NAME2) && \
	$(MAKE) -C libft fclean && \
	$(RM) -r $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re FORCE