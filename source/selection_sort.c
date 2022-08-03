/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:56:42 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/03 16:51:28 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/include/ft_printf.h"

void	move_b(t_stack **a, t_stack **b, t_stack *node, int index, int *cnt)
{
	while (index)
	{
		if (index <= get_list_length(*a) / 2)
			ra(a);
		else
			rra(a);
		if (check_sort(*a))
			return ;
		index = get_node_index(node, *a);
	}
	pb(a, b);
	(*cnt)++;
}

void	move_a(t_stack **a, t_stack **b, t_stack *node, int index)
{
	while (index)
	{
		if (index <= get_list_length(*b) / 2)
			rb(b);
		else
			rrb(b);
		if (check_decending_sort(*b))
			return ;
		index = get_node_index(node, *b);
	}
	pa(a, b);
}

void	selection_sort(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int	pivot;
	int	*cnt;

	if (check_sort(*a))
		return ;
	pivot = get_mid_value(*a);
	tmp = *a;
	while (tmp)
	{
		if (tmp->data < pivot)
		{
			move_b(a, b, tmp, get_node_index(tmp, *a), cnt);
//			print_state(*a, *b);
			tmp = *a;
		}
		else
			tmp = tmp->next;
	}
//	print_state(*a, *b);
	*cnt = 0;
	while (!check_sort(*a))
	{
		move_b(a, b, get_min_node(*a), get_node_index(get_min_node(*a), *a), cnt);
		if ((*a)->next->next)
			if (((*a)->data > (*a)->next->data))
				if ((*a)->data < (*a)->next->next->data)
					sa(a);
	}
//	ft_printf("cnt : %d\n", *cnt);
//	print_state(*a, *b);
	while ((*cnt)--)
		pa(a, b);
//	ft_printf("here\n");
//	print_state(*a, *b);
	while (!check_decending_sort(*b))
	{
		move_a(a, b, get_max_node(*b), get_node_index(get_max_node(*b), *b));
//	print_state(*a, *b);
		if ((*b)->next->next)
			if (((*b)->data > (*b)->next->data))
				if ((*b)->data < (*b)->next->next->data)
					sb(b);
	}
	while (*b)
		pa(a, b);
//	print_state(*a, *b);
}
