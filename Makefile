# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agallet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 17:59:42 by agallet           #+#    #+#              #
#    Updated: 2023/05/17 14:09:35 by agallet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRCS = pipex.c parse_cmds.c parse_path.c pipex_utils.c childs_process.c pipex_utils2.c $(GNL)
OBJS = $(SRCS:.c=.o)
INCLUDES = -I ./libft -I ./libft/ft_printf -I ./get_next_line
LIBS = -L ./libft -lft
NAME = pipex

%.o : %.c
	$(CC) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS) ./libft/libft.a
	$(CC) $(CFLAGS) $(LIBS) -o $(NAME) $(OBJS)

all : $(NAME)

./libft/libft.a :
	make -C libft

clean :
	rm -f $(OBJS)
	make clean -C libft

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re
