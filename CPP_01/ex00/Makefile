# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 12:19:52 by vicperri          #+#    #+#              #
#    Updated: 2025/07/15 12:21:17 by vicperri         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= zombie
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
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
