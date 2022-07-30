/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:56:42 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/30 19:29:36 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	min_move_b(t_stack **a, t_stack **b)
{
	t_stack *min_node;
	int		min_index;
	int		a_length;

	min_node = get_min_node(*a);
	min_index = get_node_index(min_node, *a);
	while (min_index)
	{
		a_length = get_list_length(*a);
		if ((a_length / min_index) <= (a_length / 2))
			rra(a);
		else
			ra(a);
		min_index = get_node_index(min_node, *a);
	}
	pb(a, b);
}

void	selection_sort(t_stack **a, t_stack **b)
{
	while (!check_sort(*a))
		min_move_b(a, b);
	while (*b)
		pa(a, b);
}
