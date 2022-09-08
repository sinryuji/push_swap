/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:21:01 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/08 11:03:44 by hyeongki         ###   ########.fr       */
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

typedef	struct	s_info
{
	int	depth;
	int	n;
	int	pow;
}	t_info;

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

/* stack_util.c */
int			check_acending_sort(t_stack *top);
int			check_decending_sort(t_stack *top);
t_stack		*get_min_node(t_stack *top);
t_stack		*get_max_node(t_stack *top);

/* stack_util2.c */
t_stack *stack_copy(t_stack *top);
void	stack_free(t_stack **top);

/* merge_sort.c */
void	merge_sort(t_stack **a, t_stack **b);
int		get_size(int pow, int i, int n);

/* triangle_a.c */
int		make_triangle_a(t_stack **a, t_stack **b, int size, int ascending);

/* triangle_b.c */
int		make_triangle_b(t_stack **a, t_stack **b, int size, int ascending);

#endif
