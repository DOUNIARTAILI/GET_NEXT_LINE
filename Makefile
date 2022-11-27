# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 01:20:33 by drtaili           #+#    #+#              #
#    Updated: 2022/11/27 01:53:49 by drtaili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRC = get_next_line.c get_next_line_utils.c

OBJS = ${SRC:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)

%.o : %.c get_next_line.h
	$(CC) $(FLAGS) $> -o $@

clean : 
	$(RM) $(OBJS) 
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re 