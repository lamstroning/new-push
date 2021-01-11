# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: -tdontos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 12:58:40 by tdontos-          #+#    #+#              #
#    Updated: 2019/05/29 15:37:44 by tdontos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	main.c linked_list.c sort_list.c sort_list.c


SRCDIR	= ./srcs
OBJDIR	= ./obj

CC	=	gcc -o
OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
# OBJ	= $(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

NAME	= 	push_swap

FTDIR	= libft
FT_INC	= -I $(FTDIR)
FT_LIB	= $(addprefix $(FTDIR)/,libft.a)
FT_LNK	= -L $(FTDIR) -lft

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(FT_INC) -o $@ -c $<

$(NAME): $(OBJ)
	make -C $(FTDIR)
	$(CC) $(OBJ) $(FT_LNK) $(PFT_LNK) -o $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJDIR)

fclean:	clean
	make fclean -C libft
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean
