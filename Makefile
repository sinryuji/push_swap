# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 18:10:52 by hyeongki          #+#    #+#              #
#    Updated: 2022/09/09 21:03:04 by hyeongki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_PATH = ./source/mandatory/
SRCS_NAME = push_swap.c data_validation.c stack.c push.c swap.c rotate.c reverse_rotate.c linked_list.c merge_sort.c \
			merge_01.c merge_02.c get_info.c triangle_a.c triangle_b.c small_case.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)
BONUS_PATH = ./source/bonus/
BONUS_SRCS_NAME = checker_bonus.c data_validation_bonus.c stack_bonus.c push_bonus.c swap_bonus.c rotate_bonus.c reverse_rotate_bonus.c
BONUS_SRCS = $(addprefix $(BONUS_PATH), $(BONUS_SRCS_NAME))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -rf
AR = ar rcs
NAME = push_swap
BONUS = checker
FT_PRINTF_PATH = ./lib/ft_printf/
FT_PRINTF = libftprintf.a

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) :  $(OBJS)
	make -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $^ $(FT_PRINTF_PATH)$(FT_PRINTF) -o $@

$(BONUS) :  $(BONUS_OBJS)
	make -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $^ $(FT_PRINTF_PATH)$(FT_PRINTF) -o $@

bonus : $(BONUS)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS) 
	make -C $(FT_PRINTF_PATH) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(FT_PRINTF_PATH) fclean

re : fclean all

.PHONY :
	all clean fclean re bonus
