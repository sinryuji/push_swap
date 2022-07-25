/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:21:01 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/25 20:31:26 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/include/ft_printf.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

/* data_validation */
void	integer_validation(int argc, char **argv);
void	duplication_validation(t_stack *top);

/* stack.c */
void	stack_init(t_stack **top, int argc, char **argv);
void	stack_push(t_stack **top, int data);
int		stack_pop(t_stack **top);
void	print_stack(t_stack *top);

#endif
