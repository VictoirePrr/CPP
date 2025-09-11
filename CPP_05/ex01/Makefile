# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 15:49:14 by victoire          #+#    #+#              #
#    Updated: 2025/09/11 11:55:52 by victoire         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME        = Form
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -Wshadow -std=c++98 -MMD
SRCDIR      = src
SRC         = main.cpp Bureaucrat.cpp Form.cpp

SRCS        = $(addprefix $(SRCDIR)/, $(SRC))

INCLUDES = -Iinclude

OBJDIR   = build
OBJ      = $(SRC:%.cpp=$(OBJDIR)/%.o)

INCLUDES    = -Iinclude

OBJDIR      = build
OBJ         = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(OBJ:%.o=%.d)
