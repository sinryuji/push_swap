/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:00:53 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/02 18:41:16 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sort(t_stack *top)
{
	while (top && top->next)
	{
		if (top->data > top->next->data)
			return (0);
		top = top->next;
	}	
	return (1);
}

int	check_decending_sort(t_stack *top)
{
	while (top && top->next)
	{
		if (top->data < top->next->data)
			return (0);
		top = top->next;
	}	
	return (1);
}

t_stack	*get_min_node(t_stack *top)
{
	t_stack	*min;

	min = top;
	while (top)
	{
		if (min->data > top->data)
			min = top;	
		top = top->next;
	}

	return (min);
}

t_stack	*get_max_node(t_stack *top)
{
	t_stack	*max;

	max = top;
	while (top)
	{
		if (max->data < top->data)
			max = top;	
		top = top->next;
	}

	return (max);
}
