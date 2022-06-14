# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 15:11:40 by ajafy             #+#    #+#              #
#    Updated: 2022/05/24 19:00:05 by ajafy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c so_long_utils.c so_long_utils1.c so_long_utils2.c so_long_utils3.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libftutils.c

SRC_BONUS = so_long_bonus.c so_long_bonus_utils.c so_long_bonus_utils1.c so_long_bonus_utils2.c so_long_bonus_utils3.c so_long_bonus_utils4.c so_long_bonus_animation.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libftutils.c

CC = gcc

SO_LONG = so_long

SO_LONG_BONUS = so_long_bonus

PRINTF = printf/libftprintf.a

DIR_PRINTF = printf/

GET_NEXT_LINE = get_next_line/get_next_line.a

DIR_GET_NEXT_LINE = get_next_line/

CFLAGS = -Wall -Wextra -Werror

NAME = so_long.a

HEADER = so_long.h

NAME_BONUS= so_long_bonus.a

HEADER_BONUS = so_long_bonus.h

all : $(SO_LONG) $(NAME)


$(SO_LONG): $(SRC) $(PRINTF) $(HEADER)
	 $(CC) $(CFLAG) $(SRC) $(PRINTF) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(SO_LONG)

$(PRINTF):
	$(MAKE) -C $(DIR_PRINTF)

$(NAME) : $(SRC) $(HEADER)
	ar -rc $(NAME) $(SRC)

clean :
	rm -f $(SO_LONG) 
	rm -f $(SO_LONG_BONUS) 
	
fclean : clean
	$(MAKE) fclean -C $(DIR_PRINTF)
	rm -f $(NAME)
	rm -f $(NAME_BONUS) 

bonus : $(SO_LONG_BONUS) $(NAME_BONUS)

$(SO_LONG_BONUS): $(SRC_BONUS) $(PRINTF) $(HEADER_BONUS)
	 $(CC) $(CFLAG) $(SRC_BONUS) $(PRINTF) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(SO_LONG_BONUS)

$(NAME_BONUS) : $(SRC_BONUS) $(HEADER_BONUS)
	ar -rc $(NAME_BONUS) $(SRC_BONUS)	
	

re : fclean all
