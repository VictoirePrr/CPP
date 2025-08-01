# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 15:49:14 by victoire          #+#    #+#              #
#    Updated: 2025/08/01 14:50:31 by victoire         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME        = ClapTrap
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
SRC         = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
INCLUDES    = -Iinclude

OBJ_DIR     = obj
OBJ         = $(SRC:.cpp=.o)
OBJ         := $(addprefix $(OBJ_DIR)/, $(notdir $(OBJ)))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
