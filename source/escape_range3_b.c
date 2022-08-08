/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_range3_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:55:08 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/08 19:17:33 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	escape_b_012(t_stack **a, t_stack **b)
{
	if (get_list_length(*b) == 3)
	{
		rb(b);
		sb(b);
		pa(a, b);
		pa(a, b);
		pa(a, b);
		return ;
	}
	rb(b);
	sb(b);
	pa(a, b);
	pa(a, b);
	rrb(b);
	pa(a, b);
}

void	escape_b_021(t_stack **a, t_stack **b)
{
	sb(b);
	pa(a, b);
	sb(b);
	pa(a, b);
	pa(a, b);
}

void	escape_b_102(t_stack **a, t_stack **b)
{
	if (get_list_length(*b) == 3)
	{
		rrb(b);
		pa(a, b);
		pa(a, b);
		pa(a, b);
		return ;
	}
	rb(b);
	sb(b);
	pa(a, b);
	rrb(b);
	pa(a, b);
	pa(a, b);
}

void	escape_b_120(t_stack **a, t_stack **b)
{
	sb(b);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}

void	escape_b_201(t_stack **a, t_stack **b)
{
	pa(a, b);
	sb(b);
	pa(a, b);
	pa(a, b);
}
