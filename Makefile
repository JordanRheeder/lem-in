# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 09:03:24 by rengelbr          #+#    #+#              #
#    Updated: 2020/05/09 11:22:35 by rengelbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
MAKELIB = -C libft
LIB = libft/libft.a
FLGS = -Wall -Werror -Wextra
DBFLG = -Wall -Werror -Wextra -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable -fsanitize=address -fno-omit-frame-pointer -g
SRC = lem-in.c \
	$(LIB) \
	src/*.c \
	src/algo.c

all: $(MAKELIB) $(NAME)

$(MAKELIB):
	@$(MAKE) $(MAKELIB)

$(NAME):
	gcc $(SRC) libft/libft.a -o $(NAME)

db:
	gcc $(DBFLG) $(SRC) libft/libft.a -o $(NAME)

clean:
	rm -f libft/*.o

fclean: clean
	rm -f libft/libft.a
	rm -fr $(NAME) $(NAME).dSYM

re: fclean all clean

redb: clean db
