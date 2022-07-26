/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:21:01 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 20:21:45 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

/* data_validation */
void	integer_validation(int argc, char **argv);
void	duplication_validation(t_stack *top);

/* stack.c */
void	init_stack(t_stack **top, int argc, char **argv);
void	push(t_stack **top, int data);
int		pop(t_stack **top);
t_stack	*get_last_node(t_stack *top);
t_stack	*get_last_previous_node(t_stack *top);

/* push.c */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* swap.c */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* rotate.c */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* reverse_rotate.c */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
#endif
