# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 21:17:27 by codespace         #+#    #+#              #
#    Updated: 2024/11/17 21:22:09 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ScalarConverter.cpp
HDRS = ScalarConverter.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re