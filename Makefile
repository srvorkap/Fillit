# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 00:34:41 by srvorkap          #+#    #+#              #
#    Updated: 2019/11/17 00:38:31 by srvorkap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Werror -Wextra

NAME	= fillit
HEAD	= fillit.h
SRCS	= 
all: $(NAME) 

clean:
	@rm

fclean: clean
	@rm

re: fclean all
