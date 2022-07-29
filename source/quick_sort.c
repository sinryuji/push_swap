/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:26:57 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/29 19:19:50 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **a, t_stack **b, int x, int y)
{
	int	i;

	i = 0;
	while (x - i++)
		pb(a, b);
	ra(a);
	i = 1;
	while (y - x - i++)
		pb(a, b);
	rra(a);
	sa(a);
	ra(a);
	i = 1;
	while (y - x - i++)
		pa(a, b);
	rra(a);
	i = 0;
	while (x - i++)
		pa(a, b);
	print_state(*a, *b);
}

int	partition(t_stack **a, t_stack **b, int left, int right)
{
	int	pivot;
	int	temp;
	int	low;
	int	high;

	pivot = get_index_node(*a, left)->data;
	low = left + 1;
	high = right;

	while (low < high)
	{
		while (low <= right && get_index_node(*a, low)->data < pivot)
			low++;
		while (high >= left && get_index_node(*a, high)->data > pivot)
			high--;
		if (high > low)
			swap(a, b, low, high);
	}
	swap(a, b, left, high);

	return (high);
}

void	quick_sort(t_stack **a, t_stack **b, int left, int right)
{
	int	q;

	if (left < right)
	{
		q = partition(a, b, left, right);
		quick_sort(a, b, left, q - 1);
		quick_sort(a, b, q + 1, right);
	}
}
