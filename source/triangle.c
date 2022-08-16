/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:48:11 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/16 16:48:44 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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