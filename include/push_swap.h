/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:21:01 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/28 21:03:22 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/ft_printf/lib//libft/include/libft.h"

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

typedef struct s_size
{
	int	a_top;
	int a_bot;
	int	b_top;
	int	b_bot;
}	t_size;

typedef struct	s_function_chain
{
	int	(*make_triangle)(t_stack **, t_stack **, int);
	struct s_function_chain	*next;
	struct s_function_chain	*prev;
}	t_fc;

typedef	struct	s_info
{
	int	depth;
	int	n;
	int	pow;
}	t_info;

typedef	struct	s_stacks
{
	t_stack **a;
	t_stack **b;
}	t_stacks;

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
int	pa(t_stack **a, t_stack **b);
int	pb(t_stack **a, t_stack **b);

/* swap.c */
int	sa(t_stack **a);
int	sb(t_stack **b);
int	ss(t_stack **a, t_stack **b);

/* rotate.c */
int	ra(t_stack **a);
int	rb(t_stack **b);
int	rr(t_stack **a, t_stack **b);

/* reverse_rotate.c */
int	rra(t_stack **a);
int	rrb(t_stack **b);
int	rrr(t_stack **a, t_stack **b);

/* linked_list.c */
t_stack	*get_last_node(t_stack *top);
int		get_list_length(t_stack *top);
t_stack	*get_index_node(t_stack *top, int i);
int	get_node_index(t_stack *current, t_stack *top);
int	get_value_index(int data, t_stack *top);

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
void	stack_free(t_stack **top);

/* quick_sort_apply.c */
void	quick_a_to_b(t_stack **a, t_stack **b, int r);
void	quick_b_to_a(t_stack **a, t_stack **b, int r);

/* escape_range3.c */
int	escape_a_to_b(t_stack **a, int r);
int	escape_b_to_a(t_stack **a, t_stack **b, int r);

/* escape_range3_a.c */
void	escape_a_201(t_stack **a);
void	escape_a_120(t_stack **a);
void	escape_a_210(t_stack **a);

/* escape_range3_b.c */
void	escape_b_012(t_stack **a, t_stack **b);
void	escape_b_021(t_stack **a, t_stack **b);
void	escape_b_102(t_stack **a, t_stack **b);
void	escape_b_120(t_stack **a, t_stack **b);
void	escape_b_201(t_stack **a, t_stack **b);

/* indexing.c */
void	indexing(t_stack **a);

/* hourglass_sort.c */
void	hourglass_sort(t_stack **a, t_stack **b);
void	hg_a_to_b(t_stack **a, t_stack **b, int chunk);
void	hg_b_to_a(t_stack **a, t_stack **b);

/* merge_sort.c */
void	merge_sort(t_stack **a, t_stack **b);
int		get_size(int pow, int i, int n);

/* triangle.c */
int		ascending_triangle_a(t_stack **a, t_stack **b, int n);
int		descending_triangle_a(t_stack **a, t_stack **b, int n);
int		ascending_triangle_b(t_stack **a, t_stack **b, int n);
int		descending_triangle_b(t_stack **a, t_stack **b, int n);

#endif
