/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:29:05 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/15 17:38:04 by hyeongki         ###   ########.fr       */
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

int	ascending_triangle_a(t_stack **a, t_stack **b, int n)
{
	int	arr[3];

	arr[0] = (*a)->data;	
	arr[1] = (*a)->next->data;	
	arr[2] = (*a)->next->next->data;

	if (arr[0] < arr[2] && arr[2] < arr[1])
		return (ra(a) && sa(a) && ra(a) && ra(a));
	if (arr[1] < arr[0] && arr[0] < arr[2])
		return (sa(a) && ra(a) && ra(a) && ra(a));
	if (arr[2] < arr[0] && arr[0] < arr[1])
		return (pb(a, b) && sa(a) && ra(a) && pa(a, b) && ra(a) && ra(a));
	if (arr[2] < arr[1] && arr[1] < arr[0])
		return (pb(a, b) && sa(a) && ra(a) && ra(a) && pa(a, b) && ra(a));
	if (arr[1] < arr[2] && arr[2] < arr[0])
		return (pb(a, b) && ra(a) && ra(a) && pa(a, b) && ra(a));
	return (ra(a) && ra(a) && ra(a));
}

int	descending_triangle_a(t_stack **a, t_stack **b, int n)
{
	int	arr[3];

	arr[0] = (*a)->data;	
	arr[1] = (*a)->next->data;	
	arr[2] = (*a)->next->next->data;

	if (arr[0] < arr[1] && arr[1] < arr[2])
		return (pb(a, b) && sa(a) && ra(a) && ra(a) && pa(a, b) && ra(a));
	if (arr[0] < arr[2] && arr[2] < arr[1])
		return (pb(a, b) && ra(a) && ra(a) && pa(a, b) && ra(a));
	if (arr[1] < arr[0] && arr[0] < arr[2])
		return (pb(a, b) && sa(a) && ra(a) && pa(a, b) && ra(a) && ra(a));
	if (arr[2] < arr[0] && arr[0] < arr[1])
		return (sa(a) && ra(a) && ra(a) && ra(a));
	if (arr[1] < arr[2] && arr[2] < arr[0])
		return (ra(a) && sa(a) && ra(a) && ra(a));
	return (ra(a) && ra(a) && ra(a));
}

int	ascending_triangle_b(t_stack **a, t_stack **b, int n)
{
	int	arr[3];

	arr[0] = (*a)->data;	
	arr[1] = (*a)->next->data;	
	arr[2] = (*a)->next->next->data;

	if (arr[0] < arr[1] && arr[1] < arr[2])
		return (pb(a, b) && sa(a) && pb(a, b) && sb(b) && pb(a, b) && sb(b));
	if (arr[0] < arr[2] && arr[2] < arr[1])
		return (sa(a) && pb(a, b) && sa(a) && pb(a, b) && pb(a, b));
	if (arr[1] < arr[0] && arr[0] < arr[2])
		return (pb(a, b) && sa(a) && pb(a, b) && sb(b) && pb(a, b));
	if (arr[2] < arr[0] && arr[0] < arr[1])
		return (sa(a) && pb(a, b) && pb(a, b) && pb(a, b));
	if (arr[1] < arr[2] && arr[2] < arr[0])
		return (pb(a, b) && sa(a) && pb(a, b) && pb(a, b));
	return (pb(a, b) && pb(a, b) && pb(a, b)); 
}

int	descending_triangle_b(t_stack **a, t_stack **b, int n)
{
	int	arr[3];

	arr[0] = (*a)->data;	
	arr[1] = (*a)->next->data;	
	arr[2] = (*a)->next->next->data;

	if (arr[0] < arr[2] && arr[2] < arr[1])
		return (pb(a, b) && sa(a) && pb(a, b) && pb(a, b));
	if (arr[1] < arr[0] && arr[0] < arr[2])
		return (sa(a) && pb(a, b) && pb(a, b) && pb(a, b));
	if (arr[2] < arr[0] && arr[0] < arr[1])
		return (pb(a, b) && sa(a) && pb(a, b) && sb(b) && pb(a, b));
	if (arr[2] < arr[1] && arr[1] < arr[0])
		return (pb(a, b) && sa(a) && pb(a, b) && sb(b) && pb(a, b) && sb(b));
	if (arr[1] < arr[2] && arr[2] < arr[0])
		return (sa(a) && pb(a, b) && sa(a) && pb(a, b) && pb(a, b));
	return (pb(a, b) && pb(a, b) && pb(a, b)); 
}

void	make_triangle(t_stack **a, t_stack **b, int depth, int n, int ascending)
{
	int	(*ascending_triangle)(t_stack **, t_stack **, int);
	int	(*descending_triangle)(t_stack **, t_stack **, int);

	if (depth % 2 == 0)
	{
		ascending_triangle = ascending_triangle_a;
		descending_triangle = descending_triangle_a;
	}
	else
	{
		ascending_triangle = ascending_triangle_b;
		descending_triangle = descending_triangle_b;
	}
	if (ascending)
	{
		ascending_triangle(a, b, n);
		descending_triangle(a, b, n);
		descending_triangle(a, b, n);
	}
	else
	{
		descending_triangle(a, b, n);
		ascending_triangle(a, b, n);
		ascending_triangle(a, b, n);
	}
}

void	division(t_stack **a, t_stack **b, int depth, int n, int ascending)
{
	int	d;

	if (depth > 0)
	{
		if	(ascending)
		{
			division(a, b, depth - 1, n, 1);
			division(a, b, depth - 1, n, 0);
			division(a, b, depth - 1, n, 0);
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
		make_triangle(a, b, d, n, ascending);
	}
}

void	merge_sort(t_stack **a, t_stack **b)
{
	int	n;
	int	depth;

	n = get_list_length(*a);
	depth = get_depth(*a, n);
	division(a, b, depth, n, 1);
//	merge();
}
