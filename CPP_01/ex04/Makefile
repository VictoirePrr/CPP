# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 11:16:43 by vicperri          #+#    #+#              #
#    Updated: 2025/07/23 12:08:52 by vicperri         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= replace
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Replace.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re