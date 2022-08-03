/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:56:42 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/03 18:29:12 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/include/ft_printf.h"

int	move_b(t_stack **a, t_stack **b, t_stack *node, int index)
{
	while (index)
	{
		if (index <= get_list_length(*a) / 2)
			ra(a);
		else
			rra(a);
		if (check_acending_sort(*a))
			return (0);
		index = get_node_index(node, *a);
	}
	pb(a, b);
	return (1);
}

int	move_a(t_stack **a, t_stack **b, t_stack *node, int index)
{
	while (index)
	{
		if (index <= get_list_length(*b) / 2)
			rb(b);
		else
			rrb(b);
		if (check_decending_sort(*b))
			return (0);
		index = get_node_index(node, *b);
	}
	pa(a, b);
	return (1);
}

void	sort_acending(t_stack **a, t_stack **b)
{
	int	cnt;

	cnt = 0;
	while (!check_acending_sort(*a))
	{
		cnt += move_b(a, b, get_min_node(*a), get_node_index(get_min_node(*a), *a));
		if ((*a)->next->next)
			if (((*a)->data > (*a)->next->data))
				if ((*a)->data < (*a)->next->next->data)
					sa(a);
	}
	while (cnt--)
		pa(a, b);
}

void	sort_decending(t_stack **a, t_stack **b)
{
	int	cnt;

	cnt = 0;
	while (!check_decending_sort(*b))
	{
		cnt += move_a(a, b, get_max_node(*b), get_node_index(get_max_node(*b), *b));
		if ((*b)->next->next)
			if (((*b)->data > (*b)->next->data))
				if ((*b)->data < (*b)->next->next->data)
					sb(b);
	}
	while (cnt--)
		pb(a, b);
}

void	pivot_less_move(t_stack **a, t_stack **b, int pivot)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->data < pivot)
		{
			move_b(a, b, tmp, get_node_index(tmp, *a));
			tmp = *a;
		}
		else
			tmp = tmp->next;
	}
}

void	selection_sort(t_stack **a, t_stack **b)
{
	t_pivots	ps;

	if (check_acending_sort(*a))
		return ;
	ps = get_pivots(*a);
	pivot_less_move(a, b, ps.pivot1);
	sort_decending(a, b);
	pivot_less_move(a, b, ps.pivot2);
	sort_decending(a, b);
	sort_acending(a, b);
	while (*b)
		pa(a, b);
}
