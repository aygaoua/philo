# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 16:01:19 by azgaoua           #+#    #+#              #
#    Updated: 2023/10/09 14:26:15 by azgaoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
# BNS_NAME = fdf_bonus

OBJS = main.o parss.o parss2.o parss3.o
# BNSOBJS = fdf_bonus.o main_bonus.o maps_reader_bonus.o draw_things_bonus.o \
			rotation_bonus.o

FILES = main.c parss.c parss2.c parss3.c
# BNSFILES = fdf_bonus.c main_bonus.c maps_reader_bonus.c draw_things_bonus.c \
			rotation_bonus.c

CC = cc

RM = rm -rf

FLGS = -Wall -Wextra -Werror 

all :  $(NAME)

%.o: %.c philosophers.h
	@$(CC) $(FLGS) -c $< -o $@

$(NAME) :  $(OBJS)
	@echo "------>making the PHILO<------"
	$(CC) $(FLGS) $(OBJS) -o $(NAME)
	@echo "--------->PHILO Done<---------"

bonus :  $(BNS_NAME)

# $(BNS_NAME): $(BNSOBJS)
#	@echo "----->making the FDF_BONUS<-----"
#	@cd libft && make && make clean
#	@cd printo && make && make clean
#	@$(CC) $(FLGS) $(BNSOBJS) libft/libft.a printo/myprintf.a -lmlx -framework OpenGL -framework AppKit  -o $(BNS_NAME)
#	@echo "----->FDF_BONUS Done<-----"

clean:
	@echo " clean all this FILES if exist: $(OBJS)"
	@$(RM) $(OBJS)

fclean:  clean
	@echo "+ that --> $(NAME)"
	@$(RM) $(NAME)

re: fclean all