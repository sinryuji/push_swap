/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:29:05 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/17 19:27:46 by hyeongki         ###   ########.fr       */
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
	int	size;
	int	tmp;

	i = n / 3;
	size = n;
	tmp = depth;
	while (tmp--)
		size /= 3;
	while (i--)
		pb(a, b);
	ascending = get_ascending(*a);
	i = 1;
	while (--depth)
		i *= 3;
	while (i--)
	{
		ts.a_top = size;
		ts.a_bot = size;
		ts.b_bot = size;
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
	int	size;
	int	tmp;

	i = n / 3;
	size = n;
	tmp = depth;
	while (i--)
		pa(a, b);
	while (tmp--)
		size /= 3;
	ascending = get_ascending(*b);
	i = 1;
	while (--depth)
		i *= 3;
	while (i--)
	{
		ts.a_bot = size;
		ts.b_top = size;
		ts.b_bot = size;
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

void	make_triangle(t_fc **fc, t_info info, int ascending)
{
	t_fc	*new;

	new = (t_fc *)malloc(sizeof(t_fc));
	if (info.depth % 2 == 0)
	{
		if (ascending)
			new->make_triangle = ascending_triangle_a;
		else
			new->make_triangle = descending_triangle_a;
	}
	else
	{
		if (ascending)
			new->make_triangle = ascending_triangle_b;
		else
			new->make_triangle = descending_triangle_b;
	}
	new->next = *fc;
	new->prev = NULL;
	if (*fc)
		(*fc)->prev = new;
	*fc = new;
}

void	division(t_stacks stacks, t_fc **fc, t_info info, int ascending)
{
	if (info.depth > 0)
	{
		info.depth--;
		if	(ascending)
		{
			division(stacks, fc, info, 0);
			division(stacks, fc, info, 0);
			division(stacks, fc, info, 1);
		}
		else
		{
			division(stacks, fc, info, 0);
			division(stacks, fc, info, 1);
			division(stacks, fc, info, 1);
		}
	}
	else
	{
		info.depth = get_depth(*(stacks.a), info.n);
		info.n--;
		make_triangle(fc, info, ascending);
	}

}

void	do_division(t_stacks stacks, t_fc *fc, t_info info)
{
	if (info.depth % 2 == 1)
	{
		while (fc)
		{
			fc->make_triangle(stacks.a, stacks.b, info.n);
			fc = fc->next;
		}
	}
	else
	{
		while (fc->next)
			fc = fc->next;
		while (fc)
		{
			fc->make_triangle(stacks.a, stacks.b, info.n);
			fc = fc->prev;
		}
	}
}

void	merge_sort(t_stack **a, t_stack **b)
{
	t_fc	*fc;
	t_info	info;
	t_stacks	stacks;
	int	cnt = 1;

	fc = NULL;
	stacks.a = a;
	stacks.b = b;
	info.n = get_list_length(*a);
	info.depth = get_depth(*a, info.n);
	division(stacks, &fc, info, 1);
	do_division(stacks, fc, info);
	merge(a, b, info.depth, info.n);
}
