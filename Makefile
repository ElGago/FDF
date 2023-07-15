# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 09:27:34 by jocorrea          #+#    #+#              #
#    Updated: 2023/06/28 09:28:35 by jocorrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	

OBJS = $(SRCS:.c=.o)

BONUS =	

BONUS_OBJS = $(BONUS:.c=.o)

AR = ar rcs

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -MMD

INCLUDE = -I libft.h

NAME = libft.a

DEPS= $(OBJS:.o=.d)

DEPS_BONUS= $(BONUS_OBJS:.o=.d)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
-include $(DEPS)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS) $(DEPS) $(DEPS_BONUS)
	

fclean: clean
	@$(RM) $(NAME) $(OBJS) $(BONUS_OBJS) $(DEPS) $(DEPS_BONUS)
	

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
-include $(DEPS_BONUS)

.PHONY: all clean fclean re bonus