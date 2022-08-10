# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 18:10:52 by hyeongki          #+#    #+#              #
#    Updated: 2022/08/09 19:29:36 by hyeongki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_PATH = ./source/
SRCS_NAME = push_swap.c data_validation.c stack.c push.c swap.c rotate.c reverse_rotate.c \
			linked_list.c quick_sort.c stack_util.c selection_sort.c stack_util2.c quick_sort_apply.c \
			escape_range3.c escape_range3_a.c escape_range3_b.c indexing.c hourglass_sort.c merge_sort.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)
BONUS_PATH = 
BONUS_SRCS_NAME = 
BONUS_SRCS = $(addprefix $(BONUS_PATH), $(BONUS_SRCS_NAME))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -rf
AR = ar rcs
NAME = push_swap
FT_PRINTF_PATH = ./lib/ft_printf/
FT_PRINTF = libftprintf.a

ifdef BONUS_FLAG
else
endif

%.o : %.c
	$(CC) $(CFALGS) -c $< -o $@

all : $(NAME)

$(NAME) :  $(OBJS)
	make -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $^ $(FT_PRINTF_PATH)$(FT_PRINTF) -o $@

bonus :
	$(MAKE) BONUS_FLAG=1 all

clean :
	$(RM) $(OBJS) 
	make -C $(FT_PRINTF_PATH) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(FT_PRINTF_PATH) fclean

re : fclean all

.PHONY :
	all clean fclean re
