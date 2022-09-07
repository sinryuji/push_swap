/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:29:05 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/07 16:56:52 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_depth(t_stack *a, int n)
{
	int	depth;

	depth = 0;
	while (n > 4)
	{
		n = n / 3 + (n % 3 > 0);
		depth++;
	}

	return (depth);
}

void	merge_ascending_a_to_b(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_top;
	int	a_bot;
	int	b_bot;

	a_top = get_size(info.pow, info.pow / 3 + i, info.n);
	a_bot = get_size(info.pow, info.pow / 3 - 1 - i, info.n);
	b_bot = get_size(info.pow, info.pow * 2 / 3 + i, info.n);
	while (a_top + a_bot + b_bot)
	{
		if (a_top && (!a_bot || (*a)->data > get_last_node(*a)->data)
			&& (!b_bot || (*a)->data > get_last_node(*b)->data))
			a_top -= pb(a, b);
		else if (a_bot && (!a_top || get_last_node(*a)->data > (*a)->data)
			&& (!b_bot || get_last_node(*a)->data > get_last_node(*b)->data))
		{
			rra(a);
			a_bot -= pb(a, b);
		}
		else if (b_bot && (!a_top || get_last_node(*b)->data > (*a)->data)
			&& (!a_bot || get_last_node(*b)->data > get_last_node(*a)->data))
			b_bot -= rrb(b);
	}
}

void	merge_descending_a_to_b(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_top;
	int	a_bot;
	int	b_bot;

	a_top = get_size(info.pow, info.pow / 3 + i, info.n);
	a_bot = get_size(info.pow, info.pow / 3 - 1 - i, info.n);
	b_bot = get_size(info.pow, info.pow * 2 / 3 + i, info.n);
	while (a_top + a_bot + b_bot)
	{
		if (a_top && (!a_bot || (*a)->data < get_last_node(*a)->data)
			&& (!b_bot || (*a)->data < get_last_node(*b)->data))
			a_top -= pb(a, b);
		else if (a_bot && (!a_top || get_last_node(*a)->data < (*a)->data)
			&& (!b_bot || get_last_node(*a)->data < get_last_node(*b)->data))
		{
			rra(a);
			a_bot -= pb(a, b);
		}
		else if (b_bot && (!a_top || get_last_node(*b)->data < (*a)->data)
			&& (!a_bot || get_last_node(*b)->data < get_last_node(*a)->data))
			b_bot -= rrb(b);
	}
}

void	merge_ascending_b_to_a(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_bot;
	int	b_top;
	int	b_bot;

	b_top = get_size(info.pow, info.pow / 3 + i, info.n);
	b_bot = get_size(info.pow, info.pow / 3 - 1 - i, info.n);
	a_bot = get_size(info.pow, info.pow * 2 / 3 + i, info.n);
	while (a_bot + b_top + b_bot)
	{
		if (b_top && (!b_bot || (*b)->data > get_last_node(*b)->data)
			&& (!a_bot || (*b)->data > get_last_node(*a)->data))
			b_top -= pa(a, b);
		else if (b_bot && (!b_top || get_last_node(*b)->data > (*b)->data)
			&& (!a_bot || get_last_node(*b)->data > get_last_node(*a)->data))
		{
			rrb(b);
			b_bot -= pa(a, b);
		}
		else if (a_bot && (!b_top || get_last_node(*a)->data > (*b)->data)
			&& (!b_bot || get_last_node(*a)->data > get_last_node(*b)->data))
			a_bot -= rra(a);
	}
}

void	merge_descending_b_to_a(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_bot;
	int	b_top;
	int	b_bot;

	b_top = get_size(info.pow, info.pow / 3 + i, info.n);
	b_bot = get_size(info.pow, info.pow / 3 - 1 - i, info.n);
	a_bot = get_size(info.pow, info.pow * 2 / 3 + i, info.n);
	while (a_bot + b_top + b_bot)
	{
		if (b_top && (!b_bot || (*b)->data < get_last_node(*b)->data)
			&& (!a_bot || (*b)->data < get_last_node(*a)->data))
			b_top -= pa(a, b);
		else if (b_bot && (!b_top || get_last_node(*b)->data < (*b)->data)
			&& (!a_bot || get_last_node(*b)->data < get_last_node(*a)->data))
		{
			rrb(b);
			b_bot -= pa(a, b);
		}
		else if (a_bot && (!b_top || get_last_node(*a)->data < (*b)->data)
			&& (!b_bot || get_last_node(*a)->data < get_last_node(*b)->data))
			a_bot -= rra(a);
	}
}

