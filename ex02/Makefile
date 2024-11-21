# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 16:09:52 by eviscont          #+#    #+#              #
#    Updated: 2024/11/21 17:23:16 by eviscont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify

CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Base.cpp
HDRS = Base.hpp A.hpp B.hpp C.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re