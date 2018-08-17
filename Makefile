# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 11:09:02 by jpirzent          #+#    #+#              #
#    Updated: 2018/08/17 16:34:01 by jpirzent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls 

FILES = flags.c\
		ft_addlink.c\
		main.c\
		print.c\
		sortlink.c\

OBJ = $(FILES:.c=.o)

LIBOBJ = ./libft/*.o

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc -Wall -Werror -Wextra -I. -c $(FILES)
	ar rcs $(NAME) $(OBJ) $(LIBOBJ)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAME)

cleanlib:
	make clean -C ./libft

fcleanlib:
	make fclean -C ./libft

cleanall: clean cleanlib

fcleanall: fclean fcleanlib

re: fcleanall all

ac: re cleanall

.PHONY: re fclean clean all


