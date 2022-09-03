/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:29:05 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/02 21:11:14 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_depth(t_stack *a, int n)
{
	int	depth;

	depth = 0;
	while (n > 3)
	{
		n = n / 3 + n % 3;
		depth++;
	}

	return (depth);
}

void	merge_ascending_a_to_b(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_top;
	int	a_bot;
	int	b_bot;

	a_top = get_size(info.pow, info.pow / 3 * 2 - i - 1, info.n);
	a_bot = get_size(info.pow, info.pow / 3 * 2 + i, info.n);
	b_bot = get_size(info.pow, info.pow / 3 - i - 1, info.n);
//	ft_printf("a_top : %d\n", a_top);
//	ft_printf("a_bot : %d\n", a_bot);
//	ft_printf("b_bot : %d\n", b_bot);
//	print_state(*a, *b);
	ft_printf("sum : %d\n", a_top + a_bot + b_bot);
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
//		ft_printf("sum : %d\n", a_top + a_bot + b_bot);
	}
}

void	merge_descending_a_to_b(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_top;
	int	a_bot;
	int	b_bot;

	a_top = get_size(info.pow, info.pow / 3 * 2 - i - 1, info.n);
	a_bot = get_size(info.pow, info.pow / 3 * 2 + i, info.n);
	b_bot = get_size(info.pow, info.pow / 3 - i - 1, info.n);
//	ft_printf("a_top : %d\n", a_top);
//	ft_printf("a_bot : %d\n", a_bot);
//	ft_printf("b_bot : %d\n", b_bot);
//	print_state(*a, *b);
	ft_printf("sum : %d\n", a_top + a_bot + b_bot);
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
//		ft_printf("sum : %d\n", a_top + a_bot + b_bot);
	}
}

