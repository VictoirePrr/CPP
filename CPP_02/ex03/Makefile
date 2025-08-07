# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 15:31:28 by vicperri          #+#    #+#              #
#    Updated: 2025/08/07 10:44:27 by vicperri         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= Fixed
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -MMD
SRC		= main.cpp Fixed.cpp Point.cpp
INCLUDES = -Iinclude
OBJDIR   = build
OBJ      = $(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(OBJ:%.o=%.d)