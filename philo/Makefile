# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 16:01:19 by azgaoua           #+#    #+#              #
#    Updated: 2023/10/21 22:04:27 by azgaoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

OBJS = philosophers.o parss.o parss2.o parss3.o tools.o tools2.o

FILES = philosophers.c parss.c parss2.c parss3.c tools.c tools2.c

CC = cc

RM = rm -rf

FLGS = -Wall -Wextra -Werror

all :  $(NAME)

%.o: %.c philosophers.h
	$(CC) $(FLGS) -c $< -o $@

$(NAME) :  $(OBJS)
	@echo "------>making the PHILO<------"
	$(CC) $(FLGS) $(OBJS) -o $(NAME) -lpthread
	@echo "--------->PHILO Done<---------"

bonus :  $(BNS_NAME)

clean:
	@echo " clean all the *.o FILES"
	@$(RM) $(OBJS)

fclean:  clean
	@echo " clean --> $(NAME)"
	@$(RM) $(NAME)

re: fclean all