int	get_ascending(int pow, int i)
{
	int	ret;

	ret = 1;
	while (pow > 1)
	{
		if (i < pow * 2 / 3)
		{
			i = (pow / 3 - 1) - (i % (pow / 3));
			ret = !ret;
		}
		else
			i = i - pow * 2 / 3;
		pow /= 3;
	}

	return (ret);
}

int	get_y(int x, int pow)
{
	int	root;
	int	range;
	int	cnt;

	root = (pow - 1) / 2;
	range = pow / 3;
	cnt = 0;
	while (pow > 3)
	{
		if (x <= range)
			range -= pow / 9 * 2;
		else if (x <= range + pow / 3)
		{
			if (cnt % 2 == 0)
				root += pow / 3;
			else 
				root -= pow / 3;
			range += pow / 3 / 3;
		}
		else
		{
			if (cnt % 2 == 0)
				root -= pow / 3;
			else
				root += pow / 3;
			range += pow / 3 + pow / 3 / 3;
			cnt++;
		}
		pow /= 3;
		cnt++;
	}
	if (cnt % 2 == 0)
	{
		if (x % 3 == 2)
			root++;
		else if (x % 3 == 0)
			root--;
	}
	else
	{
		if (x % 3 == 2)
			root--;
		else if (x % 3 == 0)
			root++;
	}

	return (root);
}

int	get_size(int pow, int i, int n)
{
	int	x;
	int	y;
	int	ret;

	x = n % pow;
	ret = n / pow;
	while (x)
	{
		y = get_y(x, pow);	
		if (i == y)
			return (ret + 1);
		x--;
	}
	
	return (ret);
}

void	division(t_stack **a, t_stack **b, t_info info)
{
	int	i;

	if (info.depth % 2 == 0)
	{
		i = 0;
		while (i < info.pow)
		{
			make_triangle_a(a, b, get_size(info.pow, info.pow - 1 - i, info.n), get_ascending(info.pow, i));
			i++;
		}
	}
	else
	{
		i = info.pow;
		while (i--)
			make_triangle_b(a, b, get_size(info.pow, info.pow - 1 - i, info.n), get_ascending(info.pow, i));
	}
}

void	merge_a_to_b(t_stack **a, t_stack **b, t_info info, int size)
{
	int	i;

	while (size--)
		pb(a, b);
	i = info.pow / 3;
	while (i--)
	{
		if (get_ascending(info.pow / 3, i))
			merge_ascending_a_to_b(a, b, info, i);
		else
			merge_descending_a_to_b(a, b, info, i);
	}
}

void	merge_b_to_a(t_stack **a, t_stack **b, t_info info, int size)
{
	int	i;

	while (size--)
		pa(a, b);
	i = info.pow / 3;
	while (i--)
	{
		if (get_ascending(info.pow / 3, i))
			merge_ascending_b_to_a(a, b, info, i);
		else
			merge_descending_b_to_a(a, b, info, i);
	}
}

void	merge(t_stack **a, t_stack **b, t_info info)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (i < info.pow / 3)
		size += get_size(info.pow, info.pow * 2 / 3 + i++, info.n);
	if (info.depth % 2 == 0)
		merge_a_to_b(a, b, info, size);
	else
		merge_b_to_a(a, b, info, size);
	if (info.depth > 1)
	{
		info.depth--;
		info.pow /= 3;
		merge(a, b, info);
	}
}

void	merge_sort(t_stack **a, t_stack **b)
{
	t_info	info;

	info.n = get_list_length(*a);
	info.depth = get_depth(*a, info.n);
	info.pow = ft_pow(3, info.depth);
	division(a, b, info);
	merge(a, b, info);
}