void	merge_ascending_b_to_a(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_bot;
	int	b_top;
	int	b_bot;

	a_bot = get_size(info.pow, info.pow / 3 - i - 1, info.n);
	b_top = get_size(info.pow, info.pow / 3 * 2 - i - 1, info.n);
	b_bot = get_size(info.pow, info.pow / 3 * 2 + i, info.n);
//	ft_printf("a_bot : %d\n", a_bot);
//	ft_printf("b_top : %d\n", b_top);
//	ft_printf("b_bot : %d\n", b_bot);
	ft_printf("sum : %d\n", a_bot + b_top + b_bot);
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

	a_bot = get_size(info.pow, info.pow / 3 - i - 1, info.n);
	b_top = get_size(info.pow, info.pow / 3 * 2 - i - 1, info.n);
	b_bot = get_size(info.pow, info.pow / 3 * 2 + i, info.n);
//	ft_printf("a_bot : %d\n", a_bot);
//	ft_printf("b_top : %d\n", b_top);
//	ft_printf("b_bot : %d\n", b_bot);
	ft_printf("sum : %d\n", a_bot + b_top + b_bot);
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

//int	get_ascending(t_stack *top)
//{
//	if (!top)
//		return (0);
//	if(top->data > top->next->data)
//		return (1);
//	return (0);
//}

//void	merge_a_to_b(t_stack **a, t_stack **b, int depth, int n)
//{
//	int	i;
//	int	ascending;
//	t_size	ts;
//	int	size;
//	int	tmp;
//
//	i = n / 3;
//	size = n;
//	tmp = depth;
//	while (tmp--)
//		size /= 3;
//	while (i--)
//		pb(a, b);
////	ascending = get_ascending(*a);
//	i = 1;
//	while (--depth)
//		i *= 3;
//	while (i--)
//	{
//		ts.a_top = size;
//		ts.a_bot = size;
//		ts.b_bot = size;
//		if (ascending)
//			merge_ascending_a_to_b(a, b, ts);
//		else
//			merge_descending_a_to_b(a, b, ts);
////		ascending = get_ascending(*a);
//	}
//}
//
//void	merge_b_to_a(t_stack **a, t_stack **b, int depth, int n)
//{
//	int	i;
//	int	ascending;
//	t_size	ts;
//	int	size;
//	int	tmp;
//
//	i = n / 3;
//	size = n;
//	tmp = depth;
//	while (i--)
//		pa(a, b);
//	while (tmp--)
//		size /= 3;
////	ascending = get_ascending(*b);
//	i = 1;
//	while (--depth)
//		i *= 3;
//	while (i--)
//	{
//		ts.a_bot = size;
//		ts.b_top = size;
//		ts.b_bot = size;
//		if (ascending)
//			merge_ascending_b_to_a(a, b, ts);
//		else
//			merge_descending_b_to_a(a, b, ts);
////		ascending = get_ascending(*b);
//	}
//}

//void	merge(t_stack **a, t_stack **b, int depth, int n)
//{
//	if (depth % 2 == 0)
//		merge_a_to_b(a, b, depth, n);
//	else
//		merge_b_to_a(a, b, depth, n);
//	if (depth > 1)
//		merge(a, b, depth - 1, n);
//}

//void	make_triangle(t_fc **fc, t_info info, int ascending)
//{
//	t_fc	*new;
//
//	new = (t_fc *)malloc(sizeof(t_fc));
//	if (info.depth % 2 == 0)
//	{
//		if (ascending)
//			new->make_triangle = ascending_triangle_a;
//		else
//			new->make_triangle = descending_triangle_a;
//	}
//	else
//	{
//		if (ascending)
//			new->make_triangle = ascending_triangle_b;
//		else
//			new->make_triangle = descending_triangle_b;
//	}
//	new->next = *fc;
//	new->prev = NULL;
//	if (*fc)
//		(*fc)->prev = new;
//	*fc = new;
//}

//void	division(t_stacks stacks, t_fc **fc, t_info info, int ascending)
//{
//	if (info.depth > 0)
//	{
//		info.depth--;
//		if	(ascending)
//		{
//			division(stacks, fc, info, 0);
//			division(stacks, fc, info, 0);
//			division(stacks, fc, info, 1);
//		}
//		else
//		{
//			division(stacks, fc, info, 0);
//			division(stacks, fc, info, 1);
//			division(stacks, fc, info, 1);
//		}
//	}
//	else
//	{
//		info.depth = get_depth(*(stacks.a), info.n);
//		info.n--;
//		make_triangle(fc, info, ascending);
//	}
//
//}

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
			range /= 3;
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

//int	get_size(int pow, int i, int n)
//{
//	int	x;
//	int	y;
//	int	ret;
//
//	x = n % pow;
//	ret = n / pow;
//	while (x)
//	{
//		y = get_y(x, pow);	
//		if (i == y)
//			return (ret + 1);
//		x--;
//	}
//	
//	return (ret);
//}

int	get_size(int pow, int i, int n)
{
	size_t	tmp;

	if (pow == 1)
		return (n);
	else if (i < pow / 3)
	{
		tmp = get_size(pow / 3, i, n);
		return (tmp / 3);
	}
	else if (i < 2 * pow / 3)
	{
		tmp = get_size(pow / 3, 2 * pow / 3 - 1 - i, n);
		return (tmp / 3 + (tmp % 3 > 0));
	}
	else
	{
		tmp = get_size(pow / 3, pow - 1 - i, n);
		return (tmp / 3 + (tmp % 3 > 1));
	}
}

void	divi(t_stack **a, t_stack **b, t_info info)
{
	int	i;

	if (info.depth % 2 == 0)
	{
		i = 0;
		while (i < info.pow)
		{
			make_triangle_a(a, b, get_size(info.pow, i, info.n), get_ascending(info.pow, i));
			i++;
		}
	}
	else
	{
		i = info.pow;
		while (i--)
		{
			make_triangle_b(a, b, get_size(info.pow, i, info.n), get_ascending(info.pow, i));
		}
	}
}

void	mer_a_to_b(t_stack **a, t_stack **b, t_info info)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (i < info.pow / 3)
		size += get_size(info.pow, i++, info.n);
	while (size--)
		pb(a, b);
	while (i--)
	{
		if (get_ascending(info.pow / 3, i))
			merge_ascending_a_to_b(a, b, info, i);
		else
			merge_descending_a_to_b(a, b, info, i);
	}
}

void	mer_b_to_a(t_stack **a, t_stack **b, t_info info)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (i < info.pow / 3)
		size += get_size(info.pow, i++, info.n);
	while (size--)
		pa(a, b);
	while (i--)
	{
		if (get_ascending(info.pow / 3, i))
			merge_ascending_b_to_a(a, b, info, i);
		else
			merge_descending_b_to_a(a, b, info, i);
	}
}

void	mer(t_stack **a, t_stack **b, t_info info)
{
	static int	cnt = 0;

	if (info.depth % 2 == 0)
		mer_a_to_b(a, b, info);
	else
		mer_b_to_a(a, b, info);
	print_state(*a, *b);
	cnt++;
//	if (cnt == 2)
//		return ;
	if (info.depth > 1)
	{
		info.depth--;
		info.pow /= 3;
		mer(a, b, info);
	}
}

void	merge_sort(t_stack **a, t_stack **b)
{
	t_fc	*fc;
	t_info	info;
	t_stacks	stacks;
	t_fc	*tmp;

	fc = NULL;
	stacks.a = a;
	stacks.b = b;
	info.n = get_list_length(*a);
	info.depth = get_depth(*a, info.n);
	info.pow = ft_pow(3, info.depth);
//	division(stacks, &fc, info, 1);
//	do_division(stacks, fc, info);
//	while (fc)
//	{
//		tmp = fc;
//		fc = tmp->next;
//		free(tmp);
//	}
//	merge(a, b, info.depth, info.n);
	divi(a, b, info);
	print_state(*a, *b);
//	return ;
	mer(a, b, info);
	// 실제로 정렬되는 방향이랑 get으로 계산하는 것의 차이를 잘 살펴보자
}
