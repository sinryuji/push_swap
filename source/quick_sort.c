/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:26:57 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/02 20:00:30 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"

void	swap(t_stack **a, t_stack **b, int x, int y)
{
	int	i;

	if (x == y)
		return ;
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
}

void	swap2(t_stack *x, t_stack *y)
{
	int tmp;

	tmp = x->data;
	x->data = y->data;
	y->data = tmp;
}

int	partition(t_stack *top, int left, int right)
{
	int	pivot;
	int	temp;
	int	low;
	int	high;

	pivot = get_index_node(top, left)->data;
	low = left + 1;
	high = right;

	while (low <= high)
	{
		while (low <= right && get_index_node(top, low)->data < pivot)
			low++;
		while (high >= left && get_index_node(top, high)->data > pivot)
			high--;
		if (high > low)
			swap2(get_index_node(top, low), get_index_node(top, high));
	}
	swap2(get_index_node(top, left), get_index_node(top, high));

	return (high);
}

void	quick_sort(t_stack *top, int left, int right)
{
	int	q;

	if (left < right)
	{
		q = partition(top, left, right);
		quick_sort(top, left, q - 1);
		quick_sort(top, q + 1, right);
	}
}
