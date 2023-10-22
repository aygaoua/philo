# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 16:01:19 by azgaoua           #+#    #+#              #
#    Updated: 2023/10/22 16:04:18 by azgaoua          ###   ########.fr        #
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
	@$(CC) $(FLGS) -c $< -o $@

$(NAME) :  $(OBJS)
	@echo " _____ _   _ _                 _        \n\
	|  _  | |_|_| |___ ___ ___ ___| |_ ___ ___ ___  \n\
	|   __|   | | | . |_ -| . | . |   | -_|  _|_ -|  \n\
	|__|  |_|_|_|_|___|___|___|  _|_|_|___|_| |___|   \n\
	                      	  |_|                      \n"
	@echo "------>making the PHILO<------"
	$(CC) $(FLGS) $(OBJS) -o $(NAME)
	@echo "--------->PHILO Done<---------"

bonus :  $(BNS_NAME)

clean:
	@echo " clean all the *.o FILES"
	@$(RM) $(OBJS)

fclean:  clean
	@echo " clean --> $(NAME)"
	@$(RM) $(NAME)

re: fclean all