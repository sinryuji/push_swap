/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourglass_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:10:43 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/10 18:33:51 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	hourglass_sort(t_stack **a, t_stack **b)
{
	int	x;
	int	chunk;

	x = get_list_length(*a);
	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	hg_a_to_b(a, b, chunk);
	hg_b_to_a(a, b);
}

void	hg_a_to_b(t_stack **a, t_stack **b, int chunk)
{
	int	i;
	int	len;

	i = 0;
	len = get_list_length(*a);
	while (len)
	{
		if ((*a)->data <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->data > i && (*a)->data <= i + chunk)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->data > i + chunk)
		{
//			if (i < len / 2 && i >= 0)
//				rra(a);
//			else
				ra(a);
		}
		len = get_list_length(*a);
//		print_state(*a, *b);
	}
}

void	hg_b_to_a(t_stack **a, t_stack **b)
{
	int	length;
	int	index;

	length = get_list_length(*b);
	while (length)
	{
		index = get_node_index(get_max_node(*b), *b);
		while (index)
		{
			if (index <= length / 2)
				rb(b);
			else if (index > length / 2)
				rrb(b);
			index = get_node_index(get_max_node(*b), *b);
		}
		pa(a, b);
		length = get_list_length(*b);
	}
}
