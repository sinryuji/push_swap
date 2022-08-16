/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:29:05 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/16 19:08:47 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_depth(t_stack *a, int n)
{
	int	depth;

	depth = 0;
	while (n > 3)
	{
		n /= 3;
		depth++;
	}

	return (depth);
}

void	make_triangle_a(t_stack **a, t_stack **b, int (*fp)(t_stack, t_stack, int))
{

}
void	make_triangle(t_stack **a, t_stack **b, int depth, int n, int ascending)
{
	if (depth % 2 == 0)
	{
		if (ascending)
			ascending_triangle_a(a, b, n);
		else
			descending_triangle_a(a, b, n);
	}
	else
	{
		if (ascending)
			ascending_triangle_b(a, b, n);
		else
			descending_triangle_b(a, b, n);
		rb(b);
		rb(b);
		rb(b);
	}
}

int	ft_pow(int x, int y)
{
	int	pow;

	pow = 1;
	while (y--)
		pow *= 3;
	return (pow);
}

void	merge_ascending_a_to_b(t_stack **a, t_stack **b, t_size ts)
{
	while (ts.a_top + ts.a_bot + ts.b_bot)
	{
		if (ts.a_top && (!ts.a_bot || (*a)->data > get_last_node(*a)->data)
			&& (!ts.b_bot || (*a)->data > get_last_node(*b)->data))
			ts.a_top -= pb(a, b);
		else if (ts.a_bot && (!ts.a_top || get_last_node(*a)->data > (*a)->data)
			&& (!ts.b_bot || get_last_node(*a)->data > get_last_node(*b)->data))
		{
			rra(a);
			ts.a_bot -= pb(a, b);
		}
		else if (ts.b_bot && (!ts.a_top || get_last_node(*b)->data > (*a)->data)
			&& (!ts.a_bot || get_last_node(*b)->data > get_last_node(*a)->data))
			ts.b_bot -= rrb(b);
	}
}

void	merge_descending_a_to_b(t_stack **a, t_stack **b, t_size ts)
{
	while (ts.a_top + ts.a_bot + ts.b_bot)
	{
		if (ts.a_top && (!ts.a_bot || (*a)->data < get_last_node(*a)->data)
			&& (!ts.b_bot || (*a)->data < get_last_node(*b)->data))
			ts.a_top -= pb(a, b);
		else if (ts.a_bot && (!ts.a_top || get_last_node(*a)->data < (*a)->data)
			&& (!ts.b_bot || get_last_node(*a)->data < get_last_node(*b)->data))
		{
			rra(a);
			ts.a_bot -= pb(a, b);
		}
		else if (ts.b_bot && (!ts.a_top || get_last_node(*b)->data < (*a)->data)
			&& (!ts.a_bot || get_last_node(*b)->data < get_last_node(*a)->data))
			ts.b_bot -= rrb(b);
	}
}

void	merge_ascending_b_to_a(t_stack **a, t_stack **b, t_size ts)
{
	while (ts.a_bot + ts.b_top + ts.b_bot)
	{
		if (ts.b_top && (!ts.b_bot || (*b)->data > get_last_node(*b)->data)
			&& (!ts.a_bot || (*b)->data > get_last_node(*a)->data))
			ts.b_top -= pa(a, b);
		else if (ts.b_bot && (!ts.b_top || get_last_node(*b)->data > (*b)->data)
			&& (!ts.a_bot || get_last_node(*b)->data > get_last_node(*a)->data))
		{
			rrb(b);
			ts.b_bot -= pa(a, b);
		}
		else if (ts.a_bot && (!ts.b_top || get_last_node(*a)->data > (*b)->data)
			&& (!ts.b_bot || get_last_node(*a)->data > get_last_node(*b)->data))
			ts.a_bot -= rra(a);
	}
}

void	merge_descending_b_to_a(t_stack **a, t_stack **b, t_size ts)
{
	while (ts.a_bot + ts.b_top + ts.b_bot)
	{
		if (ts.b_top && (!ts.b_bot || (*b)->data < get_last_node(*b)->data)
			&& (!ts.a_bot || (*b)->data < get_last_node(*a)->data))
			ts.b_top -= pa(a, b);
		else if (ts.b_bot && (!ts.b_top || get_last_node(*b)->data < (*b)->data)
			&& (!ts.a_bot || get_last_node(*b)->data < get_last_node(*a)->data))
		{
			rrb(b);
			ts.b_bot -= pa(a, b);
		}
		else if (ts.a_bot && (!ts.b_top || get_last_node(*a)->data < (*b)->data)
			&& (!ts.b_bot || get_last_node(*a)->data < get_last_node(*b)->data))
			ts.a_bot -= rra(a);
	}
}

int	get_ascending(t_stack *top)
{
	if (!top)
		return (0);
	if(top->data > top->next->data)
		return (1);
	return (0);
}

void	merge_a_to_b(t_stack **a, t_stack **b, int depth, int n)
{
	int	i;
	int	ascending;
	t_size	ts;

	i = n / 3;
	while (i--)
		pb(a, b);
	ascending = get_ascending(*a);
	i = 3;
	while (i--)
	{
		ts.a_top = 3;
		ts.a_bot = 3;
		ts.b_bot = 3;
		if (ascending)
			merge_ascending_a_to_b(a, b, ts);
		else
			merge_descending_a_to_b(a, b, ts);
		ascending = get_ascending(*a);
	}
}

void	merge_b_to_a(t_stack **a, t_stack **b, int depth, int n)
{
	int	i;
	int	ascending;
	t_size	ts;

	i = n / 3;
	while (i--)
		pa(a, b);
	ascending = get_ascending(*b);
	i = 1;
	while (i--)
	{
		ts.a_bot = 9;
		ts.b_top = 9;
		ts.b_bot = 9;
		if (ascending)
			merge_ascending_b_to_a(a, b, ts);
		else
			merge_descending_b_to_a(a, b, ts);
		ascending = get_ascending(*b);
	}
}

void	merge(t_stack **a, t_stack **b, int depth, int n)
{
	if (depth % 2 == 0)
		merge_a_to_b(a, b, depth, n);
	else
		merge_b_to_a(a, b, depth, n);
	if (depth > 1)
		merge(a, b, depth - 1, n);
}

void	division(t_stack **a, t_stack **b, int depth, int n, int ascending)
{
	int	d;

	if (depth > 0)
	{
		if	(ascending)
		{
			division(a, b, depth - 1, n, 0);
			division(a, b, depth - 1, n, 0);
			division(a, b, depth - 1, n, 1);
		}
		else
		{
			division(a, b, depth - 1, n, 0);
			division(a, b, depth - 1, n, 1);
			division(a, b, depth - 1, n, 1);
		}
	}
	else
	{
		d = get_depth(*a, n);
		make_triangle(a, b, d, n - 1, ascending);
	}


}

void	merge_sort(t_stack **a, t_stack **b)
{
	int	n;
	int	depth;

	n = get_list_length(*a);
	depth = get_depth(*a, n);
	division(a, b, depth, n, 1);
	merge(a, b, depth, n);
}
