/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:56:42 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/30 20:11:27 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	min_move_b(t_stack **a, t_stack **b)
{
	t_stack *min_node;
	int		min_index;

	min_node = get_min_node(*a);
	min_index = get_node_index(min_node, *a);
	while (min_index)
	{
		if (min_index <= get_list_length(*a) / 2)
			ra(a);
		else
			rra(a);
		if (check_sort(*a))
			return ;
		min_index = get_node_index(min_node, *a);
	}
	pb(a, b);
}

void	selection_sort(t_stack **a, t_stack **b)
{
	while (!check_sort(*a))
	{
		min_move_b(a, b);
		if ((*a)->next->next)
			if (((*a)->data > (*a)->next->data))
				if ((*a)->data < (*a)->next->next->data)
					sa(a);
	}
	while (*b)
		pa(a, b);
}
