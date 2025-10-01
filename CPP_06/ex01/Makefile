# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 15:49:14 by victoire          #+#    #+#              #
#    Updated: 2025/10/01 18:24:05 by victoire         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME        = serialize
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -Wshadow -std=c++98 -MMD
SRCDIR      = src
SRC         = main.cpp \
              Serializer.cpp \

SRCS        = $(addprefix $(SRCDIR)/, $(SRC))

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
