# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 12:00:30 by jpirzent          #+#    #+#              #
#    Updated: 2018/09/06 14:23:38 by jpirzent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = ft_ls

# PATHS #
SRC_PATH = ./src/
OBJ_PATH = ./objs/
INC_PATH = ./inc/
LIB_PATH = ./libft/
PRF_PATH = ./ft_printf/


# FILES #
SRC_FILES = flags.c\
			ft_addlink.c\
			main.c\
			print.c\
			sort_t.c\
			lstfree.c\
			sortlink.c\
			ft_rights.c\
			ft_format_t.c\
			ft_count.c\

OBJ_FILES = $(SRC_FILES:%.c=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))


# COMPILE #
CCFLAGS = -Wall -Werror -Wextra
CC = gcc $(CCFLAGS)

LIBF = $(LIB_PATH)libft.a
PRF = $(PRF_PATH)libftprintf.a

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@make -C $(PRF_PATH)
	@$(CC) -o $@ $(LIBF) $(PRF) $(OBJ)
	@echo "\033[92m"---COMPILED SUCCESFULLY---"\033[0m"


# MAKE COMMANDS #
all: temp $(NAME)

temp:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -I $(INC_PATH) -o $@ -c $<
	@echo "\x1b[31m"MAKING"\x1b[0m" $@

clean:
	@/bin/rm -rf $(OBJ)
	@echo "\x1b[31m"CLEANING"\x1b[0m" ./objs/

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\x1b[31m"REMOVING"\x1b[0m" $(NAME)

cleanlib:
	@make clean -C $(LIB_PATH)
	@make clean -C $(PRF_PATH)
	@echo "\x1b[31m"CLEANING"\x1b[0m" ./libft/

fcleanlib: cleanlib
	@make fclean -C $(LIB_PATH)
	@make fclean -C $(PRF_PATH)
	@echo "\x1b[31m"REMOVING"\x1b[0m" libft.a

re: fclean fcleanlib all

.PHONY: re clean fclean all
