/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_range3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:19:28 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/08 19:18:15 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	escape_case_a_to_b(t_stack **a)
{
	int	arr[3];

	arr[0] = (*a)->data;
	arr[1] = (*a)->next->data;
	arr[2] = (*a)->next->next->data;

	if (arr[0] < arr[2] && arr[2] < arr[1])
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		sa(a);
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		escape_a_120(a);
	else if (arr[1] < arr[2] && arr[2] < arr[0])
		escape_a_201(a);
	else if (arr[2] < arr[1] && arr[1] < arr[0])
		escape_a_210(a);
	return (1);
}

int	escape_case_b_to_a(t_stack **a, t_stack **b)
{
	int	arr[3];

	arr[0] = (*b)->data;
	arr[1] = (*b)->next->data;
	arr[2] = (*b)->next->next->data;

	if (arr[0] < arr[1] && arr[1] < arr[2])
		escape_b_012(a, b);
	else if (arr[0] < arr[2] && arr[2] < arr[1])
		escape_b_021(a, b);
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		escape_b_102(a, b);
	else if (arr[1] < arr[2] && arr[2] < arr[0])
		escape_b_201(a, b);
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		escape_b_120(a, b);
	else if (arr[2] < arr[1] && arr[1] < arr[0])
	{
		pa(a, b);
		pa(a, b);
		pa(a, b);
	}

	return (1);
}

int	escape_a_to_b(t_stack **a, int r)
{
	if (r <= 1)
		return (1);
	else if (r == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
		return (1);
	}
	else if (r == 3)
		return (escape_case_a_to_b(a));
	return (0);
}

int	escape_b_to_a(t_stack **a, t_stack **b, int r)
{
	if (r <= 1)
		return (1);
	else if (r == 2)
	{
		if ((*b)->data < (*b)->next->data)
			sb(b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	else if (r == 3)
		return (escape_case_b_to_a(a, b));
	return (0);
}
