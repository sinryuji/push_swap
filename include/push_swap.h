/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:21:01 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/07 19:29:28 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				data;
	struct s_stack 	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pivots
{
	int	pivot1;
	int	pivot2;
}	t_pivots;

/* data_validation */
void	integer_validation(int argc, char **argv);
void	duplication_validation(t_stack *top);

/* stack.c */
void	init_stack(t_stack **top, int argc, char **argv);
void	push(t_stack **top, int data);
int		pop(t_stack **top);
void	print_stack(t_stack *top);
void	print_state(t_stack *a, t_stack *b);

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

/* linked_list.c */
t_stack	*get_last_node(t_stack *top);
int		get_list_length(t_stack *top);
t_stack	*get_index_node(t_stack *top, int i);
int	get_node_index(t_stack *current, t_stack *top);

/* quick_sort.c */
void	quick_sort(t_stack *top, int left, int right);
int		partition(t_stack *top, int left, int right);

/* stack_util.c */
int			check_acending_sort(t_stack *top);
int			check_decending_sort(t_stack *top);
t_stack		*get_min_node(t_stack *top);
t_stack		*get_max_node(t_stack *top);
t_pivots	get_pivots(t_stack *top);
t_pivots	get_pivots_range(t_stack *top, int r);

/* selection_sort.c */
void	selection_sort(t_stack **a, t_stack **b);
int		move_b(t_stack **a, t_stack **b, t_stack *node, int index);

/* stack_util2.c */
t_stack *stack_copy(t_stack *top);
void	stack_free(t_stack *top);

/* quick_sort_apply.c */
void	a_to_b(t_stack **a, t_stack **b, int r);
void	b_to_a(t_stack **a, t_stack **b, int r);

#endif
