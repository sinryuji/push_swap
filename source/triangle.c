/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:48:11 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/29 18:09:36 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	make_triangle_a(t_stack **a, t_stack **b, int size, int ascending)
{
	if (size == 1)
		return (ra(a));
	else if (size == 2)
	{
		if (((*a)->data > (*a)->next->data) == ascending)
			sa(a);
		return (ra(a) && ra(a));
	}
	else
	{
		if (ascending)
			return (ascending_triangle_a(a, b));
		else
			return (descending_triangle_a(a, b));
	}
}

int	ascending_triangle_a(t_stack **a, t_stack **b)
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

int	descending_triangle_a(t_stack **a, t_stack **b)
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

int	make_triangle_b(t_stack **a, t_stack **b, int size, int ascending)
{
	if (size == 1)
		return (pb(a, b));
	else if (size == 2)
	{
		if (((*a)->data > (*a)->next->data) != ascending)
			sa(a);
		return (pb(a, b) && pb(a, b));
	}
	else
	{
		if (ascending)
			return (ascending_triangle_b(a, b));
		else
			return (descending_triangle_b(a, b));
	}
}

int	ascending_triangle_b(t_stack **a, t_stack **b)
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

int	descending_triangle_b(t_stack **a, t_stack **b)
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